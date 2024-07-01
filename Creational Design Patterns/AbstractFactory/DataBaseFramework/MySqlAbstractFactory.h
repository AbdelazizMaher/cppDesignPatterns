#pragma once

#include "DbAbstractFactory.h"

class MySqlAbstractFactory :
    public DbAbstractFactory
{
public:
	Connection* createConnection() override;
	Command* createCommand() override;
};

