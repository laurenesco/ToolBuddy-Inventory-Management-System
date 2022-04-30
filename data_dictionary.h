//
//Program Name:                  data_dictionary.h
//Last Modified:                 04/24/22
//Modified By:                   Lauren Escobedo
//Program Description:           This is the header file for the data dicitonary page. It includes the class definition,
//                               slot definitions, and included libraries


#ifndef DATA_DICTIONARY_H
#define DATA_DICTIONARY_H

//necessary includes
#include <QDialog>
#include <QScrollArea>
#include <QTextEdit>
#include <QFile>
#include <QFrame>
#include <QTextStream>

namespace Ui {
class Data_Dictionary;
}

//class definition
class Data_Dictionary : public QDialog
{
    Q_OBJECT
public:
    explicit Data_Dictionary(QWidget *parent = nullptr);
    ~Data_Dictionary();
private:
    Ui::Data_Dictionary *ui;
};

#endif // DATA_DICTIONARY_H
