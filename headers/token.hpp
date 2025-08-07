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

template <typename T>
Token<T>::Token() { }
template <typename T>
Token<T>::Token(T val) : value(val) { }
template <typename T>
Token<T>::Token(T val, char tp, int prio) : value(val), type(tp), priority(prio) { }

template <typename T>    
inline T Token<T>::get_value() { return value; }
template <typename T>
inline char Token<T>::get_type() { return type; }
template <typename T>
inline int Token<T>::get_priority() { return priority; }

