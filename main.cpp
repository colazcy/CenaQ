#include "cenaq.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cenaq w;
    w.show();
    return a.exec();
}
