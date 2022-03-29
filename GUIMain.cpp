//
// Created by Misan on 5/18/2021.
//

#include <QGridLayout>
#include "GUIMain.h"
#include "gui.h"
#include "guiUser.h"

GUIMain::GUIMain(Service &serv) : _serv(serv){
    this->setUpGUI();
    this->connectSignalAndSlots();
}

void GUIMain::setUpGUI() {
    this->adminButton = new QPushButton{"Admin"};
    this->userButton = new QPushButton{"User"};

    QVBoxLayout * mainLayout = new QVBoxLayout { this };

    QGridLayout* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->adminButton, 0, 0);
    buttonsLayout->addWidget(this->userButton, 0, 1);

    mainLayout->addLayout(buttonsLayout);
}

void GUIMain::connectSignalAndSlots() {
    QObject::connect(this->adminButton, &QPushButton::clicked, this, &GUIMain::adminGUI);
    QObject::connect(this->userButton, &QPushButton::clicked, this, &GUIMain::userGUI);
}

void GUIMain::adminGUI() {
    GUIADM guiADM{this->_serv};
    guiADM.show();
}

void GUIMain::userGUI() {
    this->hide();
    GUI gui{this->_serv};
    gui.show();
}
