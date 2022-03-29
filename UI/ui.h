//
// Created by Misan on 4/7/2021.
//

#ifndef A67_915_MISAN_TEODORA_UI_H
#define A67_915_MISAN_TEODORA_UI_H

#include "../Service/service.h"

class UI{
public:
    UI(Service& serv);
    void run();
private:
    Service& _serv;
    void menu();
    void addUi();
    void deleteUi();
    void geAllElemsUi();
    void updateDogUi();

    void menuUser();
    void displayDogsUser();
    void adoptionList();
    void adoptionListBreed();
    void saveDogToFile();

};
#endif //A67_915_MISAN_TEODORA_UI_H
