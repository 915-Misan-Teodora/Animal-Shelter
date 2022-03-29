//
// Created by Misan on 4/7/2021.
//

#ifndef A67_915_MISAN_TEODORA_PETS_H
#define A67_915_MISAN_TEODORA_PETS_H
using namespace std;
#include<string>
#include<iostream>
class Dog{
private:
    std::string breed;
    std::string name;
    int age;
    std::string photograph;
public:
    //the constructor
    Dog(const std::string& breed, const std::string& name, int age, const std::string& photograph);

    Dog();

    //copy constructor
    Dog(const Dog& d);

    //destructor
    ~Dog();

    //getters for the fields of e DOG
    std::string getBreedDog() const;
    std::string getNameDog() const;
    int getAgeDog() const;
    std::string getPhotoDog() const;

    //setters for the fields of e DOG
    void setAgeDog(int age) ;
    void setPhotoDog(std::string photoDog);

    //check if an element is in my array or not
    int foundDog(Dog d);

    Dog& operator=(const Dog& dogToGetValuesFrom);

    bool operator==(const Dog& anotherDog) const;

    friend std::istream &operator>>(std::istream &is, Dog &dog);

    friend std::ostream &operator<<(std::ostream &os, const Dog &dog);
};
#endif //A67_915_MISAN_TEODORA_PETS_H
