#include "File.h"
#include <stdexcept>

File::File(LPCSTR pFileName, DWORD DesiredAccess, DWORD ShareMode, LPSECURITY_ATTRIBUTES pSecurityAttributes, DWORD CreationDisposition, DWORD FlagsAndAttributes, HANDLE hTemplateFile)
	: m_pFileName{ pFileName }, m_DesiredAccess{ DesiredAccess }, m_ShareMode{ ShareMode }, 
	m_pSecurityAttributes{ pSecurityAttributes }, m_CreationDisposition{ CreationDisposition }, 
	m_FlagsAndAttributes{ FlagsAndAttributes }, m_hTemplateFile{ hTemplateFile } {

	m_hFile = CreateFileA(pFileName, DesiredAccess, ShareMode, pSecurityAttributes, 
		CreationDisposition, FlagsAndAttributes, hTemplateFile);

	if (m_hFile == INVALID_HANDLE_VALUE)
		throw std::runtime_error{ "[ERROR]: file handle error" };
}

File::File(LPCSTR pFileName, DWORD DesiredAccess)
	: File{ pFileName, DesiredAccess, FILE_ATTRIBUTE_NORMAL } {
}

File::File(LPCSTR pFileName, DWORD DesiredAccess, DWORD FlagsAndAttributes)
	: File{ pFileName, DesiredAccess, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FlagsAndAttributes, nullptr } {
}

File::~File()
{
	if (m_hFile)
		closeFile();
}

DWORD File::readFromFile(char* pBuff, DWORD size)
{
	DWORD readData{};

	memset(pBuff, 0, size);

	if(ReadFile(m_hFile, pBuff, size - 1, &readData, nullptr) == FALSE)
		throw std::runtime_error{ "[ERROR]: Reading error" };

	return readData;
}

DWORD File::writeInFile(const char* pBuff, DWORD size)
{
	DWORD writeData{};

	if (WriteFile(m_hFile, pBuff, size, &writeData, nullptr) == FALSE)
		throw std::runtime_error{ "[ERROR]: Writing error" };

	return writeData;
}

BOOL File::isOpen() const
{
	return m_hFile != nullptr;
}

void File::closeFile()
{
	CloseHandle(m_hFile);
	m_hFile = nullptr;
}


