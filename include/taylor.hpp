//
// Created by pusana on 6/30/26.
//

#pragma once

#include "approx.hpp"


namespace approx {

    Samples generate_taylor_samples(Function func,
                                    long double x_max,
                                    int sample_count,
                                    int term_count);

}