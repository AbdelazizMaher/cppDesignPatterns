#include <iostream>
#include "MySqlCommand.h"
#include "Connection.h"
#include "MySqlRecordSet.h"

void MySqlCommand::executeCommand()
{
	std::cout
		<< "[MySqlCommand]: Executing command "
		<< m_pConnection->getConnectionString()
		<< std::endl;
}

RecordSet* MySqlCommand::executeQuery()
{
	std::cout << "[MySqlCommand]: Executing Query " << std::endl;
	return new MySqlRecordSet{};
}
