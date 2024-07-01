#pragma once

#include <string>

class RecordSet
{
public:
	virtual const std::string& getRow() = 0;
	virtual bool hasNext() = 0;

	virtual ~RecordSet() = default;


};

