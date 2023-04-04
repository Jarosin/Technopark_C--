#include <iostream>

#include "ICalculatable.hpp"
#include "Number.hpp"
#include "Addition.hpp"
#include "Substraction.hpp"
#include "memory"
int main() {
    auto a = std::make_unique<Number>(Number(2));
    auto b = std::make_unique<Number>(Number(3));
    auto sub = std::make_unique<Substraction>(std::move(a), std::move(b));
    std::cout << sub->Calculate() << std::endl;
    return 0;
}
