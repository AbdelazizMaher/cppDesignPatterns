#include <iostream>
#include <thread>
#include "Input.h"
#include "Keyboard.h"
#include "AccelAdapter.h"

void Game(Input* pInput)
{
	int count{ 5 };

	while (count != 0)
	{
		using namespace std::chrono_literals;

		std::cout << "=============================" << std::endl;

		if (pInput->Up())
		{
			std::cout << "Pitch Up" << std::endl;
		}
		else if (pInput->Down())
		{
			std::cout << "Pitch down" << std::endl;
		}
		else
		{
			std::cout << "Plane is level" << std::endl;
		}

		if (pInput->Left())
		{
			std::cout << "Plane is turning left" << std::endl;
		}
		else if (pInput->Right())
		{
			std::cout << "Plane is turning right" << std::endl;
		}
		else
		{
			std::cout << "Plane is heading straight" << std::endl;
		}

		std::this_thread::sleep_for(1s);
		count--;
	}

}

int main()
{
	//Keyboard key;
	AccelAdapter key;

	Game(&key);

	return 0;
}
