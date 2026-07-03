//
// Created by pusana on 6/30/26.
//

#include "taylor.hpp"
#include "approx.hpp"


namespace approx {

    Samples sin_taylor(long double x_max,
                       int sample_count,
                       int term_count) {

        Samples samples;

        samples.x.resize(sample_count);
        samples.y.resize(sample_count);

        long double step = (2 * x_max) / (sample_count - 1);

        for (int i = 0; i < sample_count; ++i) {
            long double x = -x_max + i * step;
            samples.x[i] = x;

            long double term = x;
            long double sum = term;

            for (int k = 0; k < term_count - 1; ++k) {
                term *= (-x * x) / ((2*k + 2) * (2*k + 3));
                sum += term;
            }

            samples.y[i] = sum;

        }

        return samples;

    }


    Samples cos_taylor(long double x_max,
                       int sample_count,
                       int term_count) {

        Samples samples;

        samples.x.resize(sample_count);
        samples.y.resize(sample_count);

        long double step = (2 * x_max) / (sample_count - 1);

        for (int i = 0; i < sample_count; ++i) {
            long double term = 1.0;
            long double sum = term;

            long double x = -x_max + i * step;
            samples.x[i] = x;

            for (int k = 0; k < term_count - 1; ++k) {
                    term *= (-x * x) / ((2*k + 1) * (2*k + 2));
                    sum += term;
            }

            samples.y[i] = sum;

        }

        return samples;


    }


    Samples generate_taylor_samples(Function func,
                                    long double x_max,
                                    int sample_count,
                                    int term_count) {
        Samples samples;

        switch (func) {
            case (Function::Sin):
                samples =
                    sin_taylor(x_max, sample_count, term_count);
                break;

            case (Function::Cos):
                samples =
                    cos_taylor(x_max, sample_count, term_count);
                break;
        }

        return samples;

    }


}
