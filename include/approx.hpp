//
// Created by pusana on 7/3/26.
//

#pragma once

#include <cmath>
#include <vector>
#include <stdexcept>
#include <string>


namespace approx {

    enum class Function {
        Sin,
        Cos,
    };


    enum class Method {
        Reference,
        Taylor,
        Minimax,
        Cordic,

    };


    struct Samples {
        std::vector<long double> x;
        std::vector<long double> y;

    };


    using FuncPtr = long double (*)(long double);

    inline FuncPtr resolve_function(Function func_enum) {
        switch (func_enum) {
            case (Function::Sin): return static_cast<FuncPtr>(&std::sin);
            case (Function::Cos): return static_cast<FuncPtr>(&std::cos);
        }

        throw::std::invalid_argument("invalid function enum");

    }


    void generate_reference_data(Function func,
                                 long double x_max,
                                 int sample_count);


    void generate_taylor_data(Function func,
                         long double x_max,
                         int sample_count,
                         int term_count);


}
