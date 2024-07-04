#include "Frame.h"
#include <iostream>

int depth{};

void Frame::paintComponent()
{
	if (!m_isVisible)
		return;

	std::cout << "[Frame] Painting... " << std::endl;

	++depth;
	for (auto child : m_pChildern)
	{
		for (int i = 0; i < depth; i++)
			std::cout << "\t";
		child->paintComponent();
	}
	--depth;
}

void Frame::setVisibile(bool visible)
{
	m_isVisible = visible;
	std::cout << "[Frame] Changing visibility " << std::endl;

	++depth;
	for (auto child : m_pChildern)
	{
		for (int i = 0; i < depth; i++)
			std::cout << "\t";
		child->setVisibile(visible);
	}
	--depth;
}

void Frame::addWidget(IWidget* pWidget)
{
	m_pChildern.emplace_back(pWidget);
	pWidget->setParent(this);
}

void Frame::removeWidget(IWidget* pWidget)
{
	pWidget->setParent(nullptr);

	m_pChildern.erase(
		std::remove(std::begin(m_pChildern), std::end(m_pChildern),
			pWidget), 
		std::end(m_pChildern));
}

Frame::~Frame()
{
	for (auto child : m_pChildern)
		delete child;

}
