#include "SqlRecordSet.h"

SqlRecordSet::SqlRecordSet() : m_Curosr{ m_sqlDB.begin() }
{

}

const std::string& SqlRecordSet::getRow()
{
    return *m_Curosr++;
}

bool SqlRecordSet::hasNext()
{
    return m_Curosr != m_sqlDB.end();
}
