//
//  main.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

//MySQL Query to check last time the database was updated
//"SELECT UPDATE_TIME FROM information_schema.tables WHERE  TABLE_SCHEMA = 'dbName' AND TABLE_NAME = 'tableName'"

#include <iostream>
#include "Excel.h"

int main(int argc, const char * argv[]) {
    Excel spreadsheet("/Users/deisterhold/Desktop/Test.xml");
    Workbook *workbook = spreadsheet.getWorkbook();
    workbook->addWorksheet(Worksheet("Sheet 1"));
    Worksheet *worksheet = workbook->getWorksheet(0);
    worksheet->addTable(Table());
    Table table = *worksheet->getTable(0);
    table.addRow(Row());
    Row row = *table.getRow(0);
    row.addCell(Cell());
    Cell cell = *row.getCell(0);
    cell.setContents(Data("Hello", DATATYPE_STRING));
    cell.setStyle(1);
    row.setCell(cell, 0);
    table.setRow(row, 0);
    worksheet->setTable(table, 0);
    workbook->setWorksheet(*worksheet, 0);
    Style style;
    style.setBold(true);
    cout<<spreadsheet.getXML()<<endl;
    
    spreadsheet.save();
    spreadsheet.close();
    return 0;
}
