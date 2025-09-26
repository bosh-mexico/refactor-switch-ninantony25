#pragma once
#include "payment_mode.h"

class PayPalPayment : public IPayment {
public:
    void process(double amount) const override;
};
