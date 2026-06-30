#include "reference.hpp"


int main() {

    generate_reference_csv( TrigFunction::Sin, 3.14159265359, 1000);
    generate_reference_csv( TrigFunction::Cos, 3.14159265359, 1000);


    return 0;

}
