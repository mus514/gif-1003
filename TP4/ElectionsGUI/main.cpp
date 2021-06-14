#include "electionsgui.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ElectionsGUI w;
    w.show();
    return a.exec();
}
