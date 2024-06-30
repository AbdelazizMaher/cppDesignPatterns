#pragma once
#include <vector>
#include <memory>
#include "Missile.h"

using MissilePtr = std::shared_ptr<Missile>;
class MissilePool
{
private:
	inline static std::vector <MissilePtr> m_Missiles{};
	MissilePool() = default;
public:
	static MissilePtr aquireMissile();
	static void releaseMissile(const MissilePtr& releaseMissile);

};

