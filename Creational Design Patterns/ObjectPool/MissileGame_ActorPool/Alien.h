#pragma once
#include "GameActor.h"

class Alien :
    public GameActor
{
public:
	Alien();
	~Alien();

	void Update() override;
};

