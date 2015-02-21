//
//  Workbook.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "Workbook.h"

Workbook::Workbook() {
    _contentsOfWorkbook = vector<Worksheet>();
    _workbookStyles = vector<Style>();
    _properties = DocumentProperties();
    _documentSettings = OfficeDocumentSettings();
    _excelWorkbook = ExcelWorkbook();
    _workbookStyles.push_back(Style());
}

Workbook::~Workbook() {
}

void Workbook::addWorksheet(Worksheet newWorksheet) {
    _contentsOfWorkbook.push_back(newWorksheet);
}

void Workbook::removeWorkSheet(int index) {
    _contentsOfWorkbook.erase(_contentsOfWorkbook.begin() + index);
}

void Workbook::setWorksheet(Worksheet newWorksheet, int index) {
    _contentsOfWorkbook[index] = newWorksheet;
}

Worksheet* Workbook::getWorksheet(int index) {
    return &_contentsOfWorkbook[index];
}

void Workbook::addStyle(Style newStyle) {
    cout<<"New Style Made"<<endl;
    _workbookStyles.push_back(newStyle);
}

void Workbook::removeStyle(int index) {
    _workbookStyles.erase(_workbookStyles.begin() + index);
}

void Workbook::setStyle(Style newStyle, int index) {
    _workbookStyles[index] = newStyle;
}

Style Workbook::getStyle(int index) {
    return _workbookStyles[index];
}

void Workbook::setAuthor(string newAuthor) {
    _properties.setAuthor(newAuthor);
}
string Workbook::getAuthor() {
    return _properties.getAuthor();
}

void Workbook::setCompany(string newCompany) {
    _properties.setCompany(newCompany);
}

string Workbook::getCompany() {
    return _properties.getCompany();
}

int Workbook::getNumberOfWorksheets() {
    return (int) _contentsOfWorkbook.size();
}

int Workbook::getNumberOfStyles() {
    return (int) _workbookStyles.size();
}

string Workbook::getXML() {
    string temp = "<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\"\n xmlns:o=\"urn:schemas-microsoft-com:office:office\"\n xmlns:x=\"urn:schemas-microsoft-com:office:excel\"\n xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\"\n xmlns:html=\"http://www.w3.org/TR/REC-html40\">\n";
    
    temp += _properties.getXML();
    temp += _documentSettings.getXML();
    temp += _excelWorkbook.getXML();
    
    temp += " <Styles>\n";
    for (int numStyles = 0; numStyles < _workbookStyles.size(); numStyles++) {
        temp += _workbookStyles[numStyles].getXML();
    }
    temp += " </Styles>\n";
    
    for(int worksheetNum = 0; worksheetNum < _contentsOfWorkbook.size(); worksheetNum++) {
        temp += _contentsOfWorkbook[worksheetNum].getXML();
    }

    temp += "</Workbook>\n";
    return temp;
}