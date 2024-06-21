#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>
#include <mutex>

//#define EAGER_SINGLETON

class Logger
{
private:

	struct Deleter
	{
		void operator()(Logger *ptr)
		{
			delete ptr;
		}
	};

	FILE *m_pstream;
	std::string m_Tag;

	static std::mutex m_mtx;

#if defined(EAGER_SINGLETON)
	static Logger m_eagerInstance;
#endif
	// Logger* m_lazyInstance;
	inline static std::unique_ptr<Logger, Deleter> m_lazyInstance{ nullptr };

	Logger();
	~Logger();

public:
	Logger(const Logger&) = delete;
	Logger &operator =(const Logger&) = delete;

	enum class SingletonType : uint8_t { DCLP, CALL_ONCE, MEYERS };
	static Logger& Instance(SingletonType type);
	void writeLog(const char *pLog);
	void setTag(const char* pTag);

};

