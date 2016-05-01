#ifndef NEWDIALOG_HPP
#define NEWDIALOG_HPP

#include <QDialog>

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDialog(QWidget *parent = 0);
    ~NewDialog();

private:
    Ui::NewDialog *ui;
};

#endif // NEWDIALOG_HPP
