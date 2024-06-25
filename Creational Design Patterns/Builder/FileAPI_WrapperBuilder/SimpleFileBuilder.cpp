#include "SimpleFileBuilder.h"
#include "File.h"

void SimpleFileBuilder::setFileName(LPCSTR pFileName)
{
	m_pFileName = pFileName;
}

void SimpleFileBuilder::setDesiredAccess(DWORD DesiredAccess)
{
	m_DesiredAccess = DesiredAccess;
}

void SimpleFileBuilder::setShareMode()
{
}

void SimpleFileBuilder::setSecurityAttributes()
{
}

void SimpleFileBuilder::setCreationDisposition()
{
}

void SimpleFileBuilder::setFlagsAndAttributes()
{
}

void SimpleFileBuilder::setTemplateFile()
{
}

File SimpleFileBuilder::Build()
{
	return File(m_pFileName, m_DesiredAccess, FILE_SHARE_READ, nullptr, 
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
}
