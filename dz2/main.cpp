#include <iostream>

#include "ICalculatable.hpp"
#include "Number.hpp"
#include "Addition.hpp"
#include "memory"
int main() {
    auto a = std::make_unique<Number>(Number(2));
    auto b = std::make_unique<Number>(Number(3));
    Addition add(std::move(a), std::move(b));
    std::cout << add.Calculate() << std::endl;
    return 0;
}
