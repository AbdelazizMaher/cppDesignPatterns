#pragma once

#include <Windows.h>

class FileBuilder;

class Director
{
private:
	FileBuilder* m_pFileBuilder{};
public:
	Director(FileBuilder* builder);

	void Create(LPCSTR pFileName, DWORD DesiredAccess);
};

