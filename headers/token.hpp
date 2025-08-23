// Здесь реализуется класс Token
// kind : признак оператора, или скобки, или функции
// value : число
// priority только для операторов
// func : тип функции

class Token {
private:
    char kind;
    std::string func;
    int priority;
    double value;

public:
    Token();
    Token(char kd, std::string fnc, int prio, double val);
   
    inline void set_kind(char kd);
    inline void set_func(std::string fnc);
    inline void set_value(double val);
    inline void set_priority(int prio);

    inline char get_kind();
    inline std::string get_func();
    inline double get_value();
    inline int get_priority();
};

Token::Token() { 
    kind = '0';
    func = "0";
    priority = 0;
    value = 0;
}

Token::Token(char kd, std::string fnc, int prio, double val) {
    kind = kd;
    func = fnc;
    priority = prio;
    value = val;
}

inline char Token::get_kind() { return kind; }
inline std::string Token::get_func() { return func; }
inline double Token::get_value() { return value; }
inline int Token::get_priority() { return this->priority; }

inline void Token::set_kind(char kd) { kind = kd; }
inline void Token::set_func(std::string fnc) { func = fnc; }
inline void Token::set_priority(int prio) { priority = prio; }
inline void Token::set_value(double val) { value = val; }

