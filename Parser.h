#pragma once
#include <vector>
#include "Grammar.h"
#include "Lexer.h"

struct ParsedItem
{
  Grammar::ValidTokens Type;
  std::optional<std::vector<Token>> Arguments;
};

class Parser
{
  private:
    std::vector<Token> tokens;
    std::vector<ParsedItem> Parse();
};