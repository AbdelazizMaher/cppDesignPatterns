#pragma once

#include "Input.h"
#include "Accelometer.h"

class AccelAdapter :
    public Input, Accelometer
{
public:
	bool Up() override;
	bool Down() override;
	bool Left() override;
	bool Right() override;

	std::pair<int, int> Initialize() override;
};

