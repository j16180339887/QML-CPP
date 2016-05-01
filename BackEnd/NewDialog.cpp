#include "NewDialog.hpp"
#include "ui_NewDialog.h"

NewDialog::NewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialog)
{
    ui->setupUi(this);
    setWindowTitle("New");
}

NewDialog::~NewDialog()
{
    delete ui;
}
