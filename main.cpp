#include "gui.h"
#include <QApplication>
#include <exceptions.h>
#include <QLabel>
#include <QGridLayout>
#include "guiUser.h"
#include "GUIMain.h"
#include "Service/service.h"
#include "dogswidget.h"
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    std::string file = "C:\\Users\\Misan\\Documents\\GitHub\\a89-915-Misan-Teodora\\list.txt";
    FileOption *readFile = new CsvRepo{};
    Repository repo{file};
    Service serv{readFile, repo};
//    Service *service = new Service{readFile, repo};
//    Repository *repo = new Repository{file};
//    Service *serv = new Service{file, repo};
    GUI gui{serv};
    gui.show();
    GUIMain gui1{serv};
    gui1.show();
    GUIADM gui2{serv};
    gui2.show();

//    DogsWidget guiNew{};
//    guiNew.show();
    return a.exec();
}

