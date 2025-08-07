#include <iostream>
#include "token.cpp"

Token token(56789);

int main() {
//    token.value = 678;
    
    std::cout << token.get_value();
    return 0;
}
