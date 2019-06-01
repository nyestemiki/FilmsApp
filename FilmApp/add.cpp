#include "add.h"
#include "ui_add.h"

add::add(FilmsModel* fm, QWidget *parent) :
    QDialog(parent), ui(new Ui::add), films_model(fm) {
    ui->setupUi(this);
}

add::~add() {
    delete ui;
}

// Cancel window
void add::on_cancel_clicked() {
    this->close();
}

// Add new film
void add::on_addfilm_clicked() {
    Film film(
        ui->title_input->text().toStdString(),
        ui->genre_input->text().toStdString(),
        ui->year_input->text().toInt(),
        ui->likes_input->text().toInt(),
        ui->trailer_input->text().toStdString()
    );

    films_model->add_film(film);
    this->close();
}
