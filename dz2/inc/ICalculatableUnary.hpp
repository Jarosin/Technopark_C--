#ifndef ICALCULATABLEUNARY_H
#define ICALCULATABLEUNARY_H

#pragma once
#include "ICalculatable.hpp"
#include "memory"
using uptr_icalc = std::unique_ptr<ICalculatable>;
class ICalculatableUnary : public ICalculatable {
 public:
  ICalculatableUnary(uptr_icalc var);
  virtual ~ICalculatableUnary() = 0;

 protected:
  uptr_icalc var_;
};

#endif

