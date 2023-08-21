#pragma once
#include <string>
#include <map>

namespace Grammar
{
  enum class ValidTokens
  {
    // Operators
    addition,
    subtraction,
    multiply,
    divide,
    modulo,
    pow,
    increment,
    decrement,
    assignment,

    // Comparators
    greater,
    greaterequ,
    less,
    lessequ,
    equal,

    // Bitwise
    _and,
    _xand,
    _not,
    _or,
    _xor,

    // Data Types
    int_literal,
    float_literal,
    string_literal,
    void_literal,

    // Invocations 
    _return,
    _exit,

    // Punctuation
    semicolon,
    doublequotes,
    singlequotes
  };

  extern std::map<std::string, ValidTokens> Token_Map;
}