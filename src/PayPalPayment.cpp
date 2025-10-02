#include "paypal.h"
#include <iostream>

void PayPalPayment::process(double amount) const 
{
    std::cout << "Processing PayPal payment of ₹" << amount << "...\n";
}
