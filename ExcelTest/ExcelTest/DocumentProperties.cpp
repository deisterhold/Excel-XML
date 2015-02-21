//
//  DocumentProperties.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/15/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "DocumentProperties.h"
#include <iostream>
#include <time.h>

DocumentProperties::DocumentProperties() {
    // Get local time and convert to the right format
    time_t unixTime;
    time(&unixTime);
    struct tm *localTime = localtime(&unixTime);
    size_t maxSize = 21;
    char formattedTime[21];
    strftime(formattedTime, maxSize, "%Y-%m-%dT%XZ", localTime);
    
    // Initialize all variables
    _author = "";
    _lastAuthor = "";
    _timeCreated = formattedTime;
    _company = "";
    _version = "14.0";
}

DocumentProperties::~DocumentProperties() {
    
}

void DocumentProperties::setAuthor(string newAuthor) {
    if (_author == "") {
        _author = newAuthor;
        _lastAuthor = newAuthor;
    }
    else {
        _lastAuthor = _author;
        _author = newAuthor;
    }
}

string DocumentProperties::getAuthor() {
    return _author;
}

void DocumentProperties::setLastAuthor(string newLastAuthor) {
    _lastAuthor = newLastAuthor;
}

string DocumentProperties::getLastAuthor() {
    return _lastAuthor;
}

void DocumentProperties::setCompany(string newCompany) {
    _company = newCompany;
}

string DocumentProperties::getCompany() {
    return _company;
}

string DocumentProperties::getXML() {
    string temp = " <DocumentProperties xmlns=\"urn:schemas-microsoft-com:office:office\">\n";
    
    temp += "  <Author>";
    temp += _author;
    temp += "</Author>\n";
    
    temp += "  <LastAuthor>";
    temp += _lastAuthor;
    temp += "</LastAuthor>\n";
    
    temp += "  <Created>";
    temp += _timeCreated;
    temp += "</Created>\n";
    
    temp += "  <Company>";
    temp += _company;
    temp += "</Company>\n";
    
    temp += "  <Version>";
    temp += _version;
    temp += "</Version>\n";
    
    temp += " </DocumentProperties>\n";
    
    return temp;
}