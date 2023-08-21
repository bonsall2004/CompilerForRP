#pragma once
#include <string>
#include <map>

namespace DataTypes
{
  enum class Types
  {
    int_literal,
    float_literal,
    string_literal
  };

  extern std::map<std::string, Types> invocations_map = {
    {"int", Types::int_literal},
    {"float", Types::float_literal},
    {"string", Types::string_literal}
  };
}