//
// Created by Misan on 4/7/2021.
//

#include "ui.h"
#include "../exceptions/exceptions.h"
#include<iostream>
using namespace std;
UI::UI(Service & serv) : _serv(serv){
}


void UI::menu() {
        cout << endl;
        cout <<"1. Add a new dog" << endl;
        cout <<"2. Delete a dog" << endl;
        cout <<"3. Update a dog" << endl;
        cout <<"4. List all elements" << endl;
        cout <<"5. EXIT the administration mode" << endl;
}

void UI::run() {
    int ok = 0, ok2, ok3, accessMode, choose, choose2;
    while (ok == 0) {
        cout << "Choose the access mode:" << endl << "1. Administrator Mode" << endl << "2. User Mode" << endl
             << "3. EXIT the program";
        cin >> accessMode;
        cout << accessMode;
        if (accessMode == 1) {
            ok2 = 0;
            while (ok2 == 0) {
                menu();
                cin >> choose;
                if (choose == 1)
                    try {
                        addUi();
                        cout << endl << "We add successfully";
                    } catch (Exception &e) {
                        cout << endl << e.what() << endl;
                    }
                else if (choose == 2)
                    try {
                        deleteUi();
                        cout << endl << "We delete it successfully";
                    } catch (Exception &e) {
                        cout << endl << e.what() << endl;
                    }
                else if (choose == 3)
                    try {
                        updateDogUi();
                        cout << endl << "We update the field of the dog successfully";
                    } catch (Exception &e) {
                        cout << endl << e.what() << endl;
                    }
                else if (choose == 4)
                    geAllElemsUi();
                else ok2 = 1;

            }
        } else if (accessMode == 2) {
            ok3=0;
            while (ok3 == 0) {
                menuUser();
                cin >> choose2;
                if (choose2 == 1)
                    displayDogsUser();
                else if (choose2 == 2)
                    adoptionList();
                else if (choose2 == 3)
                    adoptionListBreed();
                else if (choose2 == 4)
                    saveDogToFile();
                else if (choose2 == 5)
                    this->_serv.saveIntoFile();
                else if(choose2 ==6) ok3=1;
            }
        }
        else ok=1;
    }
}

void UI::addUi() {
    string breed, name, photo;
    int age;
    cout << "Enter a breed for a dog: " << endl;
    cin >> breed;
    cout << "Enter a name for a dog: " << endl;
    cin >> name;
    cout << "Enter the age for a dog: " << endl;
    cin >> age;
    cout << "Enter a link for a photo of the dog: " << endl;
    cin >> photo;
    this->_serv.addDog(breed, name, age, photo);
}

void UI::geAllElemsUi() {
    std::vector<Dog> list = _serv.getDog();
    for (int i = 0; i < list.size(); i++) {
        cout << "Breed: " << list[i].getBreedDog() << " Name: " << list[i].getNameDog() << " Age: "
        << list[i].getAgeDog() << " Link: " << list[i].getPhotoDog()<<endl;
    }
}

void UI::deleteUi() {
    string breed, name;
    cout << "Enter a breed for a dog: " << endl;
    cin >> breed;
    cout << "Enter a name for a dog: " << endl;
    cin >> name;
    this->_serv.deleteDog(breed, name);
}

void UI::updateDogUi() {
    string breed, name, newPhoto;
    int newAge;
    cout << "Enter a breed for a dog: ";
    cin >> breed;
    cout << "Enter a name for a dog: ";
    cin >> name;
    cout << "Enter the new age for a dog: ";
    cin >> newAge;
    cout << "Enter a link for a photo of the dog: ";
    cin >> newPhoto;
    this->_serv.updateDog(breed, name, newAge, newPhoto);
}

void UI::menuUser() {
    cout << endl;
    cout <<"1. See the dogs in the database" << endl;
    cout <<"2. See the adoption list" << endl;
    cout <<"3. See the adoption list after a breed" <<endl;
    cout <<"4. Write in a file the adoption list" << endl;
    cout <<"5. Open in app" << endl;
    cout <<"6. EXIT the user mode!"<<endl;
}

void UI::displayDogsUser() {
    int option;
    std::vector<Dog> list = this->_serv.getDog();
    cout << endl;
    int i = 0;
    int ok = 0;
    while (ok == 0 && i < list.size()) {
        cout << i + 1 << "." << "Breed: " << list[i].getBreedDog() << "  Name: "
             << list[i].getNameDog() << "   Age: " << list[i].getAgeDog() << "   Photograph "
             << list[i].getPhotoDog() << endl;

        cout << endl << "Do you want to adopt " << list[i].getNameDog() << " ?" << endl;
        cout << "1. YES" << endl << "2. NEXT PET" << endl;
        cin >> option;

        if (option == 1) {
            this->_serv.AddDogAdoptionList(list[i].getBreedDog(), list[i].getNameDog(),
                                           list[i].getAgeDog(), list[i].getPhotoDog());
        }
        if (i == list.size() - 1 && option == 2) {
            i = 0;
        } else if (i >= list.size() - 1 && option == 1) ok = 1;
        else if (option == 2) i++;
        list = this->_serv.getDog();
    }
}



void UI::adoptionList() {
    std::vector<Dog> list = _serv.getDogsAdoption();
    for (int i = 0; i < list.size(); i++) {
        cout << "Breed: " << list[i].getBreedDog() << " Name: " << list[i].getNameDog() << " Age: "
        << list[i].getAgeDog() << " Link: " << list[i].getPhotoDog()<<endl;
    }
}


void UI::adoptionListBreed() {
    std::vector<Dog> list = this->_serv.getDog();
    std::vector<Dog> newlist;
    string breed;
    int age;
    cout<<endl<<"Enter a breed for the dogs you want to adopt"<<endl;
    cin>>breed;
    cout<<"Enter the oldest age for a dog"<<endl;
    cin>>age;
    int i=0;
    int found=0;
    while(i< list.size()){
        if(list[i].getBreedDog() == breed && list[i].getAgeDog()<=age){
            Dog dog(list[i].getBreedDog(), list[i].getNameDog(),list[i].getAgeDog(), list[i].getPhotoDog());
            newlist.push_back(dog);
            found=1;
        }
        i++;
    }
    if(found==0) displayDogsUser();
    else{
        int i2=0;
        int ok=0, option;
        while(ok==0 && i2<newlist.size())
        {
            cout << i2 + 1 << "." << "Breed: " << newlist[i2].getBreedDog() << "   Name: "
                 << newlist[i2].getNameDog() << "   Age: " << newlist[i2].getAgeDog() << "   Photograph "
                 << newlist[i2].getPhotoDog() << endl;

            cout<<endl<<"Do you want to adopt "<<newlist[i2].getNameDog()<<" ?"<<endl;
            cout<<"1. YES"<<endl<<"2. NEXT PET"<<endl;
            cin>>option;

            if(option==1)
            {
                this->_serv.AddDogAdoptionList(newlist[i2].getBreedDog(), newlist[i2].getNameDog(),
                                    newlist[i2].getAgeDog(), newlist[i2].getPhotoDog());
            }
            if(i2== newlist.size()-1 && option==2)
            {   i2=0;
            }
            else if(i2>=newlist.size()-1 && option==1) ok=1;
            i2++;
        }
    }
}

void UI::saveDogToFile() {
    std::string filename;
    cout<<"Input the file name (absolute path): ";
    cin>>filename;
    try{
        this->_serv.chooseAdoptionList(filename);
        cout<<"The adoption list was added successfully";
    }
    catch(Exception &e){
        cout << e.what() <<endl;
    }
}



