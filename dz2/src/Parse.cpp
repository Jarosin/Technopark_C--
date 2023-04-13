#include "Parse.hpp"

#include <exception>
#include <regex>

void ReplaceWords(std::string &inp) {
  inp = std::regex_replace(inp, std::regex(kSqrtWord), kSqrtSign);
  inp = std::regex_replace(inp, std::regex(kCeilWord), kCeilSign);
}

bool CheckBrackets(const std::string &inp) {
  int open = 0, close = 0;
  for (const auto &elm : inp) {
    if (elm == kOpenBracket) {
      open++;
    }
    if (elm == kCloseBracket) {
      if (close >= open) {
        return false;
      }
      close++;
    }
  }
  return true;
}

int FindOpeningBracket(const std::string &inp) {
  int i = 0, closing = 0, opening = 0;
  do {
    if (inp[i] == kCloseBracket) {
      closing++;
    } else if (inp[i] == kOpenBracket) {
      opening++;
    }
    i++;
  } while (closing != opening);
  return i - 1;
}

void DeleteSpaces(std::string &inp) {
  inp = std::regex_replace(inp, std::regex(" "), "");
}

void ReplaceCommas(std::string &inp) {
  inp = std::regex_replace(inp, std::regex(","), ".");
}


void ParseInput(std::string &inp) {
  for (auto &elm : inp) {
    elm = tolower(elm);
  }
  if (!CheckBrackets(inp)) {
    throw std::invalid_argument("Brackets are wrong");
  }
  ReplaceWords(inp);
  DeleteSpaces(inp);
  ReplaceCommas(inp);
  if (inp.empty()) throw std::invalid_argument("Given string is empty");

  std::reverse(inp.begin(), inp.end());
}
