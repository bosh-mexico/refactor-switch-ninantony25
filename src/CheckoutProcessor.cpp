#include "CheckoutProcessor.h"
#include "PaymentFactory.h"
#include <iostream>

void CheckoutProcessor::checkout(const std::string& mode, double amount)
{
    auto payment = PaymentFactory::createPayment(mode);
    if (payment) 
    {
        payment->process(amount);
    } 
    else
    {
        std::cout << "Error: Unsupported or invalid payment mode.\n";
    }
}
