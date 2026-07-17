//
// Created by pusana on 7/16/26.
//

#include <cmath>
#include <span>
#include <stdexcept>
#include "approx.hpp"


namespace approx {

    namespace {

        #include "generated/sin_quarter_luts.inc"

    }


    long double lerp_lut_data(long double alpha,
        std::span<const long double> lut) {

        auto lut_elements = lut.size();

        if (alpha >= pi / 2) {
            return lut[(lut_elements - 1)];
        }

        auto interval = pi / (2 * (lut_elements - 1));
        int low_index = floor(alpha / (interval));

        const long double t =
            (alpha - interval * low_index) / interval;

        const long double value =
            std::lerp(lut[low_index], lut[low_index + 1], t);

        return value;


    }


    Samples generate_lut_linear_samples(Function func,
                                        long double x_max,
                                        int sample_count,
                                        int lut_intervals) {

        std::span<const long double> lut;

        switch (lut_intervals) {
            case (8): lut = sin_quarter_lut_8; break;
            case (16): lut = sin_quarter_lut_16; break;
            case (32): lut = sin_quarter_lut_32; break;
            case (64): lut = sin_quarter_lut_64; break;

            default:
                throw std::logic_error("invalid LUT interval value");
        }

        auto interval = pi / (2 * lut_intervals);

        Samples samples;
        samples.x.resize(sample_count);
        samples.y.resize(sample_count);

        long double step = (2 * x_max) / (sample_count - 1);
        int sign = 1;

        for (int i = 0; i < sample_count; ++i) {
            long double x = -x_max + i * step;
            auto original_x = x;

            if (func == Function::Cos) {
                x += pi / 2.0L;
            }

            while (x >= 2.0L * pi) {
                x -= 2 * pi;
            }

            while (x < 0.0L) {
                x += 2.0L * pi;
            }

            const int quadrant = static_cast<int>(x / (pi / 2.0L));
            const long double alpha = x - (quadrant * pi / 2.0L);

            switch (quadrant) {
                case (0):
                case (1): sign = 1; break;
                case (2):
                case (3): sign = -1; break;

                default:
                    throw std::logic_error("invalid quadrant value");
            }

            auto lookup_angle = alpha;
            if (quadrant == 1 || quadrant == 3) {
                lookup_angle = pi / 2.0L - alpha;
            }

            samples.x[i] = original_x;
            samples.y[i] = sign * lerp_lut_data(lookup_angle, lut);

        }

        return samples;


        }


}

