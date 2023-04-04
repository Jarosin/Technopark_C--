#include <string.h>

#include <exception>
#include <iostream>
#include <memory>
#include <regex>

#include "Addition.hpp"
#include "Brackets.hpp"
#include "Ceil.hpp"
#include "ICalculatable.hpp"
#include "ICalculatableBinary.hpp"
#include "ICalculatableUnary.hpp"
#include "Multiplication.hpp"
#include "Number.hpp"
#include "SqRoot.hpp"
#include "Substraction.hpp"
std::unique_ptr<ICalculatable> getArg(std::string &inp);
std::unique_ptr<ICalculatable> ParseInput(std::string &inp);
std::unique_ptr<ICalculatable> CalculateOperation(std::string &inp);
