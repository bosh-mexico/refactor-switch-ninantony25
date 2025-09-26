#include "googlePay.h"
#include <iostream>
void GooglePayPayment::process(double amount) const 
{
    std::cout << "Processing GooglePay payment of ₹" << amount << "...\n";
}
