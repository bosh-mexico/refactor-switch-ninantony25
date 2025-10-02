#include "PaymentFactory.h"
#include "PayPalPayment.h"
#include "GooglePayPayment.h"
#include "CreditCardPayment.h"

std::unique_ptr<IPayment> PaymentFactory::createPayment(const std::string& mode)
{
    if (mode == "PayPal") return std::make_unique<PayPalPayment>();
    if (mode == "GooglePay") return std::make_unique<GooglePayPayment>();
    if (mode == "CreditCard") return std::make_unique<CreditCardPayment>();
    return nullptr;
}
