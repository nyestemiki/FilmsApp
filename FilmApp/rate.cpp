#include "rate.h"
#include "ui_rate.h"
#include "error.h"
#include "filmnotfoundexception.h"

rate::rate(FilmsModel* fm, string title, QWidget *parent) :
    QDialog(parent), ui(new Ui::rate), films_model(fm) {
    ui->setupUi(this);
    this->title = title;
}

rate::~rate() {
    delete ui;
}

// Cancel window
void rate::on_cancel_clicked() {
    this->close();
}

// Rate film
void rate::on_like_clicked() {
    try {
        Film* film = films_model->get_film_by_title(title); // Film with given title (unique key)
        int film_likes = film->get_likes(); // Likes of the selected film
        film->set_likes(film_likes+1); // Incrementing the likes of the film
    } catch (FilmNotFoundException e) { // Film no longer in the database
        error window(new FilmNotFoundException());
        window.setModal(true);
        window.exec();
    }

    this->close();
}
