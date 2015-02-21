# Excel-XML

A simple library for creating XML based Excel documents programatically

# Use
```
#include "Excel.h"<br>
int main(int argc, const char * argv[]) {
  //Create an Excel Document
  Excel spreadsheet("/Users/deisterhold/Desktop/Test.xml");
  
  //Get the main workbook (Excel only has a single workbook)
  Workbook *workbook = spreadsheet.getWorkbook();
  
  //Set Author and Company (Optional)
  workbook->setAuthor("Name Here");
  workbook->setCompany("Company Name");
  
  //Add a worksheet to the workbook
  workbook->addWorksheet(Worksheet("Sheet 1"));
  
  //Get the newly created worksheet
  Worksheet *worksheet = workbook->getWorksheet(0);
  
  //Add a table to the worksheet
  worksheet->addTable(Table());
  
  //Get the newly created table
  Table *table = worksheet->getTable(0);
  
  //Add a row to the table
  table->addRow(Row());
  
  //Get the newly create row
  Row *row = table->getRow(0);
  
  //Add a cell to the row
  row->addCell(Cell());
  
  //Get the newly created cell
  Cell *cell = row->getCell(0);
  
  //Put a data item in the cell (In this example we create a cell to hold a string)
  //There are currently three data types DATATYPE_STRING, DATATYPE_NUMBER, DATATYPE_DATETIME
  //All data is given as a string even if a number or time
  cell->setContents(Data("Hello", DATATYPE_STRING)); //If no data type is given the data is assumed to be a string
  //Equivalent to above "cell->setContents(Data("Hello"));"
  
  //Saves the data in xml to the file
  spreadsheet.save();
  
  //Closes the file
  spreadsheet.close();
  
  return 0;
}
```
