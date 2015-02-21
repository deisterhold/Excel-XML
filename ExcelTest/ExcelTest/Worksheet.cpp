//
//  Worksheet.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "Worksheet.h"

Worksheet::Worksheet() {
    _name = "";
    _contentsOfWorksheet = vector<Table>();
    _options = WorksheetOptions();
}

Worksheet::Worksheet(string name) {
    setName(name);
    _contentsOfWorksheet = vector<Table>();
    _options = WorksheetOptions();
}

Worksheet::~Worksheet() {
}

void Worksheet::addTable(Table newTable) {
    _contentsOfWorksheet.push_back(newTable);
}
void Worksheet::removeTable(int index) {
    _contentsOfWorksheet.erase(_contentsOfWorksheet.begin() + index);
}

void Worksheet::setTable(Table newTable, int index) {
    _contentsOfWorksheet[index] = newTable;
}

Table* Worksheet::getTable(int index) {
    return &_contentsOfWorksheet[index];
}

void Worksheet::setName(string name) {
    _name = name;
}

string Worksheet::getName() {
    return _name;
}

int Worksheet::getNumberOfTables() {
    return (int) _contentsOfWorksheet.size();
}

string Worksheet::getXML() {
    string temp = " <Worksheet ss:Name=\"";
    temp += _name;
    temp += "\">\n";
    
    for(int tableNum = 0; tableNum < _contentsOfWorksheet.size(); tableNum++) {
        temp += _contentsOfWorksheet.size();
        temp += _contentsOfWorksheet[tableNum].getXML();
    }
    
    temp += _options.getXML();
    
    temp += " </Worksheet>\n";
    return temp;
}