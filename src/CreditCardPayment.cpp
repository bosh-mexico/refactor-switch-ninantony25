#include "CreditCardPayment.h"
#include <iostream>

void CreditCardPayment::process(double amount) const 
{
    std::cout << "Processing CreditCard payment of ₹" << amount << "...\n";
}
