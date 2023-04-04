#include "Parse.hpp"
// TODO: унарный минус/плюс - ?(может стоит брать как второй оператор 0)
void ReplaceWords(std::string &inp) {
  inp = std::regex_replace(inp, std::regex("sqrt"), "@");
  inp = std::regex_replace(inp, std::regex("ceil"), "&");
}
bool CheckBrackets(std::string &inp) {
  int open = 0, close = 0;
  for (auto elm : inp) {
    if (elm == '(') {
      open++;
    }
    if (elm == ')') {
      if (close >= open) {
        return false;
      }
      close++;
    }
  }
  return true;
}
int FindOpeningBracket(std::string &inp) {
  int i = 0, closing = 0, opening = 0;
  do {
    if (inp[i] == ')') {
      closing++;
    } else if (inp[i] == '(') {
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
void DeleteOuterBrackets(std::string &inp)
{
  while (inp[0] == '(' && inp[inp.size() - 1] == ')')
  {
    inp = inp.substr(1, inp.size() - 2);
  }
}
std::unique_ptr<ICalculatable> getArg(std::string &inp) {
  std::unique_ptr<ICalculatable> res;
  bool met_number = false;
  if (inp[0] == ')') {
    int end = FindOpeningBracket(inp);
    std::string sub = inp.substr(1, end - 1);
    inp[end] = '~';
    res = CalculateOperation(sub);
    res = std::make_unique<Brackets>(std::move(res));
    return res;
  }
  for (char *i = &(inp[0]); *i != '\0'; i++) {
    if (*i == '+' || *i == '-' || *i == '*') {
      // самая правая тильда - последний обработанный симовл
      *(i - 1) = '~';
      return res;
    }
    if (isdigit(*i)) {
      if (met_number) {
        throw std::invalid_argument("Two numbers in a row");
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
        case '&':
          res = std::make_unique<Ceil>(std::move(res));
          break;
        case '@':
          res = std::make_unique<SqRoot>(std::move(res));
          break;
        default:
          throw std::invalid_argument("Unknown operator given");
      }
    }
  }
  return res;
}
// TODO: доделать парсинг скобочек и умножения, вынести тильду в константы(и символы-замены для слов)
std::unique_ptr<ICalculatable> CalculateOperation(std::string &inp) {
  std::unique_ptr<ICalculatable> res;
  std::unique_ptr<ICalculatable> val1 = getArg(inp);
  if (inp.find_last_of('~') == std::string::npos) return val1;
  char operation = inp[inp.find_last_of('~') + 1];
  std::string sub = inp.substr(inp.find_last_of('~') + 2);
  std::unique_ptr<ICalculatable> val2 = CalculateOperation(sub);
  switch (operation) {
    case '+':
      res = std::make_unique<Addition>(std::move(val1), std::move(val2));
      break;
    case '-':
      res = std::make_unique<Substraction>(std::move(val2), std::move(val1));
      break;
    case '*':
      res = std::make_unique<Multiplication>(std::move(val1), std::move(val2));
      break;
    default:
      throw std::invalid_argument("Unknown operator given");
  }
  return res;
}
std::unique_ptr<ICalculatable> ParseInput(std::string &inp) {
  for (auto elm : inp) {
    elm = tolower(elm);
  }
  if (!CheckBrackets(inp)) {
    throw std::invalid_argument("Brackets are wrong");
  }
  ReplaceWords(inp);
  DeleteSpaces(inp);
  ReplaceCommas(inp);
  DeleteOuterBrackets(inp);
  std::reverse(inp.begin(), inp.end());
  std::unique_ptr<ICalculatable> res = CalculateOperation(inp);
  return res;
}
