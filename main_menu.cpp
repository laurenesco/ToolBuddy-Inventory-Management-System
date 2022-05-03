////
/// Program Name:                 main_menu.cpp
/// Last Modified:                    04/24/22
/// Modified By:                      Lauren Escobedo
/// Program Description:        This program is responsible for the functionality of the main menu.
///                                          This page should present the home page of the application include the
///                                          main search menu and toolbar.
////

#include "main_menu.h"
#include "qr_search.h"
#include "add_item.h"
#include "ui_main_menu.h"
#include "qr_search.h"
#include "data_dictionary.h"

////
///  constructor
////
Main_Menu::Main_Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_Menu)
{
    ui->setupUi(this);
    connOpen();
}

////
///  destructor
////
Main_Menu::~Main_Menu()
{
    delete ui;
}

////
///  connecting to database
////
void Main_Menu::connOpen(){
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/laesc/OneDrive/Documents/ToolBuddy/test.db");

    if (mydb.open())    {
        ui->statusLabel->setText("Connected!");
    }
    else    {
        ui->statusLabel->setText("Not Connected...");
    }
}

////////////////////////////////// SLOTS BELOW ////////////////////////////////////////////

////
///  switch to data dictionary page
////
void Main_Menu::on_actionDataDictionary_triggered()
{
    Data_Dictionary page;
    page.exec();
}

////
///  switch to qr search page
////
void Main_Menu::on_actionQRScanner_triggered()
{
    QR_Search page;
    page.exec();
}

////
///  switch to qr search page
////
void Main_Menu::on_qrPageButton_clicked()
{
    QR_Search page;
    page.exec();
}

////
///  trigger search results page
////
void Main_Menu::on_searchButton_clicked()
{
    keyword = ui->searchBar->text();
    Search_Results page;
    page.exec();
}

////
///  switch to add item page
////
void Main_Menu::on_addItemButton_clicked()
{
    Add_item page;
    page.exec();
}

