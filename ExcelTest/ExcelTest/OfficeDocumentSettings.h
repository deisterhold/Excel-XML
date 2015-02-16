//
//  OfficeDocumentSettings.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/15/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__OfficeDocumentSettings__
#define __Excel__OfficeDocumentSettings__

#include <stdio.h>
#include <string>

using namespace std;

class OfficeDocumentSettings {
    bool _allowPNG;
public:
    OfficeDocumentSettings();
    ~OfficeDocumentSettings();
    
    void setAllowPNG(bool allow);
    bool getAllowPNG();
    
    string getXML();
};

#endif /* defined(__ExcelTest__OfficeDocumentSettings__) */
