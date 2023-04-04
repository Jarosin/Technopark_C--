#include <iostream>
#include <memory>

#include "ICalculatable.hpp"
#include "Parse.hpp"
int main() {
  std::string a("(1 + 10) + (1 - 1 + 100)");
  std::unique_ptr<ICalculatable> res = ParseInput(a);
  std::cout << res->Calculate();
  return 0;
}
