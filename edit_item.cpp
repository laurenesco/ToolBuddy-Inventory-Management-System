#include "edit_item.h"
#include "ui_edit_item.h"

Edit_Item::Edit_Item(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Item)
{
    ui->setupUi(this);
}

Edit_Item::~Edit_Item() {
    delete ui;
}

void Edit_Item::setup() {
    QSqlQuery qry("SELECT tool_id FROM tools");
    if(qry.exec()){
        ui->toolIdLabel->setText(qry.value(0).toString());
    }
}
