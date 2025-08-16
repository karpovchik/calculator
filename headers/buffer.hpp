// Здесь реализован класс Token_Buffer для хранения предыдущего токена

class Token_Buffer {
private:
    Token buff;
public:
    Token_Buffer();
    inline void set_token(Token tok_);
    inline char get_token();
};

Token_Buffer::Token_Buffer() { 
    buff.set_kind('0');
    buff.set_type('0');
    buff.set_func("0");
    buff.set_priority(0);
    buff.set_value(0);
}

inline void Token_Buffer::set_token(Token tok_) { buff = tok_; }
inline char Token_Buffer::get_token() { return buff.get_kind(); }
