#include "Errors.h"

namespace Error
{
  void DisplayError(ErrorTypes Type, const std::string& Message)
  {
    switch (Type)
    {
    case ErrorTypes::Info:
      std::cout << "\x1B[34m[Info]\033[0m " << Message << std::endl;
      break;
    case ErrorTypes::Warning:
      std::cout << "\x1B[33m[Warning]\033[0m " << Message << std::endl;
      break;
    case ErrorTypes::Error:
      std::cout << "\x1B[31m[Error]\033[0m " << Message << std::endl;
      break;
    default:
      break;
    }
    return;
  };
}