//
// Program Name:                  search_results.h
// Last Modified:                    05/02/22
// Modified By:                      Lauren Escobedo
// Program Description:          This is the header file for the search results page. It includes the class definition,
//                                         slot definitions, and included libraries
//

#ifndef SEARCH_RESULTS_H
#define SEARCH_RESULTS_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class Search_Results;
}

class Search_Results : public QDialog
{
    Q_OBJECT

public:
    explicit Search_Results(QWidget *parent = nullptr);
    ~Search_Results();

private:
    Ui::Search_Results *ui;
    QString returnValues;
    QString result = "";

};

#endif // SEARCH_RESULTS_H
