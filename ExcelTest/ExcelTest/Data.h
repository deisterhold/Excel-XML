//
//  Data.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__Data__
#define __Excel__Data__

#include <stdio.h>
#include <iostream>

using namespace std;

#define DATATYPE_STRING 0
#define DATATYPE_NUMBER 1
#define DATATYPE_DATETIME 2

class Data {
    string _contents;
    int _type;
public:
    Data();
    Data(string contents);
    Data(string contents, int type);
    void setDataType(int theType);
    int getDataType();
    
    void setContents(string contents);
    string getContents();

    string getXML();
};

#endif /* defined(__Excel__Data__) */
