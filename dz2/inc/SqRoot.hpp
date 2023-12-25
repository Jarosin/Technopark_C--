#ifndef SQROOT_H
#define SQROOT_H

#include "ICalculatableUnary.hpp"

class SqRoot : public ICalculatableUnary {
 public:
  using ICalculatableUnary::ICalculatableUnary;
  ~SqRoot() = default;
  double Calculate() override;

 private:
};

#endif
