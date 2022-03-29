//
// Created by Misan on 4/7/2021.
//
#include<string>
#include "../Repository/Repo.h"
#include "../Repository/CSVRepo.h"
#include "../Repository/File.h"

#ifndef A67_915_MISAN_TEODORA_SERVICE_H
#define A67_915_MISAN_TEODORA_SERVICE_H
class Service{
protected:
    FileOption* _adoptionList;
    Repository& _repo;

public:
    Service(FileOption*, Repository&);
    //Repository* getDogList() const { return _repoCsv; }
    void addDog(std::string breed, std::string name, int age, std::string photo );
    void deleteDog(std::string breed, std::string name);
    void updateDog(std::string breed, std::string name, int age, std::string photo);
    std::vector<Dog> getDog();
    void firstDogs();

    void AddDogAdoptionList(std::string breed, std::string name, int age, std::string photo);
    std::vector<Dog> getDogsAdoption();

    void chooseAdoptionList(const std::string&);
    void saveIntoFile() const;
};
#endif //A67_915_MISAN_TEODORA_SERVICE_H
