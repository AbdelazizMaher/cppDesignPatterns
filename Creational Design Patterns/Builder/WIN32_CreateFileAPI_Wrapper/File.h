#pragma once

#include <Windows.h>

class File
{
private:
    /* The name of the file: 
    A pointer to a null-terminated string that specifies the name of the file or device to be created or opened.
    */
    LPCSTR m_pFileName{};
    /* The desired access to the file: 
    This parameter can be a combination of the following values, which represent the file access modes: GENERIC_READ, GENERIC_WRITE, etc. 
    */
    DWORD m_DesiredAccess{};
    /* The share mode of the file:
    This parameter can be a combination of the following values, which represent the file share modes: FILE_SHARE_READ, FILE_SHARE_WRITE, etc.
    */
    DWORD m_ShareMode{};
    /* A pointer to a SECURITY_ATTRIBUTES structure: 
    This structure specifies a security descriptor for the new file and determines whether the handle can be inherited by child processes. 
    */
    LPSECURITY_ATTRIBUTES m_pSecurityAttributes{};
    /* The action to take on a file or device that exists or does not exist:
    This parameter must be one of the following values: CREATE_NEW, CREATE_ALWAYS, OPEN_EXISTING, etc.
     */
    DWORD m_CreationDisposition{};
    /* The file or device attributes and flags:
    This parameter can include attributes like FILE_ATTRIBUTE_NORMAL and flags like FILE_FLAG_OVERLAPPED.
     */
    DWORD m_FlagsAndAttributes{};
    /* A handle to a template file:
    This parameter is used when copying an existing file's attributes to a new file, usually set to NULL.
     */
    HANDLE m_hTemplateFile{};

    /* A handle to the file:
    This handle is used to perform operations on the file after it is opened or created.
     */
    HANDLE m_hFile{};
public:
    File(LPCSTR pFileName, DWORD DesiredAccess , DWORD ShareMode ,
        LPSECURITY_ATTRIBUTES pSecurityAttributes, DWORD CreationDisposition, 
        DWORD FlagsAndAttributes, HANDLE hTemplateFile);
    // Simple file
    File(LPCSTR pFileName, DWORD DesiredAccess);
    // File with custom attributes
    File(LPCSTR pFileName, DWORD DesiredAccess, DWORD FlagsAndAttributes);
    ~File();

    DWORD readFromFile(char* pBuff, DWORD size);
    DWORD writeInFile(const char* pBuff, DWORD size);
    BOOL isOpen() const;
    void closeFile();
};

