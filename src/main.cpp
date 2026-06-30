#include <iostream>
#include <cmath>
#include <numbers>
#include <fstream>


int main() {

    long double pi = std::numbers::pi_v<long double>;

    std::ofstream csv_file("../data/sin.csv");

    if (!csv_file.is_open()) {
        std::cout << "error, couldn't open file" << std::endl;
        return 1;
    }

    float x;
    for (int i = -1000; i < 1000; ++i) {
        x = pi * i / 1000.0;
        csv_file << x << "," << std::sin(x) << "\n" ;

    }

    csv_file.close();

    std::cout << "successfully written to file" << std::endl;


    return 0;

}
