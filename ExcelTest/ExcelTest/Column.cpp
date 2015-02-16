//
//  Column.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/14/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "Column.h"

Column::Column() {
    setWidth(80);
}

Column::Column(int width) {
    setWidth(width);
}

void Column::setWidth(int width) {
    _width = width;
}

int Column::getWidth() {
    return _width;
}