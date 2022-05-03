////
/// Program Name:                  add_item.cpp
/// Last Modified:                    04/24/22
/// Modified By:                      Lauren Escobedo
/// Program Description:        This program is responsible for the functionality of the add item page. This
///                                           page will allow the user to enter data for a number of fields and then will
///                                           pass that data to the database upon submission.
////

#include "add_item.h"
#include "ui_add_item.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <QSqlDriver>

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

////
///  closes database and removes the connection
////
void Add_item::connClose()  {
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}

////
///  create table if it doesnt exist
////
void Add_item::createTable()    {
    QSqlQuery qry;
    qry.prepare( "CREATE TABLE IF NOT EXISTS tools (tool_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, tool_name VARCHAR(30), logo BLOB)" );
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
            qDebug() << "Table 'tools' created!";
}

////
///  connecting to database
////
bool Add_item::connOpen()   {
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE", "test.db");
    mydb.setDatabaseName("C:/Users/laesc/OneDrive/Documents/ToolBuddy/test.db");
    if (mydb.open())    {
        ui->statusLabel->setText("Connected!");
        qDebug()<<("Connected");
    QSqlQuery qry;
    qry.prepare( "CREATE TABLE IF NOT EXISTS tools (tool_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, tool_name VARCHAR(30), logo BLOB)" );
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
            qDebug() << "Table 'tools' created!";
        return true;
    }
    else    {
        ui->statusLabel->setText("Connection Not Successful...");
        qDebug()<<("Not Connected");
        return false;
    }
}

////////////////////////////////// SLOTS BELOW ////////////////////////////////////////////

////
///  resets all fields upon clicking reset button
////
void Add_item::on_resetButton_clicked() {
    ui->nameField->setText(" ");
    ui->locationField->setText(" ");
    ui->safetyField->setText(" ");
    ui->summaryField->setText(" ");
    ui->useField->setText(" ");
}

////
///  passes data to database upon clicking submit button
////
void Add_item::on_submitButton_clicked()    {
    QString name, location, safety, summary, possibleUses;
    int idNumber;
    idNumber =             ui->testIdBox->text().toInt();
    name =                      ui->nameField->text();
    location =                  ui->locationField->text();
    safety =                     ui->safetyField->text();
    summary =                ui->summaryField->text();
    possibleUses =            ui->useField->text();

    QSqlQuery qry;

    qry.prepare("INSERT INTO  tools (tool_id, tool_name) "
                     "VALUES (:id, :name)");

    //binding all values to prevent sql injection attacks
    qry.bindValue(0, idNumber);
    qry.bindValue(1, name);
//    qry.bindValue(2, summary);
//    qry.bindValue(2, location);
//    qry.bindValue(3, possibleUses);
//    qry.bindValue(2, safety);


    if(qry.exec())    {
        QMessageBox::information(this,tr("Confirmation Message"),tr("Success!"));
        Add_item::close();
    }
    else    {
        //qDebug()<<QSqlDatabase::drivers();
        QMessageBox::critical(this,tr("Confirmation Message"),tr("Error, data was not saved."), qry.lastError().text());
        Add_item::close();
    }
    connClose();
}
/////////////////////////////////////////////////////////////////////////////////
//if error is unique constraint error - id is the same as another tool

//(qry.exec("INSERT INTO tools(tool_id, tool_name) "
//                   "VALUES (1008, 'test')"))
