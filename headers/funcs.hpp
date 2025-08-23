#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
#include "token.hpp"
#include "buffer.hpp"
#include "store.hpp"

Token_Buffer buff;
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

// Funcs for open and close braces

void open_brace(char& ch_);

void close_brace();

// For digits
inline void digit(char ch_);

// For funcs
void func(char& ch_);

// For factorial
double fact(double& v_);

// Preparing funcs
void check_empty_in();

void check_div(double& v_);

void fromStack_toQueue();

inline void fromQueue_toStack();

// For calculations
double prep_calc();

double calculations();
