//
// Created by Misan on 5/1/2021.
//

#ifndef A67_915_MISAN_TEODORA_FILE_H
#define A67_915_MISAN_TEODORA_FILE_H

#include "RepoAdoption.h"

class FileOption: public AdoptionRepo
{
protected:
    std::string _file;
public:
    FileOption();
    void setName(const std::string&);
    virtual void writeFile() = 0;
    virtual void display() const = 0;
};
#endif //A67_915_MISAN_TEODORA_FILE_H
