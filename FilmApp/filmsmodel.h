#ifndef FILMSMODEL_H
#define FILMSMODEL_H

#include <QListView>
#include <QWidget>
#include <QAbstractListModel>

#include "repositoryfilm.h"
#include "film.h"
#include "datamodel.h"

class FilmsModel : public DataModel {
public:
    FilmsModel(QObject*);

    Film* get_film_by_index(int); // Returns pointer to film at given index
    Film* get_film_by_title(string); // Returns pointer to film by given title (unique key)

    vector<Film> get_films_by_genre(int); // Returns array of films by given genre

    vector<string> get_genres();

    bool find(Film); // Determines if given film is in the list
    bool find_by_title(string); // Determines if a film by the given title is in the list
};

#endif // FILMSMODEL_H
