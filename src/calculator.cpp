#include <iostream>
#include "../headers/funcs.hpp"
#include "prepare_funcs.cpp"
#include "calc_funcs.cpp"

int main() {
    char ch = ' ';

    system("clear");
    while(true) {
        std::cout << " > ";
        
        std::cin >> ch;

        if (ch == 'q') { std::cout << "GoodBye!\n"; break; }

        else if (ch == ';') { std::cout << " = " << prep_calc() << "\n"; break; }

        else { get_symbl(ch); }
    }

    return 0;
}
