#include <iostream>
#include <memory>

#include "ICalculatable.hpp"
#include "Parse.hpp"
int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Wrong amount of arguments was given" << std::endl;
    return 1;
  }
  std::string input(argv[1]);
  std::unique_ptr<ICalculatable> res;
  try {
    res = ParseInput(input);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  std::cout << res->Calculate() << std::endl;
  return 0;
}
