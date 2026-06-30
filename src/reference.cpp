//
// Created by pusana on 6/30/26.
//


#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <filesystem>
#include "reference.hpp"


void generate_reference_csv(TrigFunction func, long double x_max, int samples) {
    std::string rel_path;
    long double (*trig)(long double);

    switch (func) {
        case (TrigFunction::Sin):
            rel_path = "../data/sin_reference.csv";
            trig = static_cast<long double (*)(long double)>(std::sinl);
            break;

        case (TrigFunction::Cos):
            rel_path = "../data/cos_reference.csv";
            trig = static_cast<long double (*)(long double)>(std::cosl);
            break;

        default:
            std::cout<< "error, invalid function" <<std::endl;
            return;

    }


    std::filesystem::path abs_path = std::filesystem::absolute(rel_path);

    std::ofstream csv_file(abs_path);
    csv_file << std::fixed << std::setprecision(15);

    if (!csv_file.is_open()) {
        std::cout << "error, couldn't open file" << std::endl;
        return;
    }


    long double step = (2 * x_max) / (samples - 1);
    for (int i = 0; i < samples; ++i) {
        long double x = -x_max + i * step;

        csv_file << x << "," << trig(x) << "\n" ;

    }

    csv_file.close();

    std::cout << "successfully written to file" << std::endl;


}