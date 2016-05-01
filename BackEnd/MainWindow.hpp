#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QQuickWidget>
#include <QQuickItem>
#include <QWidget>
#include <QAction>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QSize>
#include <QDesktopWidget>
#include <QStack>
#include <QString>
#include <QMetaObject>
#include <QVariantList>
#include "SettingDialog.hpp"
#include "NewDialog.hpp"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onWindowClose();
    void onWindowMinimum();
    void onWindowMaximum();
    void onWindowNormal();
    void onWindowHide();
    void onWindowShow();
    void onWindowMove(QPointF delta);
    void onSystemTrayIconAction(QSystemTrayIcon::ActivationReason reason);
    void onSettingClick();
    void onNewClick();

private:
    void connects();
    void updateQML();
    Ui::MainWindow *ui;
    QQuickItem *QML;
    QStack<QString> CloudDrives;
};

#endif // MAINWINDOW_HPP
