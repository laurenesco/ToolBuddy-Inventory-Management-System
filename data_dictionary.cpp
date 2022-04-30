//
//Program Name:                  data_dictionary.cpp
//Last Modified:                     04/24/22
//Modified By:                       Lauren Escobedo
//Program Description:          This program is responsible for the functionality of the data dictionary page.
//                                        The data dictionary should present a file which contains the table blueprints,
//                                        this includes comments on the tables purpose, the names of columns, and
//                                        the data type expected for each column.


#include "data_dictionary.h"
#include "ui_data_dictionary.h"

Data_Dictionary::Data_Dictionary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Data_Dictionary)
{
    ui->setupUi(this);
}

Data_Dictionary::~Data_Dictionary()
{
    delete ui;
}
