#include <iostream>
#include <memory>

#include "Addition.hpp"
#include "Brackets.hpp"
#include "ICalculatable.hpp"
#include "ICalculatableBinary.hpp"
#include "ICalculatableUnary.hpp"
#include "Number.hpp"
#include "Substraction.hpp"
int main() {
  auto a = std::make_unique<Number>(Number(2));
  auto b = std::make_unique<Number>(Number(3));
  auto sub = std::make_unique<Substraction>(std::move(a), std::move(b));
  auto br = std::make_unique<Brackets>(std::move(sub));
  std::cout << br->Calculate() << std::endl;
  return 0;
}
