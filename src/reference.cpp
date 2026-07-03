//
// Created by pusana on 6/30/26.
//

#include "reference.hpp"


namespace approx {

    Samples generate_reference_samples(Function func,
                                       long double x_max,
                                       int sample_count) {
        Samples samples;
        long double x;
        const auto target_func = resolve_function(func);

        samples.x.resize(sample_count);
        samples.y.resize(sample_count);

        long double step = (2 * x_max) / (sample_count - 1);

        for (int i = 0; i < sample_count; ++i) {
            x = -x_max + i * step;
            samples.x[i] = x;
            samples.y[i] = target_func(x);
        }

        return samples;

    }



}