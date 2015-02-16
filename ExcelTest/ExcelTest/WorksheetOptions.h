//
//  WorksheetOptions.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/15/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__WorksheetOptions__
#define __Excel__WorksheetOptions__

#include <stdio.h>
#include <vector>
#include "Pane.h"

class WorksheetOptions {
    int _pageLayoutZoom;
    bool _selected;
    vector<Pane> _panes;
    bool _protectObjects;
    bool _protectScenarios;
public:
    WorksheetOptions();
    ~WorksheetOptions();
    
    void setPageLayoutZoom(int zoom);
    int getPageLayoutZoom();
    
    void setSelected(bool selected);
    bool getSelected();
    
    void addPane(Pane newPane);
    void removePane(int index);
    void setPane(Pane newPane, int index);
    Pane getPane(int index);
    
    void setProtectObjects(bool protect);
    bool getProtectObjects();
    
    void setProtectScenarios(bool protect);
    bool getProtectScenarios();
    
    string getXML();
};

#endif /* defined(__ExcelTest__WorksheetOptions__) */
