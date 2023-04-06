#include <iostream>
#include <memory>

#include "ICalculatable.hpp"
#include "Parse.hpp"
int main() {
  std::string a("sqrt((100))");
  std::unique_ptr<ICalculatable> res = ParseInput(a);
  std::cout << res->Calculate();
  return 0;
}
