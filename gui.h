#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <service.h>
#include <QPushButton>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlistwidget.h>

class GUI : public QWidget
{
private:
    Service& _serv;
public:
    GUI(Service&);
    ~GUI();

private:
    QListWidget* dogsListWidget;
    QLineEdit* breedLineEdit, *nameLineEdit, *ageLineEdit, *photographLineEdit;
    QWidget* centralWidget;
    QPushButton* addButton, *deleteButton, * updateButton;
    QSlider* slider;

    void setUpGUI();
    void populateDogList();
    void connectSignalsAndSlots();

    int getSelectedIndex() const;
    void addDog();
    void deleteDog();
    void updateDog();
};
#endif // GUI_H

