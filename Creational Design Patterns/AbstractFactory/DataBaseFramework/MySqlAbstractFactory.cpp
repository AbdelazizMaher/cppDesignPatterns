#include "MySqlAbstractFactory.h"
#include "MySqlConnection.h"
#include "MySqlCommand.h"

Connection* MySqlAbstractFactory::createConnection()
{
    return new MySqlConnection{};
}

Command* MySqlAbstractFactory::createCommand()
{
    return new MySqlCommand{};
}