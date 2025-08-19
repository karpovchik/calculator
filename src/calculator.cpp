#include <iostream>
#include "prepare_func.cpp"

iint main() {
    char ch = ' ';

    while(true) {
        std::cout << " > ";
        
        std::cin >> ch;

        if (ch == 'q') { std::cout << "GoodBye!\n"; break; }

        else if (ch == ';') { std::cout << " = " << prep_calc(); break; }

        else { get_symbl(); }
    }

    return 0;
}
