//Program Name:                 main_menu.cpp
//Last Modified:                    04/24/22
//Modified By:                      Lauren Escobedo
//Program Description:         This program is responsible for the functionality of the main menu.
//                                       This page should present the home page of the application include the
//                                       main search menu and toolbar.

#include "main_menu.h"
#include "qr_search.h"
#include "ui_main_menu.h"
#include "qr_search.h"
#include "data_dictionary.h"

//constructor
Main_Menu::Main_Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_Menu)
{
    ui->setupUi(this);
}

//destructor
Main_Menu::~Main_Menu()
{
    delete ui;
}


void Main_Menu::on_actionDataDictionary_triggered()
{
    Data_Dictionary page;
    page.exec();
}


void Main_Menu::on_actionQRScanner_triggered()
{
    QR_Search page;
    page.exec();
}


void Main_Menu::on_qrPageButton_clicked()
{
    QR_Search page;
    page.exec();
}


void Main_Menu::on_searchButton_clicked()
{
    //not complete
}

