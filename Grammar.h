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

    // Number Types
    _typedef,
    number_literal,
    int_literal,
    float_literal,
    _typename,

    void_literal,
    string_literal,
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