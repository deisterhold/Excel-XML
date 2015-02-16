//
//  Pane.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/15/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__Pane__
#define __Excel__Pane__

#include <stdio.h>
#include <string>

using namespace std;

class Pane {
    int _number;
    int _activeRow;
    int _activeCol;
public:
    Pane();
    Pane(int number, int activeRow, int activeCol);
    ~Pane();
    
    void setNumber(int number);
    int getNumber();
    
    void setActiveRow(int row);
    int getActiveRow();
    
    void setActiveCol(int col);
    int getActiveCol();
    
    string getXML();
};

#endif /* defined(__ExcelTest__Pane__) */
