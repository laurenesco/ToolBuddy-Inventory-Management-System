//
//Program Name:                  add_item.cpp
//Last Modified:                     04/24/22
//Modified By:                       Lauren Escobedo
//Program Description:          This program is responsible for the functionality of the add item page. This
//                                        page will allow the user to enter data for a number of fields and then will
//                                        pass that data to the database upon submission.
//

#include "add_item.h"
#include "ui_add_item.h"

Add_item::Add_item(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_item)
{
    ui->setupUi(this);
}

Add_item::~Add_item()
{
    delete ui;
}

void Add_item::on_pushButton_2_clicked()
{
    ui->nameField->setText(" ");
    ui->locationField->setText(" ");
    ui->safetyField->setText(" ");
    ui->summaryField->setText(" ");
    ui->useField->setText(" ");
}

