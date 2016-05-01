#include "MainWindow.hpp"
#include "ui_QML.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QQuickWidget *view = new QQuickWidget(QUrl("qrc:/Qml/FrontEnd/main.qml"));
    view->setResizeMode(QQuickWidget::SizeRootObjectToView);
//    view->setSource(QUrl("qrc:/Qml/FrontEnd/main.qml"));
//    ui->verticalLayout->addWidget(container);
//    ui->verticalLayout->addWidget(view);
    ui->verticalLayout->addWidget(view);
//    QQuickItem *QML = view->rootObject();
//    connect( QML, &QQuickWidget::statusChanged, this, SLOT(onWindowCloseSlots()) );
//    ui->QML->setSource(QUrl("qrc:/Qml/FrontEnd/main.qml"));
    QML = view->rootObject();
//    connect( QML, SIGNAL(onWindowClose()), this, SLOT(close()) );
//    view->rootObject().findChild<QObject*>("gmailLink");

    QRect rec = QApplication::desktop()->screenGeometry();
    int width  = int(rec.width() / 1.5);
    int height = int(rec.height() / 1.5);
    this->setBaseSize(width, height);
    this->resize(width, height);

    QAction *minimizeAction = new QAction(QObject::tr("Mi&nimize"), QML);
    QML->connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
    QAction *maximizeAction = new QAction(QObject::tr("Ma&ximize"), QML);
    QML->connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));
    QAction *restoreAction = new QAction(QObject::tr("&Restore"), QML);
    QML->connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    QAction *quitAction = new QAction(QObject::tr("&Quit"), QML);
    QML->connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    QMenu *trayIconMenu = new QMenu();
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(maximizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon(QPixmap(":/Image/Resourse/Images/icon.png")));
    trayIcon->show();
    connect( trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
             this, SLOT(onSystemTrayIconAction(QSystemTrayIcon::ActivationReason)) );

    // See MainWindow::connects()
    connects();

    /* Fake data */
    CloudDrives.push("Google \t 10G \t 3G \t 1G");
    CloudDrives.push("OneDrive \t 10G \t 3G \t 1G");

    /* Update all drive info */
    updateQML();
}

void MainWindow::connects()
{
    connect( QML, SIGNAL(onWindowClose()), this, SLOT(onWindowClose()) );
    connect( QML, SIGNAL(onWindowMinimum()), this, SLOT(onWindowMinimum()) );
    connect( QML, SIGNAL(onWindowMaximum()), this, SLOT(onWindowMaximum()) );
    connect( QML, SIGNAL(onWindowNormal()), this, SLOT(onWindowNormal()) );
    connect( QML, SIGNAL(onWindowHide()), this, SLOT(onWindowHide()) );
    connect( QML, SIGNAL(onWindowShow()), this, SLOT(onWindowShow()) );
    connect( QML, SIGNAL(onWindowMove(QPointF)), this, SLOT(onWindowMove(QPointF)) );
    connect( QML, SIGNAL(onSettingClick()), this, SLOT(onSettingClick()) );
    connect( QML, SIGNAL(onNewClick()), this, SLOT(onNewClick()) );
}

void MainWindow::updateQML()
{
    QVariantList drives;
    for (int i = 0; i < CloudDrives.size(); i++) {
        drives << CloudDrives[i];
    }
    /* QML::updateQMLDrives(CloudDrives) */
    QMetaObject::invokeMethod(QML, "updateQMLDrives",
                              Q_ARG(QVariant, QVariant::fromValue(drives)));
}

MainWindow::~MainWindow()
{
    delete QML;
    delete ui;
}

void MainWindow::onWindowClose()
{
    this->close();
}

void MainWindow::onWindowMinimum()
{
    this->showMinimized();
}

void MainWindow::onWindowMaximum()
{
    this->showMaximized();
}

void MainWindow::onWindowNormal()
{
    this->showNormal();
}

void MainWindow::onWindowHide()
{
    this->hide();
}

void MainWindow::onWindowShow()
{
    this->show();
}

void MainWindow::onWindowMove(QPointF delta)
{;
    this->move(this->pos() + delta.toPoint());
}

void MainWindow::onSystemTrayIconAction(QSystemTrayIcon::ActivationReason reason)
{
    /* When left mouse click tray icon */
    if (reason == QSystemTrayIcon::Trigger) {
        this->showNormal();
        QApplication::setActiveWindow(this);
    }
}

void MainWindow::onSettingClick()
{
//    CloudDrives.push("Google \t 10G \t 3G \t 1G");
//    CloudDrives.push("OneDrive \t 10G \t 3G \t 1G");
    SettingDialog setting(CloudDrives);
    setting.setModal(false);
    setting.exec();
}

void MainWindow::onNewClick()
{
    NewDialog newItem;
    newItem.setModal(false);
    newItem.exec();
}
