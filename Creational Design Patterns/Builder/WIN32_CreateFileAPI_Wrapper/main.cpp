#include <iostream>
#include "File.h"

void Read() {
	File file{ "main.cpp", GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr };

	if (!file.isOpen())
	{
		std::cout << "can't open file" << std::endl;
		return;
	}

	constexpr int SIZE{ 100 };
	char Buffer[SIZE]{};

	while (file.readFromFile(Buffer, SIZE) != 0)
		std::cout << Buffer;
}

void Write() {
	File file{ "dummy.txt", GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr };

	if (!file.isOpen())
	{
		std::cout << "can't open file" << std::endl;
		return;
	}

	auto str = "Writing dummy data ...";

	file.writeInFile(str, strlen(str));
}
int main()
{
	Write();


	return 0;
}