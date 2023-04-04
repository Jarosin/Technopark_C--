#include "ICalculatableUnary.hpp"


ICalculatableUnary::ICalculatableUnary(uptr_icalc var)
    : var_(std::move(var)){}

ICalculatableUnary::~ICalculatableUnary() = default;
