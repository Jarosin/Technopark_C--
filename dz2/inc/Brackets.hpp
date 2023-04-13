#ifndef BRACKETS_H
#define BRACKETS_H

#include "ICalculatable.hpp"
#include "ICalculatableUnary.hpp"
#include "memory"
class Brackets : public ICalculatableUnary {
 public:
  using ICalculatableUnary::ICalculatableUnary;
  ~Brackets() = default;
  double Calculate() override;

 private:
};

#endif
