#include "Tokenizer.h"
#include <cctype>

Tokenizer::Tokenizer(std::string src) : m_src(std::move(src)) {}

std::vector<Token> Tokenizer::Tokenize()
{
  std::vector<Token> tokens;
  std::string buffer;
  std::string char_buffer;

  while (peek().has_value()) // Main Loop
  {
    if (peek().has_value() && std::isalpha(peek().value())) // Keyword Check
    {
      buffer.push_back(consume());
      while (peek().has_value() && (std::isalnum(peek().value())))
      {
        buffer.push_back(consume());
      }
      if (Grammar::Token_Map.contains(buffer))
      {
        tokens.emplace_back(Token{ .Type = Grammar::Token_Map.find(buffer)->second });
        buffer.clear();
      }
    }
    else if (peek().has_value() && std::isdigit(peek().value())) // Numbers
    {
      buffer.push_back(consume());
      while (peek().has_value() && (std::isdigit(peek().value()) || peek().value() == '.'))
      {
        buffer.push_back(consume());
      }
      Grammar::ValidTokens type;
      if (buffer.find(".") != std::string::npos)
      {
        type = Grammar::ValidTokens::float_literal;
      }
      else
      {
        type = Grammar::ValidTokens::int_literal;
      }
      tokens.emplace_back(Token{
          .Type = type,
          .Value = buffer
        });
      buffer.clear();
    }
    else if (peek().value() == '"')
    {
      consume();
      while (peek().value() != '"')
      {
        buffer.push_back(consume());
      }

      tokens.emplace_back(Token{ .Type = Grammar::ValidTokens::string_literal, .Value = buffer});
      buffer.clear();
      consume();
    }
    else if (std::isspace(peek().value())) // Check if its a space
    {
      consume();
    } 
    else if (peek().value() == ';') // Semicolon
    {
      tokens.emplace_back(Token{ .Type = Grammar::ValidTokens::semicolon });
      buffer.clear();
      consume();
    }
    else if (peek().value() == '+') // Addition / Increment
    {
      Grammar::ValidTokens tokenType;
      consume();
      if (peek().value() == '+')
      {
        tokenType = Grammar::ValidTokens::increment;
        consume();
      }
      else
      {
        tokenType = Grammar::ValidTokens::addition;
      }
        tokens.emplace_back(Token{ .Type = tokenType });
        buffer.clear();
    }
    else if (peek().value() == '-') // Subtraction / Decrement
    {
      Grammar::ValidTokens tokenType;
      consume();
      if (peek().value() == '-')
      {
        tokenType = Grammar::ValidTokens::decrement;
        consume();
      }
      else
      {
        tokenType = Grammar::ValidTokens::subtraction;
      }
      tokens.emplace_back(Token{ .Type = tokenType });
      buffer.clear();
    }
    else if (peek().value() == '*') // Multiplication
    {
      consume();
      tokens.emplace_back(Token{ .Type = Grammar::ValidTokens::multiply });
      buffer.clear();
    }
    else if (peek().value() == '/') // Division
    {
      consume();
      tokens.emplace_back(Token{ .Type = Grammar::ValidTokens::divide });
      buffer.clear();
    }
    else if (peek().value() == '%') // Modulo
    {
      consume();
      tokens.emplace_back(Token{ .Type = Grammar::ValidTokens::modulo });
      buffer.clear();
    }
    else if (peek().value() == '^') // Power of / xor
    {
      Grammar::ValidTokens tokenType;
      consume();

      tokenType = Grammar::ValidTokens::pow;
      
      tokens.emplace_back(Token{ .Type = tokenType });
      buffer.clear();
    }
    else if (peek().value() == '>') // Greater (equ)
    {
      Grammar::ValidTokens tokenType;
      consume();
      if (peek().value() == '=')
      {
        tokenType = Grammar::ValidTokens::greaterequ;
        consume();
      }
      else
      {
        tokenType = Grammar::ValidTokens::greater;
      }
      tokens.emplace_back(Token{ .Type = tokenType });
      buffer.clear();
    }
    else if (peek().value() == '<') // Less (equ)
    {
      Grammar::ValidTokens tokenType;
      consume();
      if (peek().value() == '=')
      {
        tokenType = Grammar::ValidTokens::lessequ;
        consume();
      }
      else
      {
        tokenType = Grammar::ValidTokens::less;
      }
      tokens.emplace_back(Token{ .Type = tokenType });
      buffer.clear();
    }
    else if (peek().value() == '=') // Equ / Assignment
    {
      Grammar::ValidTokens tokenType;
      consume();
      if (peek().value() == '=')
      {
        tokenType = Grammar::ValidTokens::equal;
        consume();
      }
      else
      {
        tokenType = Grammar::ValidTokens::assignment;
      }
      tokens.emplace_back(Token{ .Type = tokenType });
      buffer.clear();
    }
    else if (peek().value() == '&') // And
    {
      Grammar::ValidTokens tokenType;
      consume();
      if (peek().value() == '&')
      {
        tokenType = Grammar::ValidTokens::_xand;
        consume();
      }
      else
      {
        tokenType = Grammar::ValidTokens::_and;
      }
      tokens.emplace_back(Token{ .Type = tokenType });
      buffer.clear();
    }
    else if (peek().value() == '|') // Or
    {
      Grammar::ValidTokens tokenType;
      consume();
      if (peek().value() == '|')
      {
        tokenType = Grammar::ValidTokens::_or;
        consume();
      }
      else
      {
        tokenType = Grammar::ValidTokens::_or;
      }
      tokens.emplace_back(Token{ .Type = tokenType });
      buffer.clear();
    }
    else if (peek().value() == '!') // Or
    {
      consume();
      tokens.emplace_back(Token{ .Type = Grammar::ValidTokens::_not });
      buffer.clear();
    }
    else
    {
      Error::DisplayError(Error::ErrorTypes::Error, (std::string)"Invalid Keyword at character");
      consume();
    }

    // Add other tokenization cases here

  }
  this->m_index = 0;
  return tokens;
}

char Tokenizer::consume()
{
  return m_src.at(m_index++);
}

std::optional<char> Tokenizer::peek(int ahead) const
{
  if (((int32_t)ahead + (int32_t)m_index) > m_src.length())
  {
    return {};
  }
  else
  {
    return m_src.at(m_index);
  }
}