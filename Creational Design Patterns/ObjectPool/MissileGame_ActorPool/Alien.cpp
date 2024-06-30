#include <iostream>
#include "Alien.h"

Alien::Alien()
{
	std::cout << " +++ Alien created +++" << std::endl;
}

Alien::~Alien()
{
	std::cout << " ~~~ Alien destroyed ~~~" << std::endl;
}

void Alien::Update()
{
	std::cout << "@ ";
}