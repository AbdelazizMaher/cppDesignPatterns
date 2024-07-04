#pragma once

#include "IWidget.h"

class Button :
    public IWidget
{
	void paintComponent() override;
	void setVisibile(bool visible) override;

	void addWidget(IWidget* pWidget) override;
	void removeWidget(IWidget* pWidget) override;
};

