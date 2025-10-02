#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "paypal.h"
#include "googlepay.h"
#include "CreditCardPayment.h"
#include "PaymentFactory.h"
#include "CheckoutProcessor.h"

// Helper function to capture std::cout output
std::string captureOutput(std::function<void()> func) 
{
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    func();
    std::cout.rdbuf(old);
    return buffer.str();
}

// Test PayPalPayment
TEST(PaymentTests, PayPalProcess) 
{
    PayPalPayment paypal;
    std::string output = captureOutput(& { paypal.process(100.0); });
    EXPECT_EQ(output, "Processing PayPal payment of ₹100.0...\n");
}

// Test GooglePayPayment
TEST(PaymentTests, GooglePayProcess) 
{
    GooglePayPayment gpay;
    std::string output = captureOutput(& { gpay.process(200.0); });
    EXPECT_EQ(output, "Processing GooglePay payment of ₹200.0...\n");
}

// Test CreditCardPayment
TEST(PaymentTests, CreditCardProcess) 
{
    CreditCardPayment cc;
    std::string output = captureOutput(& { cc.process(300.0); });
    EXPECT_EQ(output, "Processing CreditCard payment of ₹300.0...\n");
}

// Test PaymentFactory valid modes
TEST(PaymentFactoryTests, ValidModes) 
{
    auto paypal = PaymentFactory::createPayment("PayPal");
    EXPECT_NE(paypal, nullptr);
    auto gpay = PaymentFactory::createPayment("GooglePay");
    EXPECT_NE(gpay, nullptr);
    auto cc = PaymentFactory::createPayment("CreditCard");
    EXPECT_NE(cc, nullptr);
}

// Test PaymentFactory invalid mode
TEST(PaymentFactoryTests, InvalidMode) 
{
    auto invalid = PaymentFactory::createPayment("Bitcoin");
    EXPECT_EQ(invalid, nullptr);
}

// Test CheckoutProcessor with valid and invalid modes
TEST(CheckoutProcessorTests, CheckoutFlow) 
{
    CheckoutProcessor processor;

    std::string output1 = captureOutput(& { processor.checkout("PayPal", 500.0); });
    EXPECT_EQ(output1, "Processing PayPal payment of ₹500.0...\n");

    std::string output2 = captureOutput(& { processor.checkout("GooglePay", 600.0); });
    EXPECT_EQ(output2, "Processing GooglePay payment of ₹600.0...\n");

    std::string output3 = captureOutput([ { processor.checkout("CreditCard", 700.0); });
    EXPECT_EQ(output3, "Processing CreditCard payment of ₹700.0...\n");

    std::string output4 = captureOutput(& { processor.checkout("Bitcoin", 800.0); });
    EXPECT_EQ(output4, "Error: Unsupported or invalid payment mode.\n");
}

// Main function for running all tests
int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

