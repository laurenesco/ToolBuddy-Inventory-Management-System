////
/// Program Name:                qr_search.cpp
/// Last Modified:                  04/24/22
/// Modified By:                     Lauren Escobedo
/// Program Description:       This program is responsible for the functionality of the qr search page.
///                                         This includes connecting to the camera, scanning for new cameras,
///                                         displaying the viewfinder, and utilizing Zebra to scan the qr code.
////

#include "search_results.h"
#include "ui_search_results.h"

////
///  constructor
////
Search_Results::Search_Results(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search_Results)
{
    ui->setupUi(this);
    displayResults();
}

////
///  destructor
////
Search_Results::~Search_Results()
{
    delete ui;
}

////
///  This function will run the query requested from the main menu and
///   concatenate all of the applicable results into variable result. If the
///   query was successful, the result will be displayed and the status display
///   will print "Query Successful". If it failed, the result display will print
///   "No Match" and the status display will print the error.
////
void Search_Results::displayResults() {
    QSqlQuery qry("SELECT * FROM tools");
    while (qry.next())  {
        int i = 0;
        returnValues = qry.value(i).toString();
        result += returnValues + "\n";
        i++;
    }

    if(qry.exec())    {
        ui->resultsDisplay->setText(result);
        ui->queryStatusDisplay->setText("Query Successful!");
    }
    else    {
        ui->resultsDisplay->setText("No Match\n");
        ui->queryStatusDisplay->setText(qry.lastError().text());
    }
}

