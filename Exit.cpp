#include "Exit.h"

std::string Exit::GenerateAssembly(std::vector<Token> Arguments)
{
  std::string Assembly = "";
  Assembly + "mov rax, 60 \nmov rdi, " + Arguments.front().Value.value() + "\nsyscall";
  return Assembly;
};