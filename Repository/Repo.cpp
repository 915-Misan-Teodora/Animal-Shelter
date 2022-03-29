//
// Created by Misan on 4/7/2021.
//

#include "Repo.h"
#include "../exceptions/exceptions.h"
#include <fstream>
#include<iostream>

void Repository::addDogRepo(Dog &dog) {
    Exception exc("This dog already exists in the shelter");
    for(int i=0; i< elems.size(); i++) {
        if (elems[i].foundDog(dog))
            throw exc;
    }
    elems.push_back(dog);
    writefile();
}

std::vector<Dog> Repository::getElements() {
    return elems;
}

void Repository::deleteDogRepo(Dog &dog) {
    Exception exc("This dog does not exists in the shelter!");
    for(auto i=elems.begin(); i != elems.end(); i++) {
        if (*i==dog) {
            elems.erase(i);
            writefile();
            return;
        }
    }
    throw exc;
}

void Repository::updateAgeDog(Dog &dog) {
    Exception exc("This dog can not be update! You enter his fields wrong!!");
    int position=-1;
    for(auto i=elems.begin(); i != elems.end(); i++){
        position++;
        if(*i==dog){
            elems.at(position) = dog;
            writefile();
            return;
        }
    }
    throw exc;
}


Repository::Repository(std::string file) : _file(file){
    readFile();
}

void Repository::readFile() {
    ifstream f(this->_file);
    Dog input;
    if(!f.is_open())
        return;
    while(f>>input){
        elems.push_back(input);
    }
    f.close();
}

void Repository::writefile() {
    ofstream f(this->_file);
    if(!f.is_open())
        return;
    vector<Dog> list = getElements();
    for (const auto& dog : list)
    {
        f << dog;
    }
    f.close();
}

