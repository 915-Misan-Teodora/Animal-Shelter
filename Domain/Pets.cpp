//
// Created by Misan on 4/7/2021.
//

#include <vector>
#include<sstream>
#include "Pets.h"

Dog::Dog(const string &breed, const string &name, int age, const string &photograph): breed(breed), name(name), age(age), photograph(photograph){

}

Dog::Dog() {
}

Dog::Dog(const Dog &d) {
    this->breed = d.breed;
    this->name= d.name;
    this->age = d.age;
    this->photograph = d.photograph;
}

std::string Dog::getBreedDog() const {
    return this->breed;
}

std::string Dog::getNameDog() const {
    return this->name;
}

int Dog::getAgeDog() const {
    return this->age;
}

std::string Dog::getPhotoDog() const {
    return this->photograph;
}

void Dog::setAgeDog(int age) {
    this->age = age;
}

void Dog::setPhotoDog(std::string photoDog) {
    this->photograph = photoDog;
}

int Dog::foundDog(Dog d) {
    if(this->breed == d.breed && this->name == d.name)
        return 1;
    else return 0;
}

bool Dog::operator==(const Dog &anotherDog) const {
    return (this->breed == anotherDog.breed && this->name == anotherDog.name);
}

Dog &Dog::operator=(const Dog &dogToGetValuesFrom) {
    breed = dogToGetValuesFrom.getBreedDog();
    name = dogToGetValuesFrom.getNameDog();
    age = dogToGetValuesFrom.getAgeDog();
    photograph = dogToGetValuesFrom.getPhotoDog();
    return *this;
}


vector<string> tokenize(string str, char delimiter){
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}


std::istream &operator>>(istream &is, Dog &dog) {
    string line;
    getline(is, line);
    vector<string> tokens = tokenize(line, ',');
    if(tokens.size() !=4) return is;
    dog.breed = tokens[0];
    dog.name = tokens[1];
    dog.age = stoi(tokens[2]);
    dog.photograph = tokens[3];

    return is;
}

std::ostream &operator<<(ostream &os, const Dog &dog) {
    os << dog.breed << "," << dog.name << "," << dog.age << "," << dog.photograph << "\n";
    return os;
}


Dog::~Dog() = default;


