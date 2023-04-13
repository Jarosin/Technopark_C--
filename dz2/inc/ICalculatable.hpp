#ifndef ICALCULATABLE_H
#define ICALCULATABLE_H


class ICalculatable {
 public:
  ICalculatable() = default;
  virtual ~ICalculatable() = 0;
  virtual double Calculate() = 0;

 private:
};

#endif
