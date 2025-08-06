// Здесь реализуется класс Token
// value : число, или символ, или строка
// type : операция унарная или бинарная
// priority только для операторов

template <typename T> 
class Token {
private:
    T value;
    char type;
    int priority;

public:
    Token();
    Token(T val);
    Token(T val, char tp, int prio);
    
    inline T get_value();
    inline char get_type();
    inline int get_priority();
};
