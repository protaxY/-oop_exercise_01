#include <iostream>
#include "Position.h"
int main(){
    Position example1,example2;
    double latitude1, longitude1;
    std::cin >> latitude1 >> longitude1;
    if (std::cin.fail()){
        std:: cout << "incorrect output" << std::endl;
        return 0;
    }
    double latitude2, longitude2;
    if (std::cin.fail()){
        std:: cout << "incorrect output" << std::endl;
        return 0;
    }
    std::cin >> latitude2 >> longitude2;
    example1.set_position(latitude1, longitude1);
    example2.set_position(latitude2, longitude2);
    std::cout << "example1 cords is "; example1.print_position();
    std::cout << "example2 cords is "; example2.print_position();
    std::cout << "sum is "; (example1+example2).print_position();
    std::cout << "difference between example1 and example2 is "; (example1-example2).print_position();
    std::cout << "product of multiplication is"; (example1*example2).print_position();
    std::cout << "quotient of division between example1 and example2 is "; (example1/example2).print_position();
    std::cout << "does example1 equal example2? " << (example1==example2) << std::endl;
    std::cout << "does example1 not equal example2? " << (example1!=example2) << std::endl;
    std::cout << "does example1 >= example2? " << (example1>=example2) << std::endl;
    std::cout << "does example1 <= example2? " << (example1<=example2) << std::endl;
    std::cout << "does example1 > example2? " << (example1>example2) << std::endl;
    std::cout << "does example1 < example2? " << (example1<example2) << std::endl;
    return 0;
}
