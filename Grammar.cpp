#include <vector>
#include "Grammar.h"

namespace Grammar
{
  struct TokenStructure
  {
    ValidTokens TokenType;
    std::vector<ValidTokens> Arguments = {};
  };

  std::map<std::string, TokenStructure> Token_Map = {
    // Operators
    {"+",   {.TokenType = ValidTokens::addition, .Arguments = { ValidTokens::number_literal, ValidTokens::number_literal } }},
    {"++",   ValidTokens::increment },
    {"-",   ValidTokens::subtraction},
    {"--",   ValidTokens::decrement},
    {"*",   ValidTokens::multiply},
    {"/",   ValidTokens::divide},
    {"%",   ValidTokens::modulo},
    {"^",   ValidTokens::pow},
    {"=",   ValidTokens::assignment},

    // Comparators
    {">",   ValidTokens::greater},
    {">=",  ValidTokens::greaterequ},
    {"<",   ValidTokens::less},
    {"<=",  ValidTokens::lessequ},
    {"==",  ValidTokens::equal},

    // Bitwise
    {"&",  ValidTokens::_and},
    {"&&",  ValidTokens::_xand},
    {"!",   ValidTokens::_not},
    {"||",  ValidTokens::_or},
    {"^|",  ValidTokens::_xor},

    // Invocations
    {"return", ValidTokens::_return},
    {"exit",   ValidTokens::_exit},
    {"quit",   ValidTokens::_exit},

    // Punctuation
    {";",   ValidTokens::semicolon},
    {"\"",   ValidTokens::doublequotes},
    { "'",   ValidTokens::singlequotes }
  };
}