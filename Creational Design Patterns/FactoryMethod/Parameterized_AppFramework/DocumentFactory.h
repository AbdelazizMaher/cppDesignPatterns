#pragma once

#include <memory>
#include <string>
#include "Document.h"

using DocumentPtr = std::unique_ptr<Document>;

class DocumentFactory
{
public:
	DocumentPtr Create(const std::string& type);
};

