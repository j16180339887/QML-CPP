#ifndef SETTINGDIALOG_HPP
#define SETTINGDIALOG_HPP

#include <QDialog>
#include <QStack>
#include <QString>
#include <QVBoxLayout>
#include <QRadioButton>

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QStack<QString> CloudDrives, QWidget *parent = 0);
    ~SettingDialog();

private:
    Ui::SettingDialog *ui;
    QStack<QRadioButton*> Drives;
};

#endif // SETTINGDIALOG_HPP
