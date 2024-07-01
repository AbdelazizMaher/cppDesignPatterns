#pragma once
#include <string>

class Connection;
class RecordSet;

class Command
{
private:
	std::string m_commandString{};
protected:
	Connection* m_pConnection{};
public:
	void setCommandString(const std::string& setStr)
	{
		m_commandString = setStr;
	}

	const std::string& getCommandString() const
	{
		return m_commandString;
	}

	void setConnection(Connection* pConnect)
	{
		m_pConnection = pConnect;
	}

	Connection* getConnection()
	{
		return m_pConnection;
	}

	virtual void executeCommand() = 0;
	virtual RecordSet* executeQuery() = 0;

	virtual ~Command() = default;
};

