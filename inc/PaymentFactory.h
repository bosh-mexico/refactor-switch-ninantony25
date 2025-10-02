#pragma once
#include <memory>
#include <string>
#include "IPayment.h"

class PaymentFactory
{
public:
    static std::unique_ptr<IPayment> createPayment(const std::string& mode);
};
