#include "error.h"
#include "ui_error.h"

error::error(MyException* exp, QWidget *parent) :
    QDialog(parent), ui(new Ui::error), EXP(exp) {
    ui->setupUi(this);

    ui->label->setText(EXP->render().c_str());
}

error::~error() {
    delete ui;
}

// Close window
void error::on_pushButton_clicked() {
    close();
}
