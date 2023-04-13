#ifndef CEIL_H
#define CEIL_H

#include "ICalculatableUnary.hpp"

class Ceil : public ICalculatableUnary {
 public:
  using ICalculatableUnary::ICalculatableUnary;
  ~Ceil() = default;
  double Calculate() override;

 private:
};
#endif
