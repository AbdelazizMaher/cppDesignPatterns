#include "MySqlRecordSet.h"

MySqlRecordSet::MySqlRecordSet() : m_Curosr{ m_sqlDB.begin() }
{
}

const std::string& MySqlRecordSet::getRow()
{
    return *m_Curosr++;
}

bool MySqlRecordSet::hasNext()
{
    return m_Curosr != m_sqlDB.end();
}
