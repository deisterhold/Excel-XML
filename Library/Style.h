//
//  Style.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/13/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__Style__
#define __Excel__Style__

#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

struct Color {
    uint8_t redColor;
    uint8_t greenColor;
    uint8_t blueColor;
};

class Style {
    static int styleID;
    bool borders;
    
    string fontName;
    string fontFamily;
    unsigned int fontSize;
    Color fontColor;
    bool interior;
    bool numberFormat;
    bool protection;
    
    bool bold;
    bool italicized;
    bool underlined;
public:
    Style();
    ~Style();
    
    void setFontSize(int newSize);
    int getFontSize();
    
    void setBold(bool value);
    bool getBold();
    
    void setItalicized(bool value);
    bool getItalicized();
    
    void setUnderlined(bool value);
    bool getUnderlined();
    
    static int getStyleID();
    
    string getXML();
};

#endif /* defined(__ExcelTest__Style__) */
