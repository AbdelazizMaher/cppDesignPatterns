#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include "GameActorPool.h"
#include "Missile.h"
#include "Alien.h"

std::vector<std::shared_ptr<GameActor>> GameActors;

void Fire()
{
	GameActors.push_back(GameActorPool::aquireActor("missile"));
	GameActors.push_back(GameActorPool::aquireActor("alien"));
}

void Animate()
{
	for (auto& actor : GameActors)
		actor->Update();
}

void Explode()
{
	std::cout << " X\n" << std::endl;

	for (auto& actor : GameActors)
		actor->setVisible(false);

	GameActors.clear();
	std::cout << " \n\n";
}

void GameLoop()
{
	using namespace std::chrono_literals;
	int count{}, loop{ 2 };

	while (loop != 0)
	{
		++count;

		if (count == 1)
		{
			Fire();
		}
		if (count >= 1 && count <= 5)
		{
			Animate();
		}
		if (count > 5)
		{
			Explode();
			count = 0;
			--loop;
		}

		std::this_thread::sleep_for(1s);
	}
}

int main()
{
	//GameActorPool::registerCreator("missile", []() {
	//	return std::make_shared<Missile>();
	//	});
	GameActorPool::registerCreator("alien", []() {
		return std::make_shared<Alien>();
		});

	GameLoop();

	return 0;
}