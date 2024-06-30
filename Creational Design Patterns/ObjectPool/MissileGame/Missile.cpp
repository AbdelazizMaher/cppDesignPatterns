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

bool Missile::getVisible() const
{
	return m_isVisible;
}

void Missile::setVisible(bool visible)
{
	m_isVisible = visible;
}

void Missile::Update()
{
	std::cout << "-> ";
}
