//
// Created by Misan on 5/1/2021.
//

#include "RepoAdoption.h"

void AdoptionRepo::addDogAdoption(Dog &dog) {
        elemsAdoption.push_back(dog);
}

std::vector<Dog> AdoptionRepo::getElementsAdoption() {
    return elemsAdoption;
}
