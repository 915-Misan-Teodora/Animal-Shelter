//
// Created by Misan on 5/18/2021.
//

#ifndef A89_915_MISAN_TEODORA_GUIMAIN_H
#define A89_915_MISAN_TEODORA_GUIMAIN_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <service.h>

class GUIMain: public QWidget{
    Service& _serv;
public:
    GUIMain(Service&);
private:
        QPushButton* adminButton, *userButton;

        void setUpGUI();
        void connectSignalAndSlots();
        void adminGUI();
        void userGUI();
};
#endif //A89_915_MISAN_TEODORA_GUIMAIN_H
