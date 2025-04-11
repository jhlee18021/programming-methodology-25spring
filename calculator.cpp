#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    // TODO
    // Check for overflow/underflow
    if (b > 0 && a > std::numeric_limits<int>::max() - b) 
    {
        throw std::overflow_error("Addition overflow");
    }
    if (b < 0 && a < std::numeric_limits<int>::min() - b)
    {
        throw std::overflow_error("Addition underflow");
    }

    return a+b;

}

int Calculator::sub(int a, int b) {
    // TODO
    
    if (b < 0 && a > std::numeric_limits<int>::max() + b) 
    {
        throw std::overflow_error("Sub overflow");
    }
    if (b > 0 && a < std::numeric_limits<int>::min() + b) 
    {
        throw std::overflow_error("Sub underflow");
    }
    return a-b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if (b == 0)
    {
        return 0;
    }
    if (a > 0 && b > 0 && a > std::numeric_limits<int>::max() / b) 
    {
        throw std::overflow_error("mul overflow");
    }
    if (a < 0 && b < 0 && a > std::numeric_limits<int>::max() / b) 
    {
        throw std::overflow_error("mul overflow");
    }
    
    if (a > 0 && b < 0 && a < std::numeric_limits<int>::min() / b) 
    {
        throw std::overflow_error("mul overflow");
    }
    if (a < 0 && b > 0 && a < std::numeric_limits<int>::min() / b) 
    {
        throw std::overflow_error("mul overflow");
    }
    return a*b;
}

int Calculator::div(int a, int b) {
    // TODO
    if (b == 0)
    {
        throw std::invalid_argument("Division by zero");
    }
    
    if ((a == -1 && b == std::numeric_limits<int>::min() ) || (b == -1 && a == std::numeric_limits<int>::min() ))
    {
        throw std::overflow_error("div overflow");
    }

    return a / b;
}