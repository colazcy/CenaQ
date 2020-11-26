#include "cenaq.h"

cenaq::cenaq(QWidget *parent)
    : QMainWindow(parent)
{
    setUI();
    setActions();
    setTray();
}

cenaq::~cenaq()
{
}

