//
//Program Name:                   add_item.h
//Last Modified:                     04/24/22
//Modified By:                       Lauren Escobedo
//Program Description:           This is the header file for the add item page. It includes the class definition,
//                                         slot definitions, and included libraries
//


#ifndef ADD_ITEM_H
#define ADD_ITEM_H

#include <QDialog>

namespace Ui {
class Add_item;
}

class Add_item : public QDialog
{
    Q_OBJECT

public:
    explicit Add_item(QWidget *parent = nullptr);
    ~Add_item();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Add_item *ui;
};

#endif // ADD_ITEM_H
