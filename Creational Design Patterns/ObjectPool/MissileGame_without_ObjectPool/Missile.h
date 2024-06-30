#pragma once

class Missile
{
private:
	bool m_isVisible{ true };
public:
	Missile();
	~Missile();

	bool getVisible() const;
	void setVisible(bool visible);

	void Update();
};

