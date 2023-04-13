#ifndef ADDITION_H
#define ADDITION_H

#include "ICalculatableBinary.hpp"

class Addition : public ICalculatableBinary {
 public:
  using ICalculatableBinary::ICalculatableBinary;
  ~Addition() = default;
  double Calculate() override;
};

#endif
