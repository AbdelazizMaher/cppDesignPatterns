#pragma once

#include <random>

class Accelometer
{
private:
	std::default_random_engine m_rEngine{ 999 };
public:
	double getHorizonatalAxis();
	double getVerticalAxis();

	virtual std::pair<int, int> Initialize();

	virtual ~Accelometer() = default;
};

