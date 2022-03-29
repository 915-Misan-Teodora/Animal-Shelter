//
// Created by Misan on 5/17/2021.
//

#include <QVBoxLayout>
#include <QFormLayout>
#include "guiUser.h"

GUIADM::GUIADM(Service &serv) : _serv{serv}{
    this->setUpGUI();
    this->populateDogList();
    this->populateAdoptList();
    this->connectSignalAndSlots();
}

void GUIADM::setUpGUI() {
    this->dogsListWidget = new QListWidget{};
    this->adoptionListWidget = new QListWidget{};
    this->breedLineEdit = new QLineEdit{};
    this->nameLineEdit = new QLineEdit{};
    this->ageLineEdit = new QLineEdit{};
    this->photographLineEdit= new QLineEdit{};
    this->adoptButton = new QPushButton{"Adopt"};

    QVBoxLayout * mainLayout = new QVBoxLayout { this };
    mainLayout->addWidget(this->dogsListWidget);
    mainLayout->addWidget(this->adoptionListWidget);

    QFormLayout* dogsDetails = new QFormLayout{};
    dogsDetails->addRow("Breed", this->breedLineEdit);
    dogsDetails->addRow("Name", this->nameLineEdit);
    dogsDetails->addRow("Age", this->ageLineEdit);
    dogsDetails->addRow("Photograph", this->photographLineEdit);

    mainLayout->addLayout(dogsDetails);

    QGridLayout* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->adoptButton, 0, 0);

    mainLayout->addLayout(buttonsLayout);
}

void GUIADM::populateDogList() {
    this->dogsListWidget->clear();

    vector<Dog> listDogs = this->_serv.getDog();
    for(Dog& d: listDogs)
        this->dogsListWidget->addItem(QString::fromStdString(d.getBreedDog() + "  " + d.getNameDog() + "  " + to_string(d.getAgeDog()) + "  " + d.getPhotoDog()));
}

void GUIADM::populateAdoptList() {
    this->adoptionListWidget->clear();

    vector<Dog> listDogsAdopt = this->_serv.getDogsAdoption();
    for(Dog& d: listDogsAdopt)
        this->adoptionListWidget->addItem(QString::fromStdString(d.getBreedDog() + "  " + d.getNameDog() + "  " + to_string(d.getAgeDog()) + "  " + d.getPhotoDog()));
}

void GUIADM::connectSignalAndSlots() {
    QObject::connect(this->dogsListWidget, &QListWidget::itemSelectionChanged, [this](){
        int selectedDog = this->getSelectedIndex();

        if(selectedDog < 0) return;

        Dog d = this->_serv.getDog()[selectedDog];
        this->breedLineEdit->setText(QString::fromStdString(d.getBreedDog()));
        this->nameLineEdit->setText(QString::fromStdString(d.getNameDog()));
        this->ageLineEdit->setText(QString::fromStdString(to_string(d.getAgeDog())));
        this->photographLineEdit->setText(QString::fromStdString(d.getPhotoDog()));
    });
    QObject::connect(this->adoptButton, &QPushButton::clicked, this, &GUIADM::adoptDog);
}

int GUIADM::getSelectedIndex() {
    QModelIndexList selectedInd = this->dogsListWidget->selectionModel()->selectedIndexes();
    if(selectedInd.size() == 0){
        this->breedLineEdit->clear();
        this->nameLineEdit->clear();
        this->ageLineEdit->clear();
        this->photographLineEdit->clear();
        return -1;
    }

    int selInd = selectedInd.at(0).row();
    return selInd;
}

void GUIADM::adoptDog() {
    string breed = this->breedLineEdit->text().toStdString();
    string name = this->nameLineEdit->text().toStdString();
    int age = this->ageLineEdit->text().toInt();
    string photo = this->photographLineEdit->text().toStdString();
    this->_serv.AddDogAdoptionList(breed, name, age, photo);

    this->populateAdoptList();
    this->populateDogList();
    int lastElem = this->_serv.getDogsAdoption().size() -1;
    this->adoptionListWidget->setCurrentRow(lastElem);
}
