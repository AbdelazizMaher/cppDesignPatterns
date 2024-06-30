#pragma once

#include "GameActor.h"

class Missile : public GameActor
{
public:
	Missile();
	~Missile();

	void Update() override;
};

