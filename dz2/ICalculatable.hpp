#ifndef ICALCULATABLE_H
#define ICALCULATABLE_H

#pragma once

class ICalculatable
{
public:
    ICalculatable();
    virtual ~ICalculatable() = 0;
    virtual double Calculate() = 0;
private:
};

#endif
