#ifndef SUBSTRACTION_H
#define SUBSTRACTION_H

#include "ICalculatableBinary.hpp"

class Substraction : public ICalculatableBinary {
 public:
  using ICalculatableBinary::ICalculatableBinary;
  ~Substraction() = default;
  double Calculate() override;

 private:
};

#endif
