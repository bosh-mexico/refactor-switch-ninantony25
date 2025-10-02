#include <iostream>
#include <cassert>
#include "paypal.h"
#include "googlepay.h"
#include "CreditCardPayment.h"
#include "PaymentFactory.h"
#include "CheckoutProcessor.h"

void testPayPalPayment() 
{
    PayPalPayment paypal;
    std::cout << "Testing PayPalPayment..." << std::endl;
    paypal.process(100.0);   // Expected output: Processing PayPal payment of ₹100.0...
}

void testGooglePayPayment() 
{
    GooglePayPayment gpay;
    std::cout << "Testing GooglePayPayment..." << std::endl;
    gpay.process(200.0);     // Expected output: Processing GooglePay payment of ₹200.0...
}

void testCreditCardPayment() 
{
    CreditCardPayment cc;
    std::cout << "Testing CreditCardPayment..." << std::endl;
    cc.process(300.0);       // Expected output: Processing CreditCard payment of ₹300.0...
}

void testPaymentFactory() 
{
    std::cout << "Testing PaymentFactory..." << std::endl;

    auto paypal = PaymentFactory::createPayment("PayPal");
    assert(paypal != nullptr);
    paypal->process(150.0);

    auto gpay = PaymentFactory::createPayment("GooglePay");
    assert(gpay != nullptr);
    gpay->process(250.0);

    auto cc = PaymentFactory::createPayment("CreditCard");
    assert(cc != nullptr);
    cc->process(350.0);

    auto invalid = PaymentFactory::createPayment("Bitcoin");
    assert(invalid == nullptr);
}

void testCheckoutProcessor() 
{
    std::cout << "Testing CheckoutProcessor..." << std::endl;
    CheckoutProcessor processor;
    processor.checkout("PayPal", 500.0);
    processor.checkout("GooglePay", 600.0);
    processor.checkout("CreditCard", 700.0);
    processor.checkout("Bitcoin", 800.0); // Expected error message
}

int main()
{
    testPayPalPayment();
    testGooglePayPayment();
    testCreditCardPayment();
    testPaymentFactory();
    testCheckoutProcessor();

    std::cout << "All tests completed." << std::endl;
    return 0;
}
