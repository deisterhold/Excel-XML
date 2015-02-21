//
//  Cell.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "Cell.h"

Cell::Cell() {
    this->_styleID = 0;
    this->_contentsOfCell = Data();
}

Cell::Cell(Data Contents, int styleID) {
    this->setStyle(styleID);
    this->setContents(Contents);
}

void Cell::setStyle(int ID) {
    this->_styleID = ID;
}

int Cell::getStyle() {
    return this->_styleID;
}

void Cell::setContents(Data contents) {
    this->_contentsOfCell = contents;
}

Data* Cell::getContents() {
    return &_contentsOfCell;
}

string Cell::getXML() {
//    string temp = "<Cell ss:StyleID=\"";
//    temp += to_string(_styleID);
//    temp += "\">";
    string temp = "    <Cell>";
    temp += _contentsOfCell.getXML();
    temp += "</Cell>\n";
    return temp;
}