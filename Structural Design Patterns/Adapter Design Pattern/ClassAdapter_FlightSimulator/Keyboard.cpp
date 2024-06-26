#include "Keyboard.h"

bool Keyboard::SimulateInput()
{
    std::bernoulli_distribution distribution{ 0.5 };
    return distribution(m_rEngine);
}

bool Keyboard::Up()
{
    return SimulateInput();
}

bool Keyboard::Down()
{
    return SimulateInput();
}

bool Keyboard::Left()
{
    return SimulateInput();
}

bool Keyboard::Right()
{
    return SimulateInput();
}
