//
//  Worksheet.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__Worksheet__
#define __Excel__Worksheet__

#include <stdio.h>
#include "Table.h"
#include "WorksheetOptions.h"

class Worksheet{
    string _name;
    vector<Table> _contentsOfWorksheet;
    WorksheetOptions _options;
public:
    Worksheet();
    Worksheet(string name);
    ~Worksheet();
    
    void addTable(Table newTable);
    void removeTable(int index);
    void setTable(Table newTable, int index);
    Table* getTable(int index);
    
    void setName(string name);
    string getName();
    
    int getNumberOfTables();
    
    string getXML();
};

#endif /* defined(__Excel__Worksheet__) */
