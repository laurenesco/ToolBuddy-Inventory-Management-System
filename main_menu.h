//
//Program Name:                  main_menu.h
//Last Modified:                    04/24/22
//Modified By:                      Lauren Escobedo
//Program Description:          This is the header file for the main menu page. It includes the class definition,
//                                        slot definitions, and included libraries


#ifndef MAIN_MENU_H
#define MAIN_MENU_H

//necessary includes
#include "qr_search.h"

#include <QMainWindow>
#include <QFrame>

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
private slots:
    void on_qrPageButton_clicked();
    void on_actionQRScanner_triggered();
    void on_searchButton_clicked();

    void on_actionDataDictionary_triggered();

private:
    Ui::Main_Menu *ui;
    QR_Search *m_searchPage;
};

#endif // MAIN_MENU_H
