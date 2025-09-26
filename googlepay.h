#pragma once
#include "payment_mode.h"

class GooglePayPayment : public IPayment 
{
public:
    void process(double amount) const override;
};
