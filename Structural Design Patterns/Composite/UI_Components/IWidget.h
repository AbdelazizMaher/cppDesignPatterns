#pragma once

class IWidget
{
private:
	IWidget* m_pParent{};
protected:
	bool m_isVisible{ true };
public:
	void setParent(IWidget* parent)
	{
		m_pParent = parent;
	}
	IWidget* getParent() { return m_pParent; }

	virtual void paintComponent() = 0;
	virtual void setVisibile(bool visible) = 0;

	virtual void addWidget(IWidget* pWidget) = 0;
	virtual void removeWidget(IWidget* pWidget) = 0;
	virtual IWidget* getFrame() { return nullptr; }

	virtual ~IWidget() = default;
};

