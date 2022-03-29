#include "gui.h"
#include <qlayout.h>
#include <QFormLayout>
#include <qgridlayout.h>
#include <vector>
#include <QMessageBox>
#include <exceptions.h>
#include <QLabel>

using namespace std;
GUI::~GUI()
{
}

GUI::GUI(Service &serv) :  _serv{serv} {
    this->setUpGUI();
    this->populateDogList();
    this->connectSignalsAndSlots();
}

void GUI::setUpGUI() {
    this->dogsListWidget = new QListWidget{};
    this->breedLineEdit = new QLineEdit{};
    this->nameLineEdit = new QLineEdit{};
    this->ageLineEdit = new QLineEdit{};
    this->photographLineEdit= new QLineEdit{};
    this->addButton = new QPushButton{"Add"};
    this->deleteButton = new QPushButton{"Delete"};
    this->updateButton = new QPushButton{"Update"};
    this->slider = new QSlider{};


    QVBoxLayout * mainLayout = new QVBoxLayout { this };
    mainLayout->addWidget(this->dogsListWidget);

    QBoxLayout::Direction direction;
    direction = QBoxLayout::LeftToRight;

    QBoxLayout* slider = new QBoxLayout{direction};

    //mainLayout->addWidget(slider);
    QFormLayout* dogsDetails = new QFormLayout{};
    dogsDetails->addRow("Breed", this->breedLineEdit);
    dogsDetails->addRow("Name", this->nameLineEdit);
    dogsDetails->addRow("Age", this->ageLineEdit);
    dogsDetails->addRow("Photograph", this->photographLineEdit);

    mainLayout->addLayout(dogsDetails);

    QGridLayout* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->addButton, 0, 0);
    buttonsLayout->addWidget(this->deleteButton, 0, 1);
    buttonsLayout->addWidget(this->updateButton, 1, 0);

    mainLayout->addLayout(buttonsLayout);
}

void GUI::populateDogList() {
    this->dogsListWidget->clear();

    vector<Dog> listDogs = this->_serv.getDog();
    for(Dog& d: listDogs)
        this->dogsListWidget->addItem(QString::fromStdString(d.getBreedDog() + "  " + d.getNameDog() + "  " + to_string(d.getAgeDog()) + "  " + d.getPhotoDog()));
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->dogsListWidget, &QListWidget::itemSelectionChanged, [this](){
        int selectedDog = this->getSelectedIndex();

        if(selectedDog < 0) return;

        Dog d = this->_serv.getDog()[selectedDog];
        this->breedLineEdit->setText(QString::fromStdString(d.getBreedDog()));
        this->nameLineEdit->setText(QString::fromStdString(d.getNameDog()));
        this->ageLineEdit->setText(QString::fromStdString(to_string(d.getAgeDog())));
        this->photographLineEdit->setText(QString::fromStdString(d.getPhotoDog()));
    });
    QObject::connect(this->addButton, &QPushButton::clicked, this, &GUI::addDog);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &GUI::deleteDog);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &GUI::updateDog);
}

int GUI::getSelectedIndex() const {
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

void GUI::addDog() {
    string breed = this->breedLineEdit->text().toStdString();
    string name = this->nameLineEdit->text().toStdString();
    int age = this->ageLineEdit->text().toInt();
    string photo = this->photographLineEdit->text().toStdString();

    try{
        this->_serv.addDog(breed, name, age, photo);
    }
    catch(Exception &e)
    {
        cout << endl << e.what() << endl;

    }

    this->populateDogList();
    int lastElem = this->_serv.getDog().size() -1;
    this->dogsListWidget->setCurrentRow(lastElem);
}

void GUI::deleteDog() {
    int selectedInd = this->getSelectedIndex();
    if(selectedInd < 0){
        QMessageBox::critical(this, "Error", "No dog was selected! :(");
        return;
    }

    Dog d = this->_serv.getDog()[selectedInd];
    this->_serv.deleteDog(d.getBreedDog(), d.getNameDog());

    this->populateDogList();
}

void GUI::updateDog() {
    string breed = this->breedLineEdit->text().toStdString();
    string name = this->nameLineEdit->text().toStdString();
    int age = this->ageLineEdit->text().toInt();
    string photo = this->photographLineEdit->text().toStdString();

    this->_serv.updateDog(breed, name, age, photo);

    this->populateDogList();
}

