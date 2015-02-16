//
//  Excel.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__Excel__
#define __Excel__Excel__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Workbook.h"

#ifndef __cplusplus
#error C++ Compiler Required
#endif

using namespace std;

class Excel {
    fstream *_file;
    Workbook _workbook;
    string readInFile(ifstream &input);
    void writeOutFile(ofstream &output, string data);
public:
    Excel();
    Excel(fstream &file);
    Excel(string fileLocation);
    
    ~Excel();
    
    void save();
    void open(string fileLocation);
    void close();
    
    void setWorkbook(Workbook newWorkbook);
    Workbook* getWorkbook();
    
    string getXML();
};

#endif /* defined(__Excel__Excel__) */
