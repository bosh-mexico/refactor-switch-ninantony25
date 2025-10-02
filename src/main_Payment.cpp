#include "CheckoutProcessor.h"

int main() 
{
    CheckoutProcessor processor;
    processor.checkout("GooglePay", 1500.00);
    processor.checkout("Bitcoin", 2000.00); // Invalid mode
    return 0;
}
