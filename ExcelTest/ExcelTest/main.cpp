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
    //Create an Excel Document
    Excel spreadsheet("/Users/deisterhold/Desktop/Test.xls");
//    Excel spreadsheet;
//    spreadsheet.open("/Users/deisterhold/Desktop/Test.xls");
    
    //Get the main workbook (Excel only has a single workbook)
    Workbook *workbook = spreadsheet.getWorkbook();
    
    //Set Author and Company (Optional)
    workbook->setAuthor("Name Here");
    workbook->setCompany("Company Name");
    
    //Add a worksheet to the workbook
    workbook->addWorksheet(Worksheet("Sheet1"));
    
    //Get the newly created worksheet
    Worksheet *worksheet = workbook->getWorksheet(0);
    
    //Add a table to the worksheet
    worksheet->addTable(Table());
    worksheet->addTable(Table());
    
    //Get the newly created table
    Table *table = worksheet->getTable(0);
    
    //Add a row to the table
    table->addRow(Row());
    
    //Get the newly create row
    Row *row = table->getRow(0);
    
    //Add a cell to the row
    row->addCell(Cell());
    row->addCell(Cell());
    
    //Get the newly created cell
    Cell *cell = row->getCell(0);
    
    //Put a data item in the cell (In this example we create a cell to hold a string)
    //There are currently three data types DATATYPE_STRING, DATATYPE_NUMBER, DATATYPE_DATETIME
    //All data is given as a string even if a number or time
    cell->setContents(Data("Hello", DATATYPE_STRING)); //If no data type is given the data is assumed to be a string
    //Equivalent to above "cell->setContents(Data("Hello"));"
    
    cell = row->getCell(1);
    cell->setContents(Data("New Column"));
    //Saves the data in xml to the file
    spreadsheet.save();
    
    //Closes the file
    spreadsheet.close();
    
    //Optionally output
//    cout<<spreadsheet.getXML()<<endl;
    return 0;
}
