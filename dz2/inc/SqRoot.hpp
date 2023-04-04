#ifndef SQROOT_H
#define SQROOT_H

#pragma once

#include "ICalculatable.hpp"
#include "ICalculatableUnary.hpp"
#include "memory"
class SqRoot : public ICalculatableUnary {
 public:
  using ICalculatableUnary::ICalculatableUnary;
  ~SqRoot() = default;
  double Calculate() override;

 private:
};

#endif
