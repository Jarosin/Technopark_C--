#include "SqRoot.hpp"
#include <cmath>
// TODO: здесь возможен sqrt(negative), и нужно решить, отпускать ли ошибку
// дальше или обработать мне
double SqRoot::Calculate() { return sqrt(var_->Calculate()); }
