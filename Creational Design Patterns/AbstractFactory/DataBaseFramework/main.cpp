#include <iostream>
#include "SqlConnection.h"
#include "MySqlConnection.h"
#include "SqlCommand.h"
#include "MySqlCommand.h"
#include "RecordSet.h"
#include "DbFactory.h"
#include "DbAbstractFactory.h"
#include "SqlAbstractFactory.h"
#include "MySqlAbstractFactory.h"

#define SQL
void UsingMacros()
{
#ifdef SQL
	Connection* pConnect{ new SqlConnection{} };
	Command* pCommand{ new SqlCommand{} };
#elif defined MYSQL
	Connection* pConnect{ new MySqlConnection{} };
	Command* pCommand{ new MySqlCommand{} };
#endif 

	pConnect->setConnectionString("uid=Abdelaziz;db=quran;table=surah");
	pConnect->openConnection();

	pCommand->setConnection(pConnect);
	pCommand->setCommandString("select * from quran");
	pCommand->executeCommand();

	RecordSet* pRec = pCommand->executeQuery();
	while (pRec->hasNext())
		std::cout << pRec->getRow() << std::endl;

	delete pConnect;
	delete pCommand;
	delete pRec;
}

void UsingConditional()
{
	int dbType = 0;

	Connection* pConnect{};
	Command* pCommand{};
	if (dbType == 0)
	{
		pConnect = new SqlConnection{};
		pCommand = new SqlCommand{};
	}
	else if (dbType == 1)
	{
		Connection* pConnect{ new MySqlConnection{} };
		Command* pCommand{ new MySqlCommand{} };
	}

	pConnect->setConnectionString("uid=Abdelaziz;db=quran;table=surah");
	pConnect->openConnection();

	pCommand->setConnection(pConnect);
	pCommand->setCommandString("select * from quran");
	pCommand->executeCommand();

	RecordSet* pRec = pCommand->executeQuery();
	while (pRec->hasNext())
		std::cout << pRec->getRow() << std::endl;

	delete pConnect;
	delete pCommand;
	delete pRec;
}

void FactoryMethod()
{
	Connection* pConnect{ DbFactory::createConnection("sql") };
	pConnect->setConnectionString("uid=Abdelaziz;db=quran;table=surah");
	pConnect->openConnection();

	Command* pCommand{ DbFactory::createCommand("sql") };
	pCommand->setConnection(pConnect);
	pCommand->setCommandString("select * from quran");
	pCommand->executeCommand();

	RecordSet* pRec = pCommand->executeQuery();
	while (pRec->hasNext())
		std::cout << pRec->getRow() << std::endl;

	delete pConnect;
	delete pCommand;
	delete pRec;
}

void AbstractFactoryMethod(DbAbstractFactory* pAbstractFactory)
{
	Connection* pConnect{ pAbstractFactory->createConnection() };
	pConnect->setConnectionString("uid=Abdelaziz;db=quran;table=surah");
	pConnect->openConnection();

	Command* pCommand{ pAbstractFactory->createCommand() };
	pCommand->setConnection(pConnect);
	pCommand->setCommandString("select * from quran");
	pCommand->executeCommand();

	RecordSet* pRec = pCommand->executeQuery();
	while (pRec->hasNext())
		std::cout << pRec->getRow() << std::endl;

	delete pConnect;
	delete pCommand;
	delete pRec;
}
int main()
{
	SqlAbstractFactory pAbstractFactory{ };

	AbstractFactoryMethod(&pAbstractFactory);

	return 0;
}