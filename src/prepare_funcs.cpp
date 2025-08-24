/* Для формирования ОПЗ определяются приоритеты операторов
1 - Наивысший приоритет:
    '~' : 1,
    '^' : 2,
    '!' : 3,
    '*' : 4, '/' : 4, '%' : 4,
    '+' : 5, '-' : 5,
    '(' : 6, '[' : 6, '{' : 6
*/

std::unordered_map<char, int> operators 
{ 
    {'~', 1},
    {'a', 2}, {'c', 2}, {'l', 2}, {'s', 2}, {'t', 2},
    {'^', 3},
    {'!', 4},
    {'*', 5}, {'/', 5}, {'%', 5},
    {'+', 6}, {'-', 6},
    {'(', 7}
};

inline void get_symbl(char& ch_) 
{
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

        case 'l': case 's': case 'c': case 't': case 'a':
            func(ch_);
            break;

        case 'e': case 'E':
            add_E(ch_);
            break;

        case 'p': case 'P':
            add_PI(ch_);
            break;

        default:
            error("[ERROR] Wrong input! You entered a wrong symbol!\n");
            abort();
    }
    buff.set_value(ch_);
}

inline void op_priority(char& ch_) 
{
    Token t;

    if (ch_ == '-' && (buff.get_value() == ' ' || buff.get_value() == '(')) {
        ch_ = '~';
        t.set_kind(ch_);
    }
    else if (ch_ == '!') { t.set_kind('!'); }

    else { t.set_kind(ch_); }

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

inline void high_priority(Token& t_)
{
    stack.push_front(t_);
}

inline void equal_priority(Token& t_) 
{
    Token tmp_t = stack.get_front();
    
    stack.pop_front();

    queue.push_back(tmp_t);
    stack.push_front(t_);
}

inline void low_priority(Token& t_)
{
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

void open_brace(char& ch_) 
{
    Token t(ch_, "0", 7, 0);

    high_priority(t);
}

void close_brace() 
{
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

inline void digit(char ch_) 
{
    double val;
    Token t;

    std::cin.putback(ch_);
    std::cin >> val;

    t.set_value(val);
    queue.push_back(t);
}

void func(char& ch_) 
{
    std::string f;
    Token t;
    
    while (ch_ != '(')
    {
        f += ch_;
        std::cin >> ch_;
    }
    std::cin.putback(ch_);
    ch_ = 'f';

    if (f == "log" || f == "lg" || f == "ln" || f == "sin" || f == "cos" || f == "tan" 
    || f == "ctan" || f == "asin" || f == "acos" || f == "atan" || f == "actan") {
        t.set_kind('f');
        t.set_func(f);
        stack.push_front(t);
    }
    else {
        error("[ERROR] Wrong input!\nYou entered wrong function or a wrong symbol.\n");
    }
}

void add_E(char& ch_)
{
    Token t;
    
    t.set_value(E);
    queue.push_back(t);
}

void add_PI(char& ch_)
{
    char next_ch = ' ';
    Token t;

    std::cin >> next_ch;
    if (next_ch == 'i' || next_ch == 'I')
    {
        t.set_value(PI);
        queue.push_back(t);
    }
    else
    {
        error("[ERROR] Wrong input!\n'I' or 'i' should go after 'p' or 'P'!\n");
        abort();
    }
}
