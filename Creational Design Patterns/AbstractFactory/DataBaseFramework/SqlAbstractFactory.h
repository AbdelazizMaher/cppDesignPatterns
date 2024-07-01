#pragma once

#include "DbAbstractFactory.h"

class SqlAbstractFactory :
    public DbAbstractFactory
{
public:
	Connection* createConnection() override;
	Command* createCommand() override;
};

