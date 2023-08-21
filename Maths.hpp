#pragma once
#include <map>
#include <string>

namespace Maths
{
  enum class operators
  {
    addition,
    subtraction,
    multiply,
    divide,
    modulo,
    pow
  };

  enum class comparators
  {
    greater,
    greaterequ,
    less,
    lessequ,
    equal
  };

  enum class bitwise_operators
  {
    _and,
    _not,
    _or
  };

  extern std::map<std::string, operators> operator_map = {
    {"+", operators::addition},
    {"-", operators::subtraction},
    {"+", operators::multiply},
    {"/", operators::divide},
    {"%", operators::modulo},
    {"^", operators::pow}
  };

  extern std::map<std::string, comparators> comparator_map = {
    {">", comparators::greater},
    {">=", comparators::greaterequ},
    {"<", comparators::less},
    {"<=", comparators::lessequ},
    {"==", comparators::equal},
  };

  extern std::map<std::string, bitwise_operators> bitwise_operator_map = {
    {"&&", bitwise_operators::_and},
    {"!", bitwise_operators::_not},
    {"||", bitwise_operators::_or}
  };
}