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

    class Builder
    {
    private:
        LPCSTR m_pFileName{};
        DWORD m_DesiredAccess{};
        DWORD m_ShareMode{};
        LPSECURITY_ATTRIBUTES m_pSecurityAttributes{};
        DWORD m_CreationDisposition{ CREATE_ALWAYS };
        DWORD m_FlagsAndAttributes{ FILE_ATTRIBUTE_NORMAL };
        HANDLE m_hTemplateFile{};
    public:
        Builder(LPCSTR pFileName, DWORD DesiredAccess)
            : m_pFileName{ pFileName }, m_DesiredAccess{ DesiredAccess } {

        }

        Builder(const Builder&) = delete;
        Builder& operator =(const Builder&) = delete;

        Builder(Builder&& other) noexcept
            : m_pFileName{ other.m_pFileName }, m_DesiredAccess{ other.m_DesiredAccess }, m_ShareMode{ other.m_ShareMode },
            m_pSecurityAttributes{ other.m_pSecurityAttributes }, m_CreationDisposition{ other.m_CreationDisposition },
            m_FlagsAndAttributes{ other.m_FlagsAndAttributes }, m_hTemplateFile{ other.m_hTemplateFile } 
        {
            other.m_pFileName = nullptr;
            other.m_DesiredAccess = 0;
            other.m_ShareMode = 0;
            other.m_pSecurityAttributes = nullptr;
            other.m_CreationDisposition = 0;
            other.m_FlagsAndAttributes = 0;
            other.m_hTemplateFile = nullptr;
        }

        Builder& operator =(Builder&& other) noexcept
        {
            if (this == &other)
                return *this;
            m_pFileName = other.m_pFileName;
            m_DesiredAccess = other.m_DesiredAccess;
            m_ShareMode = other.m_ShareMode;
            m_pSecurityAttributes = other.m_pSecurityAttributes;
            m_CreationDisposition = other.m_CreationDisposition;
            m_FlagsAndAttributes = other.m_FlagsAndAttributes;
            m_hTemplateFile = other.m_hTemplateFile;

            other.m_pFileName = nullptr;
            other.m_DesiredAccess = 0;
            other.m_ShareMode = 0;
            other.m_pSecurityAttributes = nullptr;
            other.m_CreationDisposition = 0;
            other.m_FlagsAndAttributes = 0;
            other.m_hTemplateFile = nullptr;

            return *this;
        }

        Builder& setFileName(LPCSTR pFileName)
        {
            m_pFileName = pFileName;
            return *this;
        }

        Builder& setDesiredAccess(DWORD DesiredAccess)
        {
            m_DesiredAccess = DesiredAccess;
            return *this;
        }

        Builder& setShareMode(DWORD ShareMode)
        {
            m_ShareMode = ShareMode;
            return *this;
        }

        Builder& setSecurityAttributes(LPSECURITY_ATTRIBUTES pSecurityAttributes)
        {
            m_pSecurityAttributes = pSecurityAttributes;
            return *this;
        }

        Builder& setCreationDisposition(DWORD CreationDisposition)
        {
            m_CreationDisposition = CreationDisposition;
            return *this;
        }

        Builder& setFlagsAndAttributes(DWORD FlagsAndAttributes)
        {
            m_FlagsAndAttributes = FlagsAndAttributes;
            return *this;
        }

        Builder& setTemplateFile(HANDLE hTemplateFile)
        {
            m_hTemplateFile = hTemplateFile;
            return *this;
        }

        File Build()
        {
            return File(m_pFileName, m_DesiredAccess, m_ShareMode, m_pSecurityAttributes,
                m_CreationDisposition, m_FlagsAndAttributes, m_hTemplateFile);
        }
    };
};

