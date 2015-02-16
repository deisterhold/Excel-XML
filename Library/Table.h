//
//  Table.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__Table__
#define __Excel__Table__

#include <stdio.h>
#include "Row.h"
#include "Column.h"

class Table {
    vector<Row> _contentsOfTable;
    vector<Column> _widthsOfRows;
public:
    Table();
    Table(Row data[], int numOfRows);
    ~Table();
    
    void addRow(Row newRow);
    void removeRow(int index);
    void setRow(Row newRow, int index);
    Row* getRow(int index);
    
    void addRow(Row newRow, Column newColumn);
    void setRow(Row newRow, Column newColumn, int index);
    void setRowWidth(int width, int index);
    int getRowWidth(int index);
    
    int getNumberOfRows();
    
    string getXML();
};

#endif /* defined(__Excel__Table__) */
