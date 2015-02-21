//
//  Style.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/13/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "Style.h"

int Style::globalStyleID = 0;

Style::Style() {
    fontName = "Calibri";
    fontFamily = "Swiss";
    fontSize = 12;
    fontColor.redColor = 0;
    fontColor.greenColor = 0;
    fontColor.blueColor = 0;
    interior = true;
    numberFormat = true;
    protection = true;
    
    bold = false;
    italicized = false;
    underlined = false;
    styleID = globalStyleID;
    ++globalStyleID;
}

Style::~Style() {
    
}

void Style::setFontSize(int newSize) {
    fontSize = newSize;
}

int Style::getFontSize() {
    return fontSize;
}

void Style::setBold(bool value) {
    bold = value;
}

bool Style::getBold() {
    return bold;
}

void Style::setItalicized(bool value) {
    italicized = value;
}

bool Style::getItalicized() {
    return italicized;
}

void Style::setUnderlined(bool value) {
    underlined = value;
}

bool Style::getUnderlined() {
    return underlined;
}

int Style::getStyleID() {
    return styleID;
}

string Style::getXML() {
    string temp = "  <Style ss:ID=\"";
    if (styleID == 0) {
        temp += "Default";
        temp += "\" ss:Name=\"Normal\">\n";
    }
    else {
        temp += getStyleID();
        temp += "\" ss:Name=\"Normal\">\n";
    }
    
    temp += "   <Alignment ss:Vertical=\"Bottom\"/>\n";
    
    if (borders) {
        temp += "   <Borders/>\n";
    }
    
    temp += "   <Font ss:FontName=\"";
    temp += fontName;
    temp += "\" x:Family=\"";
    temp += fontFamily;
    temp += "\" ss:Size=\"";
    temp += to_string(fontSize);
    temp += "\" ss:Color=\"#";
    temp += "000000"; // Set color to black
    temp += "\"/>\n";
    
    if (interior) {
        temp += "   <Interior/>\n";
    }
    
    if (numberFormat) {
        temp += "   <NumberFormat/>\n";
    }
    
    if (protection) {
        temp += "   <Protection/>\n";
    }
    
//    if (bold) {
//        temp += "<ss:Font ss:Bold=\"1\">";
//    }
//    else {
//        temp += "<ss:Font ss:Bold=\"0\">";
//    }
//    
//    if (italicized) {
//        temp += "<ss:Font ss:Italics=\"1\">";
//    }
//    else {
//        temp += "<ss:Font ss:Italics=\"0\">";
//    }
//    
//    if (underlined) {
//        temp += "<ss:Font ss:Underline=\"1\">";
//    }
//    else {
//        temp += "<ss:Font ss:Underline=\"0\">";
//    }
    
    temp += "  </Style>\n";
    return temp;
}