#include "EncryptedFileBuilder.h"
#include "File.h"

void EncryptedFileBuilder::setFileName(LPCSTR pFileName)
{
	m_pFileName = pFileName;
}

void EncryptedFileBuilder::setDesiredAccess(DWORD DesiredAccess)
{
	m_DesiredAccess = DesiredAccess;
}

void EncryptedFileBuilder::setShareMode()
{
	m_ShareMode = 0;
}

void EncryptedFileBuilder::setSecurityAttributes()
{
}

void EncryptedFileBuilder::setCreationDisposition()
{
}

void EncryptedFileBuilder::setFlagsAndAttributes()
{
	m_FlagsAndAttributes = FILE_ATTRIBUTE_ENCRYPTED;
}

void EncryptedFileBuilder::setTemplateFile()
{
}

File EncryptedFileBuilder::Build()
{
	return File(m_pFileName, m_DesiredAccess, m_ShareMode, nullptr,
		CREATE_ALWAYS, m_FlagsAndAttributes, nullptr);
}
