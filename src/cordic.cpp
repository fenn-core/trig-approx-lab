//
// Created by pusana on 7/5/26.
//

#include <cstdint>
#include "approx.hpp"


namespace approx {

    struct FixedPointSamples {
        std::vector<std::int16_t> x;
        std::vector<std::int16_t> y;

    };


    FixedPointSamples cordic(Function func,
                   long double x_max,
                   int sample_count,
                   int interations) {

        std::int16_t inverse_gain[8] = {};

        std::int16_t x = ;  // Q2.14
        std::int16_t y = ;

        std:: int16_t z = ;  // error accumulator



    }




}