#include "AccelAdapter.h"

bool AccelAdapter::Up()
{
    return m_Accelo.getVerticalAxis() > 0;
}

bool AccelAdapter::Down()
{
    return m_Accelo.getVerticalAxis() < 0;
}

bool AccelAdapter::Left()
{
    return m_Accelo.getHorizonatalAxis() < 0;
}

bool AccelAdapter::Right()
{
    return m_Accelo.getHorizonatalAxis() > 0;
}


