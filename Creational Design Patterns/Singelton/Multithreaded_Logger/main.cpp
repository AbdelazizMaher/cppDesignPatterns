#include <thread>
#include "Logger.h"

void openAnotherConnection()
{
	Logger& lg = Logger::Instance(Logger::SingletonType::MEYERS);

	lg.setTag("func dummy");
	lg.writeLog("Attempt to open from function");
}

int main()
{
	std::thread t1 ([]() {
		Logger& lg = Logger::Instance(Logger::SingletonType::MEYERS);

		lg.setTag("Thread1 dummy");
		lg.writeLog("Main App started....");
		});

	std::thread t2 ([]() {
		Logger& lg = Logger::Instance(Logger::SingletonType::MEYERS);

		lg.setTag("Thread2 dummy");
		lg.writeLog("Main App started....");
		});

	openAnotherConnection();

	t1.join();
	t2.join();

	return 0;
}