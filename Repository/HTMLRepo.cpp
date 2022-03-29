//
// Created by Misan on 5/5/2021.
//

#include "HTMLRepo.h"
#include "../exceptions/exceptions.h"
#include <Windows.h>
#include <fstream>
void HtmlRepo::display() const {
    string file = "\"" + this->_file + "\"";
    ShellExecuteA(NULL, NULL, "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Google Chrome", file.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void HtmlRepo::writeFile() {
    ofstream file(this->_file);
    if(!file.is_open()){
        throw Exception("The HTML file does not open ok");
    }
    file << "<!DOCTYPE html>\n"
            "<html>\n"
            "<body>\n"
            "<table border=\"1\">\n"
            "<tr>\n"
            "<td>Breed</td>\n"
            "<td>Name</td>\n"
            "<td>Age</td>\n"
            "<td>Photograph</td>\n"
            "</tr>\n";
    for ( auto dog : this->elemsAdoption){
        file << "<tr>\n"
             << "<td>" << dog.getBreedDog() << "</td>\n"
             << "<td>" << dog.getNameDog() << "</td>\n"
             << "<td>" << dog.getAgeDog() << "</td>\n"
             << "<td>" << dog.getPhotoDog() << "</td>\n"
             << "</tr>\n";
    }
    file << "</table>\n"
            "</body>\n"
            "</html>\n";
}
