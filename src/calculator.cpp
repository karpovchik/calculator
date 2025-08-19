#include <iostream>
#include "../headers/prepare_funcs.hpp"
#include "prepare_funcs.cpp"
#include "calc_funcs.cpp"

int main() {
    double v = 0;
    char ch = ' ';

    while(true) {
        std::cout << " > ";
        
        std::cin >> ch;

        if (ch == 'q') { std::cout << "GoodBye!\n"; break; }

        else if (ch == ';') { v = prep_calc(); std::cout << " = " << v; break; }

        else { get_symbl(ch); }
    }

    return 0;
}
