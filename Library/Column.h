//
//  Column.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/14/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__Column__
#define __Excel__Column__

#include <stdio.h>

class Column {
    int _width;
    
public:
    Column();
    Column(int width);
    
    void setWidth(int width);
    int getWidth();
};

#endif /* defined(__Excel__Column__) */
