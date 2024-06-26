#pragma once

#include <random>
#include "Input.h"

class Keyboard :
    public Input
{
private:
	std::default_random_engine m_rEngine{ 12345 };
	bool SimulateInput();
public:
	bool Up() override;
	bool Down() override;
	bool Left() override;
	bool Right() override;
};

