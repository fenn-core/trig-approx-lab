//
// Created by pusana on 7/1/26.
//

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "approx.hpp"


namespace approx {

    std::string file_name(Function func, Method method) {
        std::string func_str;
        switch (func) {
            case Function::Sin: func_str = "sin"; break;
            case Function::Cos: func_str = "cos"; break;
        }

        std::string method_str;
        switch (method) {
            case Method::Reference: method_str = "reference"; break;
            case Method::Taylor: method_str = "taylor"; break;
            case Method::Cordic: method_str = "cordic"; break;
            case Method::Minimax: method_str = "minimax"; break;
        }

        return (func_str + "_" + method_str + ".csv");

    }


    void write_csv(Function func,
                   Method method,
                   Samples samples) {


        std::string name = file_name(func, method);
        std::string rel_path = "data/" + name;
        std::filesystem::path abs_path = std::filesystem::absolute(rel_path);

        std::ofstream csv_file(abs_path);
        csv_file << std::fixed << std::setprecision(15);

        if (!csv_file.is_open()) {
            std::cout << "error, couldn't open file" << std::endl;
            return;
        }

        for (int i = 0; i < samples.x.size(); ++i) {
            csv_file << samples.x[i] << "," << samples.y[i] << "\n" ;
        }

        csv_file.close();
        std::cout << "successfully written to file " << name << std::endl;

    }

}