//
// Created by Misan on 5/1/2021.
//

#include "File.h"


FileOption::FileOption() : AdoptionRepo{}, _file(""){
}

void FileOption::setName(const string &file) {
    this->_file = file;
}
