#include "Frame.h"
#include "Button.h"
#include <iostream>

void Display(IWidget* pWidget)
{
	//pWidget->paintComponent();

	if( auto pFrame = pWidget->getFrame(); pFrame != nullptr)
		pWidget->addWidget(new Button{});
	else
		std::cout << "[Error]: Cannot add a child" << std::endl;

	if (auto parent = pWidget->getParent(); parent != nullptr)
		parent->paintComponent();
	else
		std::cout << "[Error]: No parent" << std::endl;
}

int main()
{
	Frame* mainWindow{ new Frame{} };
	Button* btnOK{ new Button{} };

	mainWindow->addWidget(btnOK);
	//mainWindow->paintComponent();

	Frame* childWindow{ new Frame{} };
	Button* btnFind{ new Button{} };

	childWindow->addWidget(btnFind);
	mainWindow->addWidget(childWindow);
	//mainWindow->paintComponent();

	/* std::cout << "Changing Visibility" << std::endl;
	mainWindow->setVisibile(false);
	mainWindow->paintComponent(); */

	std::cout << "Operating on button" << std::endl;
	Display(btnOK);
	std::cout << "\n\nOperating on frame" << std::endl;
	Display(mainWindow);

	delete mainWindow;
	_CrtDumpMemoryLeaks();

	return 0;
}