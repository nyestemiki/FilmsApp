#include "filmsmodel.h"

#include <QListView>
#include <QWidget>
#include <QAbstractListModel>

#include "repositoryfilm.h"
#include "film.h"
#include "filmnotvalidexception.h"
#include "filmalreadyaddedexception.h"
#include "error.h"

FilmsModel::FilmsModel(QObject *parent) : DataModel(parent) {
    this->repo = new RepositoryFilm();
}

// Returns pointer to the film on given index
Film* FilmsModel::get_film_by_index(int index) {
    return repo->get_film_by_index(index);
}

// Returns pointer to the film with the given title
Film* FilmsModel::get_film_by_title(string title) {
    return repo->get_film_by_title(title);
}

// Return vector of films by selected genre
vector<Film> FilmsModel::get_films_by_genre(int genre) {
    return repo->get_films_by_genre(genre);
}

// Determines whether the given film is in the storage
bool FilmsModel::find(Film film) {
    return repo->find(film);
}

// Determines whether a film with the given title is in the storage
bool FilmsModel::find_by_title(string title) {
    return repo->find_by_title(title);
}

// Return vector of genres
vector<string> FilmsModel::get_genres() {
    return repo->get_genres();
}
