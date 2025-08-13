#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
#include "token.hpp"
#include "store.hpp"

Store stack;
Store queue;

// Здесь расположены объявления функций для подготовки к вычислениям,
// а также иные вспомогательные функции

inline void get_symbl(char& ch_);

// Funcs for operators
inline void op_priority(char& ch_);

inline void high_priority(Token& t_);

inline void equal_priority(Token& t_);

inline void low_priority(Token& t_);
