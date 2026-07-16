//
// Created by pusana on 7/5/26.
//

#include <cstdint>
#include <stdexcept>
#include "approx.hpp"


namespace approx {

    std::int16_t cordic(
        Function func,
        std::int64_t reduced_angle,
        std::uint8_t iterations
    ) {

        constexpr std::int16_t atan_lut[8] =
        {8192, 4836, 2555, 1297, 651, 326, 163, 81};

        constexpr std::int16_t inverse_gain_q2_14[8] =
        {11585, 10362, 10053, 9975, 9956, 9951, 9950, 9949};

        std::int16_t x = inverse_gain_q2_14[iterations - 1];
        std::int16_t y = 0;
        std::int64_t z = reduced_angle;

        for (std::uint8_t i = 0; i < iterations; ++i) {
            auto x_old = x;
            auto y_old = y;

            std::int8_t d = (z >= 0) ? 1 : -1;

            x = x_old - d * (y_old >> i);
            y = y_old + d * (x_old >> i);
            z -= d * atan_lut[i];

        }

        switch (func) {
            case Function::Cos: return x;
            case Function::Sin: return y;
        }

    }


    Samples generate_cordic_samples(Function func,
                   long double x_max,
                   std::uint16_t sample_count,
                   std::uint8_t iterations) {

        if ((iterations > 8) || (1 > iterations)) {
            throw std::out_of_range("cordic iterations must be in [1, 8]");
        }

        Samples samples;
        samples.x.resize(sample_count);
        samples.y.resize(sample_count);

        const auto raw_x_max = static_cast<std::int64_t>(
                std::llround(
                    x_max * 32768L /
                    std::numbers::pi_v<long double>
                    )
                );

        const std::int64_t interval_count = sample_count - 1;

        const std::int64_t raw_span = 2 * raw_x_max;  // range is defined as [-x_max, x_max]

        for (uint16_t i = 0; i < sample_count; ++i) {
            // compute the index only using integer arithmetic,
            // then wrap and range reduce

            const std::int64_t offset =
                (raw_span * i + interval_count / 2) / interval_count;

            std::int64_t raw_angle =
                -raw_x_max + offset;

            while (raw_angle >= 32768)
                raw_angle -= 65536;

            while (raw_angle < -32768)
                raw_angle += 65536;

            bool negate_cosine = false;

            if (raw_angle > 16384) {
                raw_angle = 32768 - raw_angle;
                negate_cosine = true;
            }
            else if (raw_angle < -16384) {
                raw_angle = -32768 - raw_angle;
                negate_cosine = true;
            }

            std::int16_t raw_value = cordic(func, raw_angle, iterations);

            samples.x[i] =
                (raw_angle * std::numbers::pi_v<long double> / 32768.0);
            samples.y[i] = (raw_value / 16384.0);

        }

        return samples;

    }


}
