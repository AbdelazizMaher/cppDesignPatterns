#include "SqlAbstractFactory.h"
#include "SqlConnection.h"
#include "SqlCommand.h"

Connection* SqlAbstractFactory::createConnection()
{
    return new SqlConnection{};
}

Command* SqlAbstractFactory::createCommand()
{
    return new SqlCommand{};
}
