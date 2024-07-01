#pragma once

#include "Connection.h"

class SqlConnection :
    public Connection
{
public:
    void openConnection() override;
};

