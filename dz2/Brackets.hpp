#ifndef BRACKETS_H
#define BRACKETS_H

#pragma once
#include "ICalculatable.hpp"
#include "ICalculatableUnary.hpp"
#include "memory"
class Brackets : private ICalculatableUnary {
 public:
  using ICalculatableUnary::ICalculatableUnary;
  ~Brackets() = default;
  double Calculate() override;

 private:
};

#endif
