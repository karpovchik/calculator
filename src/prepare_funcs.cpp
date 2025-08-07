#include "token.cpp"
#include "store.cpp"
#include "../headers/prepare_funcs.hpp"

/* Для формирования ОПЗ определяются приоритеты операторов:
    '^' : 1,
    '!' : 2,
    '*' : 3, '/' : 3, '%' : 3,
    '+' : 4, '-' : 4,
    '(' : 5, '[' : 5, '{' : 5
*/

std::unordered_map<char, int> operators { 
    {'^', 1},
    {'!', 2},
    {'*', 3}, {'/', 3}, {'%', 3},
    {'+', 4}, {'-', 4},
    {'(', 5}, {'[', 5}, {'{', 5}
};

inline void get_token(char& ch_) {
    switch(ch_) {
        case '+': case '-': case '*':
        case '/': case '%': case '^': case '!':
            op_priority(ch_);
            break;
/*
        case '(': case '[': case '{':
            open_brace(ch);
            break;

        case ')': case ']': case '}':
            close_brace(ch);
            break;

        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            digit(ch);
            break;

        case 'l': case 's': case 'c': case 't': case 'a':
            func(ch);
            break;
*/
        default:
            error("[ERROR] Wrong input! You entered a wrong symbol!\n");
    }
}

template <typename T>
inline void op_priority(char& ch_) {
    Token<T> t;
    
    t.value = ch_;
    if (ch_ == '!') { t.type = 'u'; }
    else { t.type = 'b'; }

    for (auto& oper : operators) {
        if (ch_ == oper.first) { t.priority = oper.second; } 
    } 
    
    if (stack.get_size() == 0)
        stack.push_front(t);
/*    
    else { 
        if (t.priority < stack.get_front().priority)
            high_priority(t);

        else if (t.priority == stack.get_front().priority)
            equal_priority(t);

        else 
            low_priority(t);
    }
*/
}

/*
inline void high_priority(Token& t_) {
    stack.push_front(t_);
}

inline void equal_priority(Token& t_) {
    Token tmp_t = get_front();
    
    stack.pop_front();

    queue.push_back(tmp_t);
    stack.push_front(t_);
}

inline void low_priority(Token& t_) {
    Token tmp_t;

    while (t_.priority > stack.get_front().priority) {
        tmp_t = stack.get_front();
        stack.pop_front();
        queue.push_back(tmp_t);

        if (stack.get_size() == 0) { break; }
    }

    if (stack.get_size() == 0)              // когда стэк пуст - любой оператор высокого приоритета
        stack.push_front(t_);

    else if (t_.priority == stack.get_front().priority)
        equal_priority(t_);

    else 
        high_priority(t_);
}
*/
