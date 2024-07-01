#include "DbFactory.h"
#include "SqlConnection.h"
#include "MySqlConnection.h"
#include "SqlCommand.h"
#include "MySqlCommand.h"

Connection* DbFactory::createConnection(std::string_view type)
{
    if (type == "sql")
        return new SqlConnection{};
    else if(type == "mysql")
        return new MySqlConnection{};

    return nullptr;
}

Command* DbFactory::createCommand(std::string_view type)
{
    if (type == "sql")
        return new SqlCommand{};
    else if (type == "mysql")
        return new MySqlCommand{};

    return nullptr;
}
