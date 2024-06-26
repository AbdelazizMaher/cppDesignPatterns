#pragma once

#include "Input.h"
#include "Accelometer.h"

class AccelAdapter :
    public Input
{
private:
	Accelometer m_Accelo;
public:
	bool Up() override;
	bool Down() override;
	bool Left() override;
	bool Right() override;
};

