#pragma once
#include <vector>
#include "Grammar.h"
#include "Tokenizer.h"

struct ParseItem
{
  Grammar::ValidTokens Token;
  std::optional<std::vector<std::string>> Arguments;
};

class Parser
{
  private:
    std::vector<Token> tokens;
};