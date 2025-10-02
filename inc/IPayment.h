#pragma once

class IPayment 
{
public:
    virtual void process(double amount) const = 0;
    virtual ~IPayment() = default;
};
