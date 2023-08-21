#pragma once
#include <optional>
#include <vector>
#include <string>
#include "Grammar.h"
#include "Tokenizer.h"

struct TokenStructure
{
  Grammar::ValidTokens Type;
  int ArgCount;
  std::vector<Grammar::ValidTokens> Arguments;
};

class Default
{
  public:
    TokenStructure structure;
    virtual std::string GenerateAssembly(std::vector<Token> Arguments);
};