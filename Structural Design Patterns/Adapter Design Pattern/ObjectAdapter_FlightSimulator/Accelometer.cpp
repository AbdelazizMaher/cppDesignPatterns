#include <iostream>
#include "Accelometer.h"

double Accelometer::getHorizonatalAxis()
{
    auto value = m_distribution( m_rEngine );
    std::cout << "[Horizontal]: " << value << std::endl;

    return value;
}

double Accelometer::getVerticalAxis()
{
    auto value = m_distribution( m_rEngine );
    std::cout << "[Vertical]: " << value << std::endl;

    return value;
}
