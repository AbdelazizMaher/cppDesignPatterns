#include <iostream>
#include "MissilePool.h"

MissilePtr MissilePool::aquireMissile()
{
    for (auto& missile : m_Missiles)
    {
        if (!missile->getVisible())
        {
            std::cout << "[POOL]: Returning an existing instance" << std::endl;

            missile->setVisible(true);
            return missile;
        }
    }

    std::cout << "[POOL]: Creating a new instance" << std::endl;

    auto missile = std::make_shared<Missile>();
    m_Missiles.push_back(missile);

    return missile;
}

void MissilePool::releaseMissile(const MissilePtr& releaseMissile)
{
    for (auto& missile : m_Missiles)
    {
        if (missile == releaseMissile)
            missile->setVisible(false);
        break;
    }
}
