#ifndef SUBSTRACTION_H
#define SUBSTRACTION_H

#pragma once
#include "ICalculatable.hpp"
#include "ICalculatableBinary.hpp"
#include "memory"
class Substraction : public ICalculatableBinary {
 public:
  using ICalculatableBinary::ICalculatableBinary;
  ~Substraction() = default;
  double Calculate() override;

 private:
};

#endif
