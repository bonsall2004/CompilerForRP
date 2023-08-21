#pragma once
#include <string>
#include <map>

namespace Invocations
{
  enum class Invocations
  {
    _return,
    _exit
  };

  extern std::map<std::string, Invocations> invocations_map = {
    {"return", Invocations::_return},
    {"exit", Invocations::_exit},
    {"quit", Invocations::_exit}
  };
}