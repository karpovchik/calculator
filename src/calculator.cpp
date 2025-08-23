#include <iostream>
#include "../headers/funcs.hpp"
#include "prepare_funcs.cpp"
#include "calc_funcs.cpp"

int main() {
    char ch = ' ';

    system("clear");

    std::cout << "<<< This is a calculator >>>\n\n"; 
    std::cout << "<< It can perform the following operations >>\n\n";
    std::cout << "'+' '-' '*' '/' '%' '^' '!';\n"
                 "'log' to base 2;\n'lg' to base 10;\n'ln' to base 'e';\n"
                 "'sin' 'cos' 'tan' 'ctan';\n"
                 "'asin' 'acos' 'atan' 'actan'.\n\n";
    std::cout << "In the end of the expression you should print ';' to calculate the result "
                 "and see it on screen.\nTo exit program type 'q'.\n\n";

    std::cout << "Example: 9.4-7*(6+49.07/78)+(-23)*log(9)+sin(15)+((30-2)%8.04);\n\n";

    while(ch != 'q')
    {
        std::cout << "> ";
        while (true)
        {
            std::cin >> ch;

            if (ch == 'q') { std::cout << "GoodBye!\n"; break; }

            else if (ch == ';') 
            {
                std::cout << "= " << prep_calc() << "\n";
                buff.set_value(' ');
                break;
            }
            else { get_symbl(ch); }
        }
    }
    return 0;
}
