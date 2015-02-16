//
//  Cell.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__Cell__
#define __Excel__Cell__

#include <stdio.h>
#include "Data.h"

class Cell {
    int _styleID;
    Data _contentsOfCell;
public:
    Cell();
    Cell(Data Contents, int styleID);
    
    void setStyle(int ID);
    int getStyle();
    
    void setContents(Data contents);
    Data* getContents();
    string getXML();
};

#endif /* defined(__Excel__Cell__) */
