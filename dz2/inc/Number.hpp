#ifndef NUMBER_H
#define NUMBER_H

#include "ICalculatable.hpp"
class Number : public ICalculatable {
 public:
  Number(double number);
  ~Number() = default;
  double Calculate() override;

 private:
  double number_;
};

#endif
