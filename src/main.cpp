#include <numbers>
#include "approx.hpp"


int main() {

    using namespace approx;

    generate_reference_data(Function::Sin,
        std::numbers::pi_v<long double>, 1000);

    generate_taylor_data(Function::Sin,
        std::numbers::pi_v<long double>, 1000, 3);

    generate_taylor_data(Function::Cos,
    std::numbers::pi_v<long double>, 1000, 3);


    return 0;

}
