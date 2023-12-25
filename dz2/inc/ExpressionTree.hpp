#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <string>
#include <memory>

#include "ICalculatable.hpp"

std::unique_ptr<ICalculatable> getArg(std::string &inp);
std::unique_ptr<ICalculatable> CreateOperation(std::string &inp);
std::unique_ptr<ICalculatable> CreateTree(std::string inp);

#endif
