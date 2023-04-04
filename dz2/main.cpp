#include <iostream>
#include <memory>

#include "Addition.hpp"
#include "Brackets.hpp"
#include "Ceil.hpp"
#include "ICalculatable.hpp"
#include "ICalculatableBinary.hpp"
#include "ICalculatableUnary.hpp"
#include "Multiplication.hpp"
#include "Number.hpp"
#include "SqRoot.hpp"
#include "Substraction.hpp"

int main() {
  auto a = std::make_unique<Number>(Number(2.5));
  auto b = std::make_unique<Number>(Number(3.1));
  auto sub = std::make_unique<Multiplication>(std::move(a), std::move(b));
  auto br = std::make_unique<Brackets>(std::move(sub));
  auto ceil = std::make_unique<Ceil>(std::move(br));
  std::cout << ceil->Calculate() << std::endl;
  return 0;
}
