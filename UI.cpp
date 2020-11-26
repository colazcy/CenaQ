#include "cenaq.h"
#include <QMessageBox>

void cenaq::setUI(){
    setWindowTitle(tr("CenaQ"));

    userNameLineEdit = new QLineEdit;
    userNameLineEdit->setText(tr("stu-001"));
    workingDirLineEdit = new QLineEdit;
    workingDirLineEdit->setText(QDir::currentPath());

    formLayout = new QFormLayout;
    formLayout->addRow(tr("Username:"),userNameLineEdit);
    formLayout->addRow(tr("Working Directory:"),workingDirLineEdit);

    setButton = new QPushButton(tr("Set"));
    saveButton = new QPushButton(tr("Save"));

    hboxLayout = new QHBoxLayout;
    hboxLayout->addWidget(setButton);
    hboxLayout->addWidget(saveButton);

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(hboxLayout);

    mainWindow = new QWidget;
    mainWindow->setLayout(mainLayout);

    setCentralWidget(mainWindow);

    aboutMenu = menuBar()->addMenu(tr("About"));

    aboutCenaQAction = new QAction(tr("About CenaQ"));
    aboutQtAction = new QAction(tr("About Qt"));
    aboutMenu->addAction(aboutCenaQAction);
    aboutMenu->addAction(aboutQtAction);
    saveSettings();
}
void cenaq::saveSettings(){
    userName = userNameLineEdit->text();
    workingDir = workingDirLineEdit->text();
}
void cenaq::setWorkingDir(){
    QString tmp = QFileDialog::getExistingDirectory();
    if(tmp.isEmpty())return;
    workingDirLineEdit->setText(tmp);
    saveSettings();
}
void cenaq::setActions(){
    connect(aboutCenaQAction,&QAction::triggered,[this]{
        QMessageBox::about(this,tr("About CenaQ"),tr("A simple cross-platform client of Cena.\n\nMade with love by colazcy.\n\nPowered by Qt."));
    });
    connect(aboutQtAction,&QAction::triggered,[this]{
        QMessageBox::aboutQt(this);
    });
    connect(setButton,&QPushButton::clicked,this,&cenaq::setWorkingDir);
    connect(saveButton,&QPushButton::clicked,this,&cenaq::saveSettings);
}
void cenaq::trayIconClicked(QSystemTrayIcon::ActivationReason reason){
    switch(reason){
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        setWindowState(Qt::WindowActive);
        show();
        break;
    default:
        break;
    }
}
void cenaq::closeEvent(QCloseEvent *event){
    event->ignore();
    hide();
}
void cenaq::setTray(){
    icon = new QIcon(":/icon/icon");
    setWindowIcon(*icon);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(*icon);
    trayIcon->setToolTip(tr("CenaQ"));
    trayIcon->show();

    setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint);
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(tr("Quit"),this,&QApplication::quit);
    trayIcon->setContextMenu(trayIconMenu);

    connect(trayIcon,&QSystemTrayIcon::activated,this,&cenaq::trayIconClicked);
}
