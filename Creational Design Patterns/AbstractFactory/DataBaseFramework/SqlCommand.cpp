#include <iostream>
#include "SqlCommand.h"
#include "Connection.h"
#include "SqlRecordSet.h"

void SqlCommand::executeCommand()
{
	std::cout 
		<< "[SqlCommand]: Executing command "
		<< m_pConnection->getConnectionString()
		<< std::endl;
}

RecordSet* SqlCommand::executeQuery()
{
	std::cout << "[SqlCommand]: Executing Query " << std::endl;
	return new SqlRecordSet{};
}
