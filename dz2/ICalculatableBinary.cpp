#include "ICalculatableBinary.hpp"

ICalculatableBinary::ICalculatableBinary(uptr_icalc var1, uptr_icalc var2)
    : var1_(std::move(var1)), var2_(std::move(var2)) {}
    
ICalculatableBinary::~ICalculatableBinary() = default;
