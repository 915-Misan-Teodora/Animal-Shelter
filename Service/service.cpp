//
// Created by Misan on 4/7/2021.
//

#include "service.h"
#include "../validation/validator.h"
#include "../Domain/Pets.h"
#include "../exceptions/exceptions.h"
#include "../Repository/CSVRepo.h"

Service::Service(FileOption* file, Repository& repo) : _adoptionList(file), _repo{repo}{

}

void Service::addDog(std::string breed, std::string name, int age, std::string photo) {
    Validator val;
    Exception exc("The fields of the dog are wrong!");
    if(!val.validateDog(breed, name, age, photo)) {
        Dog dog{breed, name, age, photo};
        this->_repo.addDogRepo(dog);
    }
    else throw exc;
}

std::vector<Dog> Service::getDog() {
    std::vector<Dog> allElems= _repo.getElements();
    return allElems;
}

void Service::deleteDog(std::string breed, std::string name) {
    Dog dog(breed, name, 0, " ");
    this->_repo.deleteDogRepo(dog);
}

void Service::updateDog(std::string breed, std::string name, int age, std::string photo) {
    Validator val;
    if(!val.validateDog(breed, name, age, photo)) {
        Dog dog(breed, name, age, photo);
        this->_repo.updateAgeDog(dog);
    }
    else return;
}

std::vector<Dog> Service::getDogsAdoption() {
    std::vector<Dog> allElems= _adoptionList->getElementsAdoption();
    return allElems;
}

void Service::AddDogAdoptionList(std::string breed, std::string name, int age, std::string photo) {
    Dog dog{breed, name, age, photo};
    this->_adoptionList->addDogAdoption(dog);
    this->_repo.deleteDogRepo(dog);
}

void Service::chooseAdoptionList(const string &file) {
    this->_adoptionList->setName(file);
    this->_adoptionList->writeFile();
}

void Service::saveIntoFile() const {
    this->_adoptionList->display();
}









