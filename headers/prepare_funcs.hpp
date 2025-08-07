#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

Store stack;
Store queue;

// Здесь расположены объявления функций для подготовки к вычислениям,
// а также иные вспомогательные функции

inline void error(std::string s) {
    std::cout << s;
}

inline void get_token(char& ch_);

// Funcs for operators
template <typename T>
inline void op_priority(char& ch_);

template <typename T>
inline void high_priority(Token<T>& t_);

template <typename T>
inline void equal_priority(Token<T>& t_);

template <typename T>
inline void low_priority(Token<T>& t_);
