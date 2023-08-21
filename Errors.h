#pragma once
#include <iostream>
#include <string>

namespace Error
{
  enum class ErrorTypes
  {
    Info,
    Warning,
    Error
  };
  void DisplayError(ErrorTypes Type, const std::string& Message);
}