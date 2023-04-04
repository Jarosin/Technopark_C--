#ifndef ADDITION_H
#define ADDITION_H

#pragma once
#include "ICalculatable.hpp"
#include "ICalculatableBinary.hpp"
#include "memory"
using uptr_icalc = std::unique_ptr<ICalculatable>;
class Addition : public ICalculatableBinary {
 public:
  using ICalculatableBinary::ICalculatableBinary;
  ~Addition() = default;
  double Calculate() override;
};

#endif
