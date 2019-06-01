#ifndef REPOSITORYFILM_H
#define REPOSITORYFILM_H

#include <iostream>
#include <vector>
#include <fstream>
#include "film.h"
#include "repository.h"

class RepositoryFilm : public Repository {
public:
    vector<string> genres; // Genres to choose from

    RepositoryFilm();
    ~RepositoryFilm();

    vector<Film> get_films_by_genre(int); // Returns vector of films by selected genre

    void fill(); // Fills some sample data
    void read(); // Read data into the storage from file
    void write(); // Saves data into file
    vector<string> get_genres();
};

#endif // REPOSITORYFILM_H
