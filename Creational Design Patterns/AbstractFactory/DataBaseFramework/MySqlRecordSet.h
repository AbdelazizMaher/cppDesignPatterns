#pragma once

#include <vector>
#include "RecordSet.h"

class MySqlRecordSet :
    public RecordSet
{
private:
	const std::vector<std::string> m_sqlDB{
		"Juz'1",
		"Juz'2",
		"Juz'3",
		"Juz'4",
		"Juz'5"
	};
	std::vector<std::string>::const_iterator m_Curosr;
public:
	MySqlRecordSet();

	const std::string& getRow() override;
	bool hasNext() override;
};

