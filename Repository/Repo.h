//
// Created by Misan on 4/7/2021.
//
#include "../Domain/Pets.h"
#include<vector>
using namespace std;

#ifndef A67_915_MISAN_TEODORA_REPO_H
#define A67_915_MISAN_TEODORA_REPO_H
class Repository{
protected:
    std::vector<Dog> elems;
    std::string _file;
public:
    Repository(std::string file);
    void addDogRepo(Dog &dog);
    void deleteDogRepo(Dog &dog);
    void updateAgeDog(Dog& dog);
    std::vector<Dog> getElements();

    void readFile();
    void writefile();

};
#endif //A67_915_MISAN_TEODORA_REPO_H
