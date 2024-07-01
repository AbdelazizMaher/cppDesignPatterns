#pragma once

#include <string_view>

class Connection;
class Command;

class DbFactory
{
public:
	static Connection* createConnection(std::string_view type);
	static Command* createCommand(std::string_view type);
};

