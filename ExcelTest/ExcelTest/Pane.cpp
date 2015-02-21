//
//  Pane.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/15/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "Pane.h"

Pane::Pane() {
    setNumber(1);
    setActiveRow(1);
    setActiveCol(1);
}

Pane::Pane(int number, int activeRow, int activeCol) {
    setNumber(number);
    setActiveRow(activeRow);
    setActiveCol(activeCol);
}

Pane::~Pane() {
    
}

void Pane::setNumber(int number) {
    _number = number;
}

int Pane::getNumber() {
    return _number;
}

void Pane::setActiveRow(int row) {
    _activeRow = row;
}

int Pane::getActiveRow() {
    return _activeRow;
}

void Pane::setActiveCol(int col) {
    _activeCol = col;
}

int Pane::getActiveCol() {
    return _activeCol;
}

string Pane::getXML() {
    string temp = "    <Pane>\n";
    
    temp += "     <Number>";
    temp += to_string(_number);
    temp += "</Number>\n";
    
    temp += "     <ActiveRow>";
    temp += to_string(_activeRow);
    temp += "</ActiveRow>\n";
    
    temp += "     <ActiveCol>";
    temp += to_string(_activeCol);
    temp += "</ActiveCol>\n";
    
    temp += "    </Pane>\n";
    return temp;
}