//
//  Workbook.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__Workbook__
#define __Excel__Workbook__

#include <stdio.h>
#include "DocumentProperties.h"
#include "OfficeDocumentSettings.h"
#include "ExcelWorkbook.h"
#include "Style.h"
#include "Worksheet.h"

class Workbook {
    vector<Worksheet> _contentsOfWorkbook;
    vector<Style> _workbookStyles;
    DocumentProperties _properties;
    OfficeDocumentSettings _documentSettings;
    ExcelWorkbook _excelWorkbook;
public:
    Workbook();
    ~Workbook();
    
    void addWorksheet(Worksheet newWorksheet);
    void removeWorkSheet(int index);
    void setWorksheet(Worksheet newWorksheet, int index);
    Worksheet* getWorksheet(int index);
    
    void addStyle(Style);
    void removeStyle(int index);
    void setStyle(Style newStyle, int index);
    Style getStyle(int index);
    
    void setAuthor(string newAuthor);
    string getAuthor();
    
    void setCompany(string newCompany);
    string getCompany();
    
    int getNumberOfWorksheets();
    int getNumberOfStyles();
    
    string getXML();
};

#endif /* defined(__Excel__Workbook__) */
