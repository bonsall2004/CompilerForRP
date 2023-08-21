#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include "Errors.h"
#include "Tokenizer.h"

bool readFileContents(const std::string& filePath, std::string& fileContents)
{
  std::ifstream inputFileStream(filePath);

  if (!inputFileStream.is_open())
  {
    return false; // File does not exist
  }

  std::stringstream buffer;
  buffer << inputFileStream.rdbuf();
  fileContents = buffer.str();

  return true;
}

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    Error::DisplayError(Error::ErrorTypes::Error, "No file was specified.");
    return EXIT_FAILURE;
  }

  std::string filePath = argv[1];
  std::string fileContents;
  auto readStartTime = std::chrono::high_resolution_clock::now();
  if (!readFileContents(filePath, fileContents))
  {
    Error::DisplayError(Error::ErrorTypes::Warning, "File not found or could not be opened.");
    Error::DisplayError(Error::ErrorTypes::Info, "File not found or could not be opened.");
    Error::DisplayError(Error::ErrorTypes::Error, "File not found or could not be opened.");
    return EXIT_FAILURE;
  }

  auto readEndTime = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> readTimeDuration = readEndTime - readStartTime;
  std::string readTimeString = "File Reading Time: " + std::to_string(readTimeDuration.count() * 1000) + "ms";
  Error::DisplayError(Error::ErrorTypes::Info, readTimeString);
 
  auto tokenizeStartTime = std::chrono::high_resolution_clock::now();

  Tokenizer _tokenizer(fileContents);
  std::vector<Token> _tokens = _tokenizer.Tokenize();

  auto tokenizeEndTime = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> tokenizeTimeDuration = tokenizeEndTime - tokenizeStartTime;
  std::string tokenizeTimeString = "Tokenizing Time: " + std::to_string(tokenizeTimeDuration.count() * 1000) + "ms";
  Error::DisplayError(Error::ErrorTypes::Info, tokenizeTimeString);

  std::string tokenCount = "Tokens found: ";
  Error::DisplayError(Error::ErrorTypes::Info, (tokenCount + std::to_string(_tokens.size())));

  return EXIT_SUCCESS;
}