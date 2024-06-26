#include "AccelAdapter.h"

bool AccelAdapter::Up()
{
    return getVerticalAxis() > 0;
}

bool AccelAdapter::Down()
{
    return getVerticalAxis() < 0;
}

bool AccelAdapter::Left()
{
    return getHorizonatalAxis() < 0;
}

bool AccelAdapter::Right()
{
    return getHorizonatalAxis() > 0;
}

std::pair<int, int> AccelAdapter::Initialize()
{
    return { -1,1 };
}