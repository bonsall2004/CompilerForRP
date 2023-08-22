#pragma once
#include <string>
#include <vector>
#include <optional>
#include "Grammar.h"
#include "Errors.h"

struct Token
{
  Grammar::ValidTokens Type;
  std::optional<std::string> Value;
};

class Lexer
{
private:
  const std::string m_src;
  int m_index = 0;

public:
  explicit Lexer(std::string src);
  std::vector<Token> Tokenize();
  char consume();
  std::optional<char> peek(int ahead = 1) const;
};