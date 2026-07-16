//
// Created by pusana on 7/5/26.
//

#pragma once

#include <cstdint>
#include "approx.hpp"


namespace approx {

    Samples generate_cordic_samples(Function func,
                   long double x_max,
                   std::uint16_t sample_count,
                   std::uint8_t iterations);

}
