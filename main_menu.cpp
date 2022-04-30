//Program Name:                 main_menu.cpp
//Last Modified:                    04/24/22
//Modified By:                      Lauren Escobedo
//Program Description:         This program is responsible for the functionality of the main menu.
//                                         This page should present the home page of the application include the
//                                         main search menu and toolbar.

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

//move to QR code page from push button
void Main_Menu::on_qrPageButton_clicked()
{
    hide();
    m_searchPage = new QR_Search(this);
    m_searchPage->activateWindow();
}

//move to QR code from menu bar
void Main_Menu::on_actionQRScanner_triggered()
{
    m_searchPage = new QR_Search(this);
    m_searchPage->show();
}

//Search button clicked
void Main_Menu::on_searchButton_clicked()
{

}

//move to data dictionary from menu bar
void Main_Menu::on_actionDataDictionary_triggered()
{
    Data_Dictionary dataDictionaryPage;
    dataDictionaryPage.setModal(true);
    dataDictionaryPage.exec();
}

