#pragma once

class Connection;
class Command;

class DbAbstractFactory
{
public:
	virtual Connection* createConnection() = 0;
	virtual Command* createCommand() = 0;

	virtual ~DbAbstractFactory() = default;
};

