//
//  Data.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "Data.h"

Data::Data() {
    
}

Data::Data(string contents) {
    this->setDataType(DATATYPE_STRING);
    this->setContents(contents);
}

Data::Data(string contents, int type) {
    this->setDataType(type);
    this->setContents(contents);
}

void Data::setDataType(int theType) {
    this->_type = theType;
}

int Data::getDataType() {
    return _type;
}

void Data::setContents(string contents) {
    _contents = contents;
}

string Data::getContents() {
    return _contents;
}

string Data::getXML() {
    string temp = "<Data ss:Type=\"";
    switch (this->_type) {
        case 0:
            temp += "String\">";
            break;
        case 1:
            temp += "Number\">";
            break;
        case 2:
            temp += "DataTime\">";
            break;
        default:
            temp += "String\">";
            break;
    }
    temp += this->_contents;
    temp += "</Data>";
    
    return temp;
}