//
// Program Name:                  main_menu.h
// Last Modified:                    04/24/22
// Modified By:                      Lauren Escobedo
// Program Description:          This is the header file for the main menu page. It includes the class definition,
//                                         slot definitions, and included libraries
//


#ifndef MAIN_MENU_H
#define MAIN_MENU_H

//necessary includes
#include "qr_search.h"
#include "search_results.h"

#include <QMainWindow>
#include <QFrame>
#include <QSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class Main_Menu;
}

//class definition
class Main_Menu : public QMainWindow
{
    Q_OBJECT
public:
    explicit Main_Menu(QWidget *parent = nullptr);
    ~Main_Menu();
      QString keyword;
private slots:
    void on_qrPageButton_clicked();
    void on_actionQRScanner_triggered();
    void on_searchButton_clicked();
    void on_actionDataDictionary_triggered();
    void on_addItemButton_clicked();
private:
    Ui::Main_Menu *ui;
    QR_Search *m_searchPage;
    void connOpen();
};

#endif // MAIN_MENU_H
