#include "../headers/prepare_funcs.hpp"

/* Для формирования ОПЗ определяются приоритеты операторов
1 - Наивысший приоритет:
    '~' : 1,
    '^' : 2,
    '!' : 3,
    '*' : 4, '/' : 4, '%' : 4,
    '+' : 5, '-' : 5,
    '(' : 6, '[' : 6, '{' : 6
*/

std::unordered_map<char, int> operators { 
    {'~', 1},
    {'^', 2},
    {'!', 3},
    {'*', 4}, {'/', 4}, {'%', 4},
    {'+', 5}, {'-', 5},
    {'(', 6}, {'[', 6}, {'{', 6}
};

inline void get_symbl(char& ch_) {
    switch(ch_) {
        case '+': case '-': case '*':
        case '/': case '%': case '^': case '!':
            op_priority(ch_);
            break;

        case '(':
            open_brace(ch_);
            break;

        case ')':
            close_brace();
            break;

        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            digit(ch_);
            break;
/*
        case 'l': case 's': case 'c': case 't': case 'a':
            func(ch);
            break;
*/
        default:
            error("[ERROR] Wrong input! You entered a wrong symbol!\n");
    }
    buff.set_value(ch_);
}

inline void op_priority(char& ch_) {
    Token t;

    if (ch_ == '-' && (buff.get_value() == ' ' || buff.get_value() == '('))
        t.set_kind('~');
    else
        t.set_kind(ch_);

    for (auto& oper : operators) {
        if (ch_ == oper.first) { t.set_priority(oper.second); } 
    } 
    
    if (stack.get_size() == 0)
        stack.push_front(t);
    
    else { 
        if (t.get_priority() < stack.get_front().get_priority())
            high_priority(t);

        else if (t.get_priority() == stack.get_front().get_priority())
            equal_priority(t);

        else 
            low_priority(t);
    }

}

inline void high_priority(Token& t_) {
    stack.push_front(t_);
}

inline void equal_priority(Token& t_) {
    Token tmp_t = stack.get_front();
    
    stack.pop_front();

    queue.push_back(tmp_t);
    stack.push_front(t_);
}

inline void low_priority(Token& t_) {
    Token tmp_t;

    while (t_.get_priority() > stack.get_front().get_priority()) {
        tmp_t = stack.get_front();
        stack.pop_front();
        queue.push_back(tmp_t);

        if (stack.get_size() == 0) { break; }
    }

    if (stack.get_size() == 0)              // когда стэк пуст - любой оператор высокого приоритета
        stack.push_front(t_);

    else if (t_.get_priority() == stack.get_front().get_priority())
        equal_priority(t_);

    else 
        high_priority(t_);
}

void open_brace(char& ch_) {
    Token t(ch_, '0', "0", 0, 0);

    high_priority(t);
}

void close_brace() {
    Token t;

    while(true) {
        if (stack.get_size() == 0) {
            error("[ERROR] You`ve missed a '('!\n");
            abort();
        }
        t = stack.get_front();
        stack.pop_front();
        
        if (t.get_kind() == '(') { break; }

        queue.push_back(t);
    }

}

inline void digit(char ch_) {
    double val;
    Token t;

    std::cin.putback(ch_);
    std::cin >> val;

    t.set_value(val);
    queue.push_back(t);
}
