//
// Created by Misan on 4/7/2021.
//

#include"validator.h"

bool Validator::validateDog(const std::string &breed, const std::string &name, int age, const std::string &photo) {
    bool flag;
    if(age<0)
        flag = true;
    else if(breed.empty())
        flag = true;
    else if (name.empty())
        flag = true;
    else if (photo.empty())
        flag = true;
    else
        flag = false;
    return flag;
}

