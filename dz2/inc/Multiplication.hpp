#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H


#include "ICalculatableBinary.hpp"

class Multiplication : public ICalculatableBinary {
 public:
  using ICalculatableBinary::ICalculatableBinary;
  ~Multiplication() = default;
  double Calculate() override;
};

#endif
