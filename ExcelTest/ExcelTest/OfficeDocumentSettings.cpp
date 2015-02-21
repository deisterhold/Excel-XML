//
//  OfficeDocumentSettings.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/15/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "OfficeDocumentSettings.h"

OfficeDocumentSettings::OfficeDocumentSettings() {
    _allowPNG = true;
}

OfficeDocumentSettings::~OfficeDocumentSettings() {
    
}

void OfficeDocumentSettings::setAllowPNG(bool allow) {
    _allowPNG = allow;
}

bool OfficeDocumentSettings::getAllowPNG() {
    return _allowPNG;
}

string OfficeDocumentSettings::getXML() {
    string temp = " <OfficeDocumentSettings xmlns=\"urn:schemas-microsoft-com:office:office\">\n";
    
    if(_allowPNG) {
        temp += "  <AllowPNG/>\n";
    }
    
    temp += " </OfficeDocumentSettings>\n";
    return temp;
}