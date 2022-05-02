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

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

Add_item::Add_item(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_item)
{
    ui->setupUi(this);
    connOpen();
}

Add_item::~Add_item()   {
    delete ui;
}

//closes database and removes the connection
void Add_item::connClose()  {
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}

//connecting to database
bool Add_item::connOpen()   {
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/laesc/OneDrive/Documents/ToolBuddy/test.db");
    if (mydb.open())    {
        ui->statusLabel->setText("Connected!");
        qDebug()<<("Connected");
        return true;
    }
    else    {
        ui->statusLabel->setText("Connection Not Successful...");
        qDebug()<<("Not Connected");
        return false;
    }
}

//resets all fields upon clicking reset button
void Add_item::on_resetButton_clicked() {
    ui->nameField->setText(" ");
    ui->locationField->setText(" ");
    ui->safetyField->setText(" ");
    ui->summaryField->setText(" ");
    ui->useField->setText(" ");
}

//passes data to database upon clicking submit button
void Add_item::on_submitButton_clicked()    {
    QString name, location, safety, summary, use;
    name =        ui->nameField->text();
    location =     ui->locationField->text();
    safety =        ui->safetyField->text();
    summary =   ui->summaryField->text();
    use =            ui->useField->text();

    QSqlQuery qry;
}

