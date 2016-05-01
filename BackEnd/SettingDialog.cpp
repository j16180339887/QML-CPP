#include "SettingDialog.hpp"
#include "ui_SettingDialog.h"

SettingDialog::SettingDialog(QStack<QString> CloudDrives, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    setWindowTitle("Setting");

    /* Dynamically add radio button to SettingDialog */
    Drives.resize(CloudDrives.size());
    QVBoxLayout *DriveLayout = new QVBoxLayout();
    for (int i = 0; i< CloudDrives.size(); i++)
    {
        Drives[i] = new QRadioButton();
        Drives[i]->setText(CloudDrives[i]);
        DriveLayout->addWidget(Drives[i]);
    }
    ui->DrivesLabel->setLayout(DriveLayout);
}

SettingDialog::~SettingDialog()
{
    delete ui;
}
