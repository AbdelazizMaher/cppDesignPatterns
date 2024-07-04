#pragma once

#include <vector>
#include "IWidget.h"

class Frame :
    public IWidget
{
private:
	std::vector<IWidget*> m_pChildern{};
public:
	void paintComponent() override;
	void setVisibile(bool visible) override;

	void addWidget(IWidget* pWidget) override;
	void removeWidget(IWidget* pWidget) override;
	IWidget* getFrame() override { return this; }

	~Frame();
};

