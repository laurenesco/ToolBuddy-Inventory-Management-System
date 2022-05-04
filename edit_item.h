#ifndef EDIT_ITEM_H
#define EDIT_ITEM_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <QSqlDriver>

namespace Ui {
class Edit_Item;
}

class Edit_Item : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Item(QWidget *parent = nullptr);
    ~Edit_Item();

private:
    Ui::Edit_Item *ui;
    void setup();
};

#endif // EDIT_ITEM_H
