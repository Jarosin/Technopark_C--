#include "ICalculatableBinary.hpp"

#include <stdexcept>
ICalculatableBinary::ICalculatableBinary(uptr_icalc var1, uptr_icalc var2)
    : var1_(std::move(var1)), var2_(std::move(var2)) {
  if (!var1_ || !var2_) {
    throw std::invalid_argument("Binary operation required two variables");
  }
}

ICalculatableBinary::~ICalculatableBinary() = default;

