#include "main_menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Main_Menu w;
    w.setWindowTitle("Tool Buddy");
    w.show();


    return a.exec();
}


