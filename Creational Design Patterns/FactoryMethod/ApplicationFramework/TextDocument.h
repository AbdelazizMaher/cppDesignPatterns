#pragma once
#include "Document.h"
#include <iostream>

class TextDocument :
    public Document
{
public:
    void Write() override;
    void Read() override;
};

