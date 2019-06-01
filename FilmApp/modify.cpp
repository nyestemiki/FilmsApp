#include "modify.h"
#include "ui_modify.h"
#include "error.h"
#include "filmtitletakenexception.h"
#include "filmnotvalidexception.h"
#include "validate.h"

modify::modify(FilmsModel* fm, int index, QWidget *parent) :
    QDialog(parent), ui(new Ui::modify), films_model(fm) {
    ui->setupUi(this);
    this->index = index;

    Film* film = films_model->get_film_by_index(index);

    ui->title_input->setPlaceholderText(film->get_title().c_str());
    ui->genre_input->setPlaceholderText(film->get_genre().c_str());
    ui->year_input->setPlaceholderText(QString::number(film->get_year()));
    ui->likes_input->setPlaceholderText(QString::number(film->get_likes()));
    ui->trailer_input->setPlaceholderText(film->get_trailer().c_str());
}

modify::~modify() {
    delete ui;
}

// Cancel window
void modify::on_cancel_clicked() {
    this->close();
}

// Modify film to modified attributes
void modify::on_modify_2_clicked() {
    Film* film = films_model->get_film_by_index(index); // Getting the film by index

    string title = ui->title_input->text() == "" ? film->get_title() : ui->title_input->text().toStdString(); // Changed title || Old title
    string genre = ui->genre_input->text() == "" ? film->get_genre() : ui->genre_input->text().toStdString(); // Changed genre || Old genre
    int year = ui->year_input->text().toInt() == 0 ? film->get_year() : ui->year_input->text().toInt(); // Changed year || Old year
    int likes = ui->likes_input->text().toInt() == 0 ? film->get_likes() : ui->likes_input->text().toInt(); // Changed likes || Old likes
    string trailer = ui->trailer_input->text() == "" ? film->get_trailer() : ui->trailer_input->text().toStdString(); // Changed trailer || Old trailer

    // Newly given title is taken
    if(films_model->find_by_title(ui->title_input->text().toStdString())) {
        this->close();
        error window(new FilmTitleTakenException());
        window.setModal(true);
        window.exec();
        return;
    }

    // Checking whether the film has valid attributes
    Validate validator(new Film(title, genre, year, likes, trailer));
    if(!validator.valid()) {
        this->close();
        error window(new FilmNotValidException());
        window.setModal(true);
        window.exec();
        return;
    } else {
        films_model->delete_film(index); // Deleting old redundant film
        films_model->add_film(Film(title, genre, year, likes, trailer)); // Adding newly created film
    }

    this->close();
}

// Delete film
void modify::on_delete_2_clicked() {
    films_model->delete_film(index);
    this->close();
}
