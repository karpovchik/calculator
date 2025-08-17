// Здесь реализован класс Token_Buffer для хранения предыдущего токена

class Token_Buffer {
private:
    char buff;
public:
    Token_Buffer();
    inline void set_value(char val_);
    inline char get_value();
};

Token_Buffer::Token_Buffer() { 
    buff = ' ';
}

inline void Token_Buffer::set_value(char val_) { buff = val_; }
inline char Token_Buffer::get_value() { return buff; }
