#include "SimpleFileBuilder.h"
#include "EncryptedFileBuilder.h"
#include "Director.h"
#include "File.h"
#include <utility>

int main()
{
	SimpleFileBuilder builder{};
	//EncryptedFileBuilder builder{};
	Director director{ &builder };

	director.Create("myfile.txt", FILE_GENERIC_WRITE);
	File file{ std::move(builder.Build()) };

	file.writeInFile("testing handle...", 17);


	return 0;
}