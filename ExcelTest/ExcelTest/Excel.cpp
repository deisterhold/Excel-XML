//
//  Excel.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "Excel.h"

Excel::Excel() {
    _workbook = Workbook();
    _file = new fstream();
}

Excel::~Excel() {
    if(_file->is_open()) {
        _file->close();
    }
    delete _file;
}

Excel::Excel(fstream &file) {
    _file = &file;
}

Excel::Excel(string fileLocation) {
    _file = new fstream(fileLocation.c_str());
    if(!_file->is_open()) {
        cerr<<"File \""<<fileLocation<<"\" does not existing, attempting to create."<<endl;
        _file = new fstream(fileLocation.c_str(), ios::trunc | ios::in | ios::out);
        if(_file->is_open()) {
            cout<<"File opened."<<endl;
        }
        else {
            cerr<<"Error: Unable to open file \""<<fileLocation<<"\"."<<endl;
        }
    }
}

string Excel::getXML() {
    string temp = "<?xml version=\"1.0\"?>\n";
    temp += _workbook.getXML();
    return temp;
}

void Excel::save() {
    *_file<<getXML();
}

void Excel::open(string fileLocation) {
    _file = new fstream(fileLocation.c_str());
    if(!_file->is_open()) {
        cerr<<"File \""<<fileLocation<<"\" does not existing, attempting to create."<<endl;
        _file = new fstream(fileLocation.c_str(), ios::trunc | ios::in | ios::out);
        if(_file->is_open()) {
            cout<<"File opened."<<endl;
        }
        else {
            cerr<<"Error: Unable to open file \""<<fileLocation<<"\"."<<endl;
        }
    }
}

void Excel::close() {
    _file->close();
}

void Excel::setWorkbook(Workbook newWorkbook) {
    _workbook = newWorkbook;
}

Workbook* Excel::getWorkbook() {
    return &_workbook;
}

string Excel::readInFile(ifstream &input) {
    if(input.eof()) {
        return "";
    }
    char *data;
    input.getline(data, 1000, '\n');
    return (string) data;
}

void Excel::writeOutFile(ofstream &output, string data) {
    output<<data<<endl;
}