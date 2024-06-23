#pragma once

#include "DocumentFactory.h"

class Application
{
private:
	DocumentPtr m_pDocument;

public:
	void New(const std::string& type);
	void Open(const std::string& type);
	void Save();
	
};

