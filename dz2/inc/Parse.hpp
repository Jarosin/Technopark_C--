#ifndef PARSE_H
#define PARSE_H
#include <string.h>

#include <memory>

#include "ICalculatable.hpp"

std::unique_ptr<ICalculatable> getArg(std::string &inp);
std::unique_ptr<ICalculatable> ParseInput(std::string inp);
std::unique_ptr<ICalculatable> CreateOperation(std::string &inp);

#endif
