#pragma once

#include <memory>
#include "Document.h"

using DocumentPtr = std::unique_ptr<Document>;

class Application
{
private:
	DocumentPtr m_pDocument;

public:
	virtual ~Application() = default;

	void New();
	void Open();
	void Save();
	virtual DocumentPtr Create() { return nullptr; }
};

