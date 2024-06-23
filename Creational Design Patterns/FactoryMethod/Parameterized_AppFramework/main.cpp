#include "Application.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Application app;

	app.New("text");
	app.Open("spreadsheet");
	app.Save();

	return 0;
}