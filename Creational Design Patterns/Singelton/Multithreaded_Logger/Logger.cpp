#include "Logger.h"

#if defined(EAGER_SINGLETON)
Logger Logger::m_eagerInstance{};
#endif
//Logger* Logger::m_lazyInstance{nullptr};
std::mutex Logger::m_mtx;

Logger::Logger()
{
	std::cout << __FUNCSIG__ << std::endl;
	m_pstream = fopen("applog.txt", "w");
	/* atexit([]() {
		delete m_lazyInstance;
		}); */
}

Logger::~Logger()
{
	std::cout << __FUNCSIG__ << std::endl;
	fclose(m_pstream);
}

std::once_flag fg;
Logger& Logger::Instance(SingletonType type)
{
#if defined(EAGER_SINGLETON)
	return m_eagerInstance;
#endif

	switch (type)
	{
	case SingletonType::DCLP:
	{
		// Double Checked locking pattern
		if (m_lazyInstance == nullptr) {
			m_mtx.lock();
			if (m_lazyInstance == nullptr)
				m_lazyInstance.reset(new Logger());
			m_mtx.unlock();
		}
		return *m_lazyInstance;
	}
	case SingletonType::CALL_ONCE:
	{
		std::call_once(fg, []() {
			m_lazyInstance.reset(new Logger());
			});
		return *m_lazyInstance;
	}
	case SingletonType::MEYERS:
	default:
	{
		// Meyer's singelton
		static Logger meyerSingelton{};
		return meyerSingelton;
	}
	}
}

void Logger::writeLog(const char* pLog)
{
	fprintf(m_pstream, "[%s]: %s\n", m_Tag.c_str(), pLog);
	fflush(m_pstream);
}

void Logger::setTag(const char* pTag)
{
	m_Tag = pTag;
}
