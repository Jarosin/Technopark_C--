#include <iostream>
#include <memory>

#include "ICalculatable.hpp"
#include "Parse.hpp"
int main() {
  std::string a("2 - (3 - (1 + 2))");
  std::unique_ptr<ICalculatable> res = ParseInput(a);
  std::cout << res->Calculate();
  return 0;
}
