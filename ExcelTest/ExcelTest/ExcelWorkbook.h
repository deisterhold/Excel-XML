//
//  ExcelWorkbook.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/15/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__ExcelWorkbook__
#define __Excel__ExcelWorkbook__

#include <stdio.h>
#include <string>

using namespace std;

class ExcelWorkbook {
    unsigned int windowHeight;
    unsigned int windowWidth;
    int windowTopX;
    int windowTopY;
    bool protectStructure;
    bool protectWindows;
public:
    ExcelWorkbook();
    ~ExcelWorkbook();
    
    void setWindowHeight(int height);
    unsigned int getWindowHeight();
    
    void setWindowWidth(int width);
    unsigned int getWindowWidth();
    
    string getXML();
};

#endif /* defined(__ExcelTest__ExcelWorkbook__) */
