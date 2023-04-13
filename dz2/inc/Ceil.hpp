#ifndef CEIL_H
#define CEIL_H

#include "ICalculatable.hpp"
#include "ICalculatableUnary.hpp"
#include "memory"
class Ceil : public ICalculatableUnary {
 public:
  using ICalculatableUnary::ICalculatableUnary;
  ~Ceil() = default;
  double Calculate() override;

 private:
};
#endif
