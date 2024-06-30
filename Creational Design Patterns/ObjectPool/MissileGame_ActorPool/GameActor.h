#pragma once

class GameActor
{
private:
	bool m_isVisible{ true };
public:
	virtual ~GameActor() = default;

	virtual void Update() = 0;

	bool getVisible() const
	{
		return m_isVisible;
	}

	void setVisible(bool visible)
	{
		m_isVisible = visible;
	}

};

