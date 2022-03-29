//
// Created by Misan on 4/20/2021.
//

#include "CSVRepo.h"
#include "../exceptions/exceptions.h"
#include <fstream>
#include <Windows.h>

void CsvRepo::display() const {
    string file = "\"" + this->_file + "\"";
    ShellExecuteA(NULL, NULL, "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Excel 2016", file.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void CsvRepo::writeFile() {
    ofstream file(this->_file);
    if (!file.is_open())
        throw Exception("The CSV file did not open!");
    for (const auto& dog : this->elemsAdoption)
        file << dog;
    file.close();

}

