#pragma once

#include <Windows.h>
class File;

class FileBuilder
{
public:
	virtual void setFileName(LPCSTR pFileName) = 0;
	virtual void setDesiredAccess(DWORD DesiredAccess) = 0;
	virtual void setShareMode() = 0;
	virtual void setSecurityAttributes() = 0;
	virtual void setCreationDisposition() = 0;
	virtual void setFlagsAndAttributes() = 0;
	virtual void setTemplateFile() = 0;

	virtual File Build() = 0;

	virtual ~FileBuilder() = default;

};

