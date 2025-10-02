#pragma once
#include "IPayment.h"

class CreditCardPayment : public IPayment {
public:
    void process(double amount) const override;
};
