//
//  WorksheetOptions.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/15/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "WorksheetOptions.h"

WorksheetOptions::WorksheetOptions() {
    _pageLayoutZoom = 0;
    _selected = true;
    _protectObjects = false;
    _protectScenarios = false;
    _panes = vector<Pane>();
    _panes.push_back(Pane(1, 1, 1));
}

WorksheetOptions::~WorksheetOptions() {

}

void WorksheetOptions::setPageLayoutZoom(int zoom) {
    _pageLayoutZoom = zoom;
}

int WorksheetOptions::getPageLayoutZoom() {
    return _pageLayoutZoom;
}

void WorksheetOptions::setSelected(bool selected) {
    _selected = selected;
}

bool WorksheetOptions::getSelected() {
    return _selected;
}

void WorksheetOptions::addPane(Pane newPane) {
    _panes.push_back(newPane);
}

void WorksheetOptions::removePane(int index) {
    _panes.erase(_panes.begin() + index);
}


void WorksheetOptions::setPane(Pane newPane, int index) {
    _panes[index] = newPane;
}

Pane WorksheetOptions::getPane(int index) {
    return _panes[index];
}

void WorksheetOptions::setProtectObjects(bool protect) {
    _protectObjects = protect;
}

bool WorksheetOptions::getProtectObjects() {
    return _protectObjects;
}

void WorksheetOptions::setProtectScenarios(bool protect) {
    _protectScenarios = protect;
}

bool WorksheetOptions::getProtectScenarios() {
    return _protectScenarios;
}

string WorksheetOptions::getXML() {
    string temp = "  <WorksheetOptions xmlns=\"urn:schemas-microsoft-com:office:excel\">\n";
    
    temp += "   <Unsynced/>\n";
    
    temp += "   <PageLayoutZoom>";
    temp += to_string(_pageLayoutZoom);
    temp += "</PageLayoutZoom>\n";
    
    if (_selected) {
        temp += "   <Selected/>\n";
    }
    
//    temp += "   <Panes>\n";
//    for (int paneNum = 0; paneNum < _panes.size(); paneNum++) {
//        temp += _panes[paneNum].getXML();
//    }
//    temp += "   </Panes>\n";
    
    if (_protectObjects) {
        temp += "   <ProtectObjects>True</ProtectObjects>\n";
    }
    else {
        temp += "   <ProtectObjects>False</ProtectObjects>\n";
    }
    
    if (_protectScenarios) {
        temp += "   <ProtectScenarios>True</ProtectScenarios>\n";
    }
    else {
        temp += "   <ProtectScenarios>False</ProtectScenarios>\n";
    }
    
    temp += "  </WorksheetOptions>\n";
    
    return temp;
}