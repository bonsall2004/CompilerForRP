#pragma once
#include "LangDef.h"

class Exit : public Default
{
  TokenStructure structure = {
    .Type = Grammar::ValidTokens::_exit,
    .ArgCount = 1,
    .Arguments = { Grammar::ValidTokens::int_literal }
  };

  std::string GenerateAssembly(std::vector<Token> Arguments) override;
};