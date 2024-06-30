#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include "Missile.h"

std::vector<std::shared_ptr<Missile>> missiles;

void Fire()
{
	missiles.push_back(std::make_shared<Missile>());
	missiles.push_back(std::make_shared<Missile>());
}

void Animate()
{
	for (auto& missile : missiles)
		missile->Update();
}

void Explode()
{
	std::cout << " X\n" << std::endl;

	for (auto& missile : missiles)
		missile->setVisible(false);

	missiles.clear();
	std::cout << " \n\n";
}

void GameLoop()
{
	using namespace std::chrono_literals;
	int count{};

	while (true)
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
		}

		std::this_thread::sleep_for(1s);
	}
}

int main()
{
	GameLoop();

	return 0;
}