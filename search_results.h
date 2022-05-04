//
// Program Name:                  search_results.h
// Last Modified:                    05/02/22
// Modified By:                      Lauren Escobedo
// Program Description:          This is the header file for the search results page. It includes the class definition,
//                                         slot definitions, and included libraries
//

#ifndef SEARCH_RESULTS_H
#define SEARCH_RESULTS_H

#include <QListWidgetItem>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "edit_item.h"

class Main_Menu;

namespace Ui {
class Search_Results;
}

class Search_Results : public QDialog
{
    Q_OBJECT
   QString key;
public:
    explicit Search_Results(QWidget *parent = nullptr);
    ~Search_Results();
    QString result;
    void setKey(QString k);
        void displayResults();

private slots:
    void on_resultsDisplay_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::Search_Results *ui;
    QString returnValues;
    bool connOpen();


};

#endif // SEARCH_RESULTS_H
