#include <numbers>
#include "approx.hpp"


int main() {

    using namespace approx;

    generate_reference_data(Function::Sin,
        pi, 1000);

    generate_reference_data(Function::Cos,
    pi, 1000);

    generate_taylor_data(Function::Sin,
        pi, 1000, 3);

    generate_taylor_data(Function::Cos,
        pi, 1000, 3);

    generate_cordic_data(Function::Sin,
        pi, 1000, 8);

    generate_cordic_data(Function::Cos,
    pi, 1000, 8);

    generate_lut_linear_data(Function::Sin,
        pi, 1000, 8);

    generate_lut_linear_data(Function::Cos,
        pi, 1000, 8);



    return 0;

}
