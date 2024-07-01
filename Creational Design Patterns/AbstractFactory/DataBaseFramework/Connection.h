#pragma once
#include <string>

class Connection
{
private:
	std::string m_connectionString{};
public:
	void setConnectionString(const std::string& setStr)
	{
		m_connectionString = setStr;
	}

	const std::string& getConnectionString() const
	{
		return m_connectionString;
	}

	virtual void openConnection() = 0;
	virtual ~Connection() = default;
};

