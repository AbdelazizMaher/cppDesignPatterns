#include "Missile.h"
#include <iostream>

Missile::Missile()
{
	std::cout << " +++ Missle created +++" << std::endl;
}

Missile::~Missile()
{
	std::cout << " ~~~ Missle destroyed ~~~" << std::endl;
}

void Missile::Update()
{
	std::cout << "-> ";
}
