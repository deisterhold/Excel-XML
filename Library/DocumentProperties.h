//
//  DocumentProperties.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/15/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__DocumentProperties__
#define __Excel__DocumentProperties__

#include <stdio.h>
#include <string>

using namespace std;

class DocumentProperties {
    string _author;
    string _lastAuthor;
    string _company;
    string _version;
    string _timeCreated;
public:
    DocumentProperties();
    ~DocumentProperties();
    
    void setAuthor(string newAuthor);
    string getAuthor();
    
    void setLastAuthor(string newLastAuthor);
    string getLastAuthor();
    
    void setCompany(string newCompany);
    string getCompany();
    
    string getXML();
};

#endif /* defined(__ExcelTest__DocumentProperties__) */
