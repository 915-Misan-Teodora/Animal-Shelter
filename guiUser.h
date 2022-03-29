//
// Created by Misan on 5/17/2021.
//

#ifndef A89_915_MISAN_TEODORA_GUIUSER_H
#define A89_915_MISAN_TEODORA_GUIUSER_H

#include <QMainWindow>
#include <service.h>
#include <QPushButton>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <QColorDialog>

class GUIADM : public QWidget{
private:
    Service& _serv;
public:
    GUIADM(Service&);
private:
    QListWidget* dogsListWidget;
    QListWidget* adoptionListWidget;
    QLineEdit* breedLineEdit, *nameLineEdit, *ageLineEdit, *photographLineEdit;
    QWidget* centralWidget;
    QPushButton* adoptButton;
    QDialog* color;


    void setUpGUI();
    void populateDogList();
    void populateAdoptList();
    void connectSignalAndSlots();
    int getSelectedIndex();
    void adoptDog();
};

#endif //A89_915_MISAN_TEODORA_GUIUSER_H
