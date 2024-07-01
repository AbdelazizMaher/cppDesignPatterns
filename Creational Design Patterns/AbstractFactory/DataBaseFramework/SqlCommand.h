#pragma once

#include "Command.h"

class SqlRecordSet;

class SqlCommand : public Command
{
public:
	void executeCommand() override;
	RecordSet* executeQuery() override;
};

