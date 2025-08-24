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
    "To calculate logarithms, you should enter 'log' then a log`s base and then in braces an expression;\n"
    "To simplify logarithms` inputs with bases 2, 10 and 'e', "
    " you may not specify explicitly these bases and type: 'log()', 'lg()' and 'ln()' accordingly;\n"
    "'sin()' 'cos()' 'tan()' 'ctan()';\n"
    "'asin()' 'acos()' 'atan()' 'actan()';\n";
    std::cout << "Also, you can use some constants: exponent {'e' or 'E'} "
    "and pi number {'pi' or 'pI' or 'PI' or 'Pi'}.\n\n";

    std::cout << "In the end of the expression you should print ';' to calculate the result "
                 "and see it on screen.\nTo exit program type 'q'.\n\n";

    std::cout << "Example: 9.4-7*(6+49.07/78)+(-23)*log(9)+sin(15)+((30-2)%8.04);\n";

    while(ch != 'q')
    {
        std::cout << "\n> ";
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
