#ifndef DISCOVER_H
#define DISCOVER_H

#include <QDialog>
#include "filmsmodel.h"
#include "watchlistmodel.h"

namespace Ui { class discover; }

class discover : public QDialog
{
    Q_OBJECT

    Ui::discover *ui;

    int index; // Index of film in the Datamodel
    FilmsModel* films_model; // Datamodel for films
    WatchlistModel* watchlist_model; // Datamodel for watchlist
    vector<Film> films_by_genre; // Vector of films by given genre

public:
    explicit discover(FilmsModel*, WatchlistModel*, QWidget *parent = nullptr);
    ~discover();

private slots:
    void on_cancel_clicked(); // Cancel window
    void on_genre_currentIndexChanged(int index); // Changing genre
    void on_addToWatchlist_clicked(); // Add film to watchlist
    void on_next_clicked(); // Next film (by selected genre)
    void setup_genre(); // Appending genres to the vector

    string display(Film); // Shows a film in long format

    vector<string> get_genres(); // Returns vector with genres
};

#endif // DISCOVER_H
