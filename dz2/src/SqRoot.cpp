#include "SqRoot.hpp"

#include <cmath>

double SqRoot::Calculate() {
    return sqrt(var_->Calculate());
}
