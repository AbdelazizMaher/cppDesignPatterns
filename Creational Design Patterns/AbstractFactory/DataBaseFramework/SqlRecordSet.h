#pragma once

#include <vector>
#include "RecordSet.h"

class SqlRecordSet :
    public RecordSet
{
private:
	const std::vector<std::string> m_sqlDB{
		"Al-Fatihah",
		"Al-Baqarah",
		"Al-'Imran",
		"An-Nisa'",
		"Al-Ma'idah",
		"Al-An'am"
	};
	std::vector<std::string>::const_iterator m_Curosr;
public:
	SqlRecordSet();

	const std::string& getRow() override;
	bool hasNext() override;
};

