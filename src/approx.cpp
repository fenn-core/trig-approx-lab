//
// Created by pusana on 7/3/26.
//

#include <iostream>
#include "approx.hpp"
#include "csv.hpp"
#include "reference.hpp"
#include "taylor.hpp"

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

}
