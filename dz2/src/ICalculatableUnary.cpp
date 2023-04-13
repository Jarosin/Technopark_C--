#include "ICalculatableUnary.hpp"

#include <stdexcept>

ICalculatableUnary::ICalculatableUnary(uptr_icalc var) : var_(std::move(var)) {
  if (!var_) {
    throw std::invalid_argument(
        "Unary operation requires an operator, but none were given");
  }
}

ICalculatableUnary::~ICalculatableUnary() = default;
