#include "../headers/token.hpp"

// Определения функций класса Token
template <typename T>
Token<T>::Token() : value(0), type(' '), priority(0) { }
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
