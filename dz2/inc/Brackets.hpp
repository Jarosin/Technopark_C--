#ifndef BRACKETS_H
#define BRACKETS_H

#include "ICalculatableUnary.hpp"

class Brackets : public ICalculatableUnary {
 public:
  using ICalculatableUnary::ICalculatableUnary;
  ~Brackets() = default;
  double Calculate() override;

 private:
};

#endif
