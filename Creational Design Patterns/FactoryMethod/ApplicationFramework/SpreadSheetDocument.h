#pragma once
#include "Document.h"
#include <iostream>
 
class SpreadSheetDocument :
    public Document
{
public:
    void Write() override;
    void Read() override;
};

