//
// Created by pusana on 7/16/26.
//

#pragma once

#include "approx.hpp"


namespace approx {

    Samples generate_lut_linear_samples(Function func,
                                        long double x_max,
                                        int sample_count,
                                        int lut_intervals);


}