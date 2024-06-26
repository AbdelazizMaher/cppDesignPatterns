#include <iostream>
#include "Accelometer.h"

double Accelometer::getHorizonatalAxis()
{
    auto init_values = Initialize();
    std::uniform_int_distribution<> m_distribution{ init_values.first,init_values.second };

    auto value = m_distribution( m_rEngine );
    std::cout << "[Horizontal]: " << value << std::endl;

    return value;
}

double Accelometer::getVerticalAxis()
{
    auto init_values = Initialize();
    std::uniform_int_distribution<> m_distribution{ init_values.first,init_values.second };

    auto value = m_distribution( m_rEngine );
    std::cout << "[Vertical]: " << value << std::endl;

    return value;
}

std::pair<int, int> Accelometer::Initialize()
{
    return {-10,10};
}
