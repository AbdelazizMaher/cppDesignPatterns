#pragma once

#include "Command.h"

class MySqlCommand :
    public Command
{
public:
	void executeCommand() override;
	RecordSet* executeQuery() override;
};

