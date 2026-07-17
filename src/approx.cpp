//
// Created by pusana on 7/3/26.
//

#include <cstdint>
#include "approx.hpp"
#include "csv.hpp"
#include "reference.hpp"
#include "taylor.hpp"
#include "cordic.hpp"
#include "lut_linear.hpp"


namespace approx {

    void generate_reference_data(Function func,
                                 long double x_max,
                                 int sample_count) {

        Samples samples =
            generate_reference_samples(func, x_max, sample_count);

        write_csv(func, Method::Reference, samples);

    }


    void generate_taylor_data(Function func,
                             long double x_max,
                             int sample_count,
                             int term_count) {

        Samples samples =
            generate_taylor_samples(func, x_max, sample_count, term_count);

        write_csv(func, Method::Taylor, samples);

    }

    void generate_cordic_data(Function func,
                              long double x_max,
                              std::uint16_t sample_count,
                              std::uint8_t iterations) {

        Samples samples =
            generate_cordic_samples(func, x_max, sample_count, iterations);

        write_csv(func, Method::Cordic, samples);

    }

    void generate_lut_linear_data(Function func,
                                  long double x_max,
                                  int sample_count,
                                  int lut_intervals) {

        Samples samples =
            generate_lut_linear_samples(func,
                                        x_max,
                                        sample_count,
                                        lut_intervals);

        write_csv(func, Method::LutLinear, samples);

    }



}
