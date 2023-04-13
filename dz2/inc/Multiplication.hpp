#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "ICalculatable.hpp"
#include "ICalculatableBinary.hpp"
#include "memory"
using uptr_icalc = std::unique_ptr<ICalculatable>;
class Multiplication : public ICalculatableBinary {
 public:
  using ICalculatableBinary::ICalculatableBinary;
  ~Multiplication() = default;
  double Calculate() override;
};

#endif
