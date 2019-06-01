#include "discover.h"
#include "ui_discover.h"
#include <QDesktopServices>
#include <QString>
#include <QUrl>

discover::discover(FilmsModel* fm, WatchlistModel* wm, QWidget *parent) :
    QDialog(parent), ui(new Ui::discover), films_model(fm), watchlist_model(wm) {

    ui->setupUi(this);
    index = 0; // Index of film in films_by_genre
    setup_genre(); // Loads the genres
    films_by_genre = films_model->get_films_by_genre(ui->genre->currentIndex()); // Get films by selected genre
}

discover::~discover() {
    delete ui;
}

// Close window
void discover::on_cancel_clicked() {
    close();
}

// Add film to watchlist
void discover::on_addToWatchlist_clicked() {
    watchlist_model->add_film(films_by_genre[index]);
}

// Discover new films
void discover::on_genre_currentIndexChanged(int index) {
    films_by_genre = films_model->get_films_by_genre(ui->genre->currentIndex()); // Getting films by selected genre
    index = 0; // Index starts from null after selecting new genre
    if(films_by_genre.empty()) // No films in the database
        ui->filmData->setText("No films in the database! Check back later...");
    else {
        QString link = QString::fromStdString(films_by_genre[index].get_trailer()); // Make QString grom STDString
        QDesktopServices::openUrl(QUrl(link)); // Open trailer in browser

        ui->filmData->setText(display(films_by_genre[index]).c_str()); // Updating new film's data
    }
}

// Go to next film
void discover::on_next_clicked() {
    index++; // The index is incremented to show the next film
    if(index >= films_by_genre.size()) // If the index exceeds the size, restart array
        index = 0;
    QString link = QString::fromStdString(films_by_genre[index].get_trailer()); // QString from STDString
    QDesktopServices::openUrl(QUrl(link)); // Open link in browser

    ui->filmData->setText(display(films_by_genre[index]).c_str()); // Updating new film's data
}

// Display film in long format
string discover::display(Film film) {
    string output = "<center><h1>";

    output += film.get_title();
    output += "</h1><h3>(";
    output += to_string(film.get_year()).c_str();
    output += ")</h3><h3>";
    output += to_string(film.get_likes()).c_str();
    output += " likes</h3></center>";

    return output;
}

// Set up genre-array
void discover::setup_genre() {
    for(std::string& genre : get_genres())
        ui->genre->addItem(genre.c_str());
}

// Returns vector of genres
vector<string> discover::get_genres(){
    return films_model->get_genres();
}
