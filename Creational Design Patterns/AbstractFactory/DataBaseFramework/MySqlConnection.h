#pragma once

#include "Connection.h"

class MySqlConnection :
    public Connection
{
public:
    void openConnection() override;
};

