//
// Created by Misan on 6/2/2021.
//

#ifndef A89_915_MISAN_TEODORA_DOGSWIDGET_H
#define A89_915_MISAN_TEODORA_DOGSWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class DogsWidget; }
QT_END_NAMESPACE

class DogsWidget : public QWidget {
Q_OBJECT

public:
    explicit DogsWidget(QWidget *parent = nullptr);

    ~DogsWidget() override;

private:
    Ui::DogsWidget *ui;
};

#endif //A89_915_MISAN_TEODORA_DOGSWIDGET_H
