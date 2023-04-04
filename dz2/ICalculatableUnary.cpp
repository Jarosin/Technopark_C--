#include "ICalculatableUnary.hpp"


ICalculatableUnary::ICalculatableUnary(uptr_icalc var)
    : var_(std::move(var)){}
    
ICalculatableUnary::ICalculatableUnary(ICalculatableUnary &&other) : var_(std::move(other.var_))
{
    
}

ICalculatableUnary::~ICalculatableUnary() = default;
