#ifndef CENAQ_H
#define CENAQ_H

#include <QApplication>
#include <QMainWindow>
#include <QTranslator>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QWidget>
#include <QFileDialog>
#include <QDir>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QIcon>
#include <QSystemTrayIcon>
#include <QCloseEvent>

class cenaq : public QMainWindow
{
    Q_OBJECT

public:
    cenaq(QWidget *parent = nullptr);
    ~cenaq();
private:
    QString userName;
    QString workingDir;
    QLineEdit *userNameLineEdit;
    QLineEdit *workingDirLineEdit;
    QFormLayout *formLayout;
    QPushButton *setButton;
    QPushButton *saveButton;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *mainLayout;
    QWidget *mainWindow;
    QMenu *aboutMenu;
    QAction *aboutCenaQAction;
    QAction *aboutQtAction;
    QIcon *icon;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *trayAction;
    void setUI();
    void setActions();
    void setTray();
    void trayIconClicked(QSystemTrayIcon::ActivationReason reason);
protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void saveSettings();
    void setWorkingDir();
};
#endif // CENAQ_H
