#ifndef ICALCULATABLEBINARY_H
#define ICALCULATABLEBINARY_H

#pragma once
#include "ICalculatable.hpp"
#include "memory"
using uptr_icalc = std::unique_ptr<ICalculatable>;
class ICalculatableBinary : public ICalculatable {
 public:
 
  ICalculatableBinary(uptr_icalc var1, uptr_icalc var2);
  virtual ~ICalculatableBinary() = 0;

 protected:
  uptr_icalc var1_, var2_;
};

#endif
