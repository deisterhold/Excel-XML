//
//  ExcelWorkbook.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/15/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "ExcelWorkbook.h"

ExcelWorkbook::ExcelWorkbook() {
    windowHeight = 13700;
    windowWidth = 25600;
    windowTopX = 5740;
    windowTopY = 0;
    protectStructure = false;
    protectWindows = false;
}

ExcelWorkbook::~ExcelWorkbook() {
    
}

void ExcelWorkbook::setWindowHeight(int height) {
    windowHeight = height;
}

unsigned int ExcelWorkbook::getWindowHeight() {
    return windowHeight;
}

void ExcelWorkbook::setWindowWidth(int width) {
    windowWidth = width;
}

unsigned int ExcelWorkbook::getWindowWidth() {
    return windowWidth;
}

string ExcelWorkbook::getXML() {
    string temp = " <ExcelWorkbook xmlns=\"urn:schemas-microsoft-com:office:excel\">\n";
    
    temp += "  <WindowHeight>";
    temp += to_string(windowHeight);
    temp += "</WindowHeight>\n";
    
    temp += "  <WindowWidth>";
    temp += to_string(windowWidth);
    temp += "</WindowWidth>\n";
    
    temp += "  <WindowTopX>";
    temp += to_string(windowTopX);
    temp += "</WindowTopX>\n";
    
    temp += "  <WindowTopY>";
    temp += to_string(windowTopY);
    temp += "</WindowTopY>\n";
    
    if (protectStructure) {
        temp += "  <ProtectStructure>True</ProtectStructure>\n";
    }
    else {
        temp += "  <ProtectStructure>False</ProtectStructure>\n";
    }
    
    if (protectWindows) {
        temp += "  <ProtectWindows>True</ProtectWindows>\n";
    }
    else {
        temp += "  <ProtectWindows>False</ProtectWindows>\n";
    }
    
    temp += " </ExcelWorkbook>\n";
    return temp;
}