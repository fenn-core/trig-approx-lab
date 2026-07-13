cmake_minimum_required(VERSION 3.20)
project(trig_approx_lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(trig_approx_lab
        src/main.cpp
        src/reference.cpp
        src/taylor.cpp
        include/reference.hpp
        include/taylor.hpp
        include/csv.hpp
        src/csv.cpp
        include/approx.hpp
        src/approx.cpp
        include/cordic.hpp
        src/cordic.cpp
)

target_include_directories(trig_approx_lab
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)