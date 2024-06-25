#include <iostream>
#include "File.h"

int main()
{
	SECURITY_ATTRIBUTES secATTR{};

	File::Builder fileBuilder("main.cpp", FILE_GENERIC_READ);
	auto file = fileBuilder.setFlagsAndAttributes(FILE_ATTRIBUTE_NORMAL)
		.setCreationDisposition(OPEN_EXISTING)
		.setShareMode(FILE_SHARE_READ)
		.setSecurityAttributes(&secATTR)
		.Build();

	constexpr int SIZE{ 1024 };
	char BUFF[SIZE]{};

	file.readFromFile(BUFF, SIZE);
	std::cout << BUFF;

	return 0;
}