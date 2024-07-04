#include <iostream>
#include "Button.h"

void Button::paintComponent()
{
	if (m_isVisible)
		std::cout << "[Button] Painting..." << std::endl;
}

void Button::setVisibile(bool visible)
{
	m_isVisible = visible;

	std::cout 
		<< std::boolalpha
		<< "[Button] Visibility : " << m_isVisible 
		<< std::endl;
}

void Button::addWidget(IWidget* pWidget)
{
	throw std::runtime_error{ "Not Implemented" };
}

void Button::removeWidget(IWidget* pWidget)
{
	throw std::runtime_error{ "Not Implemented" };
}
