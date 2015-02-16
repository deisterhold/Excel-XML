//
//  Row.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__Row__
#define __Excel__Row__

#include <stdio.h>
#include <vector>
#include "Cell.h"

class Row {
    vector<Cell> _contentsOfRow;
public:
    Row();
    Row(Cell data[], int numOfCells);
    
    void addCell(Cell newCell);
    void removeCell(int index);
    void setCell(Cell newCell, int index);
    Cell* getCell(int index);
    
    int getNumberOfCells();
    string getXML();
};

#endif /* defined(__Excel__Row__) */
