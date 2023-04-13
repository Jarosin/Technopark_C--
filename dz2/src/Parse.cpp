#include "Parse.hpp"

#include <exception>
#include <iostream>
#include <regex>

#include "Addition.hpp"
#include "Brackets.hpp"
#include "Ceil.hpp"
#include "ICalculatableBinary.hpp"
#include "ICalculatableUnary.hpp"
#include "Multiplication.hpp"
#include "Number.hpp"
#include "SqRoot.hpp"
#include "Substraction.hpp"

constexpr auto kSqrtSign = "@";
constexpr auto kSqrtWord = "sqrt";
constexpr auto kCeilSign = "&";
constexpr auto kCeilWord = "ceil";
constexpr auto kAddSign = '+';
constexpr auto kSubSign = '-';
constexpr auto kMulSign = '*';
constexpr auto kOpenBracket = '(';
constexpr auto kCloseBracket = ')';

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

std::unique_ptr<ICalculatable> getArg(std::string &inp) {
  std::unique_ptr<ICalculatable> res;
  bool met_number = false;

  if (inp[0] == kCloseBracket) {
    int end = FindOpeningBracket(inp);
    std::string sub = inp.substr(1, end - 1);
    res = CreateOperation(sub);
    res = std::make_unique<Brackets>(std::move(res));
    inp = inp.substr(end + 1);
    met_number = true;
  }

  for (char *i = &(inp[0]); *i != '\0'; i++) {
    if (*i == kAddSign || *i == kSubSign) {
      inp = inp.substr(i - &(inp[0]));
      return res;
    }

    if (*i == kMulSign) {
      if (!met_number)
        throw std::invalid_argument("Unary multiplication doesnt exist");
      inp = inp.substr(i - &inp[0] + 1);
      auto right_operator = getArg(inp);
      res = std::make_unique<Multiplication>(std::move(res),
                                             std::move(right_operator));
      return res;
    }

    if (isdigit(*i)) {
      if (met_number) {
        throw std::invalid_argument(
            "Two numbers without binary operations in a row");
      }

      met_number = true;
      std::string num = "";
      while (*i != '\0') {
        if (!isdigit(*i) && !(*i == '.' && num.find('.') == std::string::npos))
          break;
        num += *i;
        i++;
      }

      std::reverse(num.begin(), num.end());
      res = std::make_unique<Number>(std::stod(num));
      i--;
    } else {
      if (!met_number) {
        throw std::invalid_argument("Unary operations without number");
      }

      switch (*i) {

        case kCeilSign[0]:
          res = std::make_unique<Ceil>(std::move(res));
          break;

        case kSqrtSign[0]:
          res = std::make_unique<SqRoot>(std::move(res));
          break;

        default:
          throw std::invalid_argument("Unknown operator given");
      }
    }
  }

  inp = "";
  return res;
}

std::unique_ptr<ICalculatable> CreateOperation(std::string &inp) {
  std::unique_ptr<ICalculatable> res;
  std::unique_ptr<ICalculatable> val1 = getArg(inp);
  if (inp.empty()) return val1;
  char operation = inp[0];
  std::string sub = inp.substr(1);
  std::unique_ptr<ICalculatable> val2 = CreateOperation(sub);
  switch (operation) {

    case kAddSign:
      if (!val2) {
        val2 = std::make_unique<Number>(0);
      }
      res = std::make_unique<Addition>(std::move(val2), std::move(val1));
      break;

    case kSubSign:
      if (!val2) {
        val2 = std::make_unique<Number>(0);
      }
      res = std::make_unique<Substraction>(std::move(val2), std::move(val1));
      break;

    case kMulSign:
      res = std::make_unique<Multiplication>(std::move(val1), std::move(val2));
      break;

    default:
      throw std::invalid_argument("Unknown operator given");
  }
  return res;
}

std::unique_ptr<ICalculatable> ParseInput(std::string inp) {
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
  std::unique_ptr<ICalculatable> res = CreateOperation(inp);
  return res;
}
