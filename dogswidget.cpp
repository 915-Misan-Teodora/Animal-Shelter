//
// Created by Misan on 6/2/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DogsWidget.h" resolved

#include "dogswidget.h"
#include "ui_DogsWidget.h"

DogsWidget::DogsWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::DogsWidget) {
    ui->setupUi(this);
}

DogsWidget::~DogsWidget() {
    delete ui;
}
