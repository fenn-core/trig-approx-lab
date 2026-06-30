//
// Created by pusana on 6/30/26.
//

#pragma once


enum class TrigFunction {
    Sin,
    Cos,
};


void generate_reference_csv(TrigFunction func, long double x_max, int samples) ;


