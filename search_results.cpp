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
    connOpen();

}

////
///  destructor
////
Search_Results::~Search_Results()
{
    delete ui;
}

////
///  connecting to database
////
bool Search_Results::connOpen()   {
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE", "test.db");
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

////
///  This function will run the query requested from the main menu and
///   concatenate all of the applicable results into variable result. If the
///   query was successful, the result will be displayed and the status display
///   will print "Query Successful". If it failed, the result display will print
///   "No Match" and the status display will print the error.
////
void Search_Results::displayResults() {
    QSqlQuery qry("SELECT tool_id FROM tools WHERE tool_name LIKE 'hammer'"); //This is where you can insert a name of an item to test the database query!
//    qry.prepare("SELECT tool_id FROM tools WHERE tool_name LIKE %key");
//    qry.bindValue(0, key);
    while (qry.next())  {
        int i = 0;
        returnValues = qry.value(i).toString();
        ui->resultsDisplay->addItem(returnValues);
        i++;
    }

    if(qry.exec())    {
        ui->queryStatusDisplay->setText("Query Successful!");
    }
    else    {
        ui->resultsDisplay->addItem("No Match\n");
        ui->queryStatusDisplay->setText(qry.lastError().text());
    }
}

////
///   this is the function to entering an items page from the search results
////
void Search_Results::on_resultsDisplay_itemDoubleClicked(QListWidgetItem *item)
{
    result = item->text();
    Edit_Item page;
    page.exec();
}

void Search_Results::setKey(QString k)
{
    key = k;
    qDebug() << "Key was set " << key;
}
