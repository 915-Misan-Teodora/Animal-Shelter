//
// Created by Misan on 5/1/2021.
//

#ifndef A67_915_MISAN_TEODORA_REPOADOPTION_H
#define A67_915_MISAN_TEODORA_REPOADOPTION_H

//#include "CSVRepo.h"
#include <vector>
#include "../Domain/Pets.h"

class AdoptionRepo
{
protected:
    std::vector<Dog> elemsAdoption;

public:
    void addDogAdoption(Dog &dog);
    std::vector<Dog> getElementsAdoption();
};
#endif //A67_915_MISAN_TEODORA_REPOADOPTION_H
