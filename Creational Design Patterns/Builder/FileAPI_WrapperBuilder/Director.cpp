#include "Director.h"
#include "FileBuilder.h"

Director::Director(FileBuilder* builder) : m_pFileBuilder{builder}
{

}

void Director::Create(LPCSTR pFileName, DWORD DesiredAccess)
{
	m_pFileBuilder->setFileName(pFileName);
	m_pFileBuilder->setDesiredAccess(DesiredAccess);
	m_pFileBuilder->setShareMode();
	m_pFileBuilder->setSecurityAttributes();
	m_pFileBuilder->setCreationDisposition();
	m_pFileBuilder->setFlagsAndAttributes();
	m_pFileBuilder->setTemplateFile();
}
