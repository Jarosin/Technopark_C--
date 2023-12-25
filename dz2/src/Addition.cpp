#include "Addition.hpp"

double Addition::Calculate() {
    return var1_->Calculate() + var2_->Calculate();
}
