void check_empty_in()
{
    if (queue.get_size() == 0)
    {
        error("[ERROR] You didn`t enter any expression!\n");
        abort();
    }
}

void check_div(double& v_)
{
    if (v_ == 0) {
         error("[ERROR] Division by zero!\n");
         abort();
    }
}

void fromStack_toQueue() 
{
    Token t;

    while(stack.get_size() != 0)
    {
        t = stack.get_front();
        stack.pop_front();

        if (t.get_kind() == '(') 
        {
            error("[ERROR] You`ve missed a ')'\n");
            abort();
        }
        queue.push_back(t);
    }
}

inline void fromQueue_toStack() 
{
    Token t;

    while(queue.get_front().get_kind() == '0')
    {
        t = queue.get_front();
        queue.pop_front();
        stack.push_front(t);
    }
}

double fact(double& v_)
{
    double res = 1;    

    if (v_ < 0)
    {
        error("[ERROR] Negative number doesn`t have a factorial!\n");
        abort();
    }
    else if (std::fmod(v_, 1) != 0)
    {
        error("[ERROR] Only integers have factorials!\n");
        abort();
    }
    else 
    {
        if (v_ == 0) { return 1; }
        else
        {
            while (v_ != 0)
            {
                res *= v_;
                --v_;
            }
            return res;
        }
    }
}

double calculations() 
{
    char ch = ' ';
    std::string f = "";
    double val1 = 0;
    double val2 = 0;
    double bs = 0;

    ch = queue.get_front().get_kind();
    f = queue.get_front().get_func();
    bs = queue.get_front().get_value();
    queue.pop_front();

    val2 = stack.get_front().get_value();
    stack.pop_front();

    switch(ch)
    {
        case '+':
            val1 = stack.get_front().get_value();
            stack.pop_front();
            return val1 + val2;
        case '-':
            val1 = stack.get_front().get_value();
            stack.pop_front();
            return val1 - val2;
        case '*':
            val1 = stack.get_front().get_value();
            stack.pop_front();
            return val1 * val2;
        case '/':
            check_div(val2);
            val1 = stack.get_front().get_value();
            stack.pop_front();
            return val1 / val2;
        case '%':
            check_div(val2);
            val1 = stack.get_front().get_value();
            stack.pop_front();
            return std::fmod(val1, val2);
        case '^':
            val1 = stack.get_front().get_value();
            stack.pop_front();
            return std::pow(val1, val2);
        case '!':
            return fact(val2);
        case '~':
            return -1*val2;
        case 'f':
            if (f == "sin") { return std::sin(val2); }
            else if (f == "cos") { return std::cos(val2); }
            else if (f == "tan") { return std::tan(val2); }
            else if (f == "ctan") { return 1.0 / std::tan(val2); }

            else if (f == "asin") { return std::asin(val2); }
            else if (f == "acos") { return std::acos(val2); }
            else if (f == "atan") { return std::atan(val2); }
            else if (f == "actan") { return 1.0 / std::atan(val2); }

            else if (f == "log" && (bs == 0 || bs == 2)) { return std::log2(val2); }
            else if (f == "lg" && (bs == 0 || bs == 10)) { return std::log10(val2); }
            else if (f == "ln" && (bs == 0 || bs == E)) { return std::log(val2); }
            else { if (f == "log") { return std::log2(val2) / std::log2(bs); } }
        default:
            error("[ERROR] Wrong symbol!\n");
            abort();
    }
}

double prep_calc() 
{
    double val = 0;
    Token t;

    check_empty_in();
 
    fromStack_toQueue();

    while(queue.get_size() != 0) 
    {
        fromQueue_toStack();             

        t.set_value(calculations());
        stack.push_front(t);
    }
    val = stack.get_front().get_value();
    stack.pop_front();

    return val;
}


