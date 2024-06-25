#pragma once
#include "FileBuilder.h"
class SimpleFileBuilder :
    public FileBuilder
{
private:
    LPCSTR m_pFileName{};
    DWORD m_DesiredAccess{};
public:
	virtual void setFileName(LPCSTR pFileName) override;
	virtual void setDesiredAccess(DWORD DesiredAccess) override;
	virtual void setShareMode() override;
	virtual void setSecurityAttributes() override;
	virtual void setCreationDisposition() override;
	virtual void setFlagsAndAttributes() override;
	virtual void setTemplateFile() override;

	virtual File Build() override;
};

