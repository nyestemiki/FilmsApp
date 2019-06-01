#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <vector>
#include <fstream>
#include "film.h"

class Repository {
public:
    std::vector<Film> storage;

    Repository();
    ~Repository();

    int size() const; // Returns size of the storage

    vector<Film> get_storage() const; // Returns the storage

    void add(Film); // Adds new film to the storage
    void delete_film(int); // Delete film by index

    Film* get_film_by_index(int); // Returns pointer to film with given index
    Film* get_film_by_title(string); // Returns pointer to the film with the given title

    bool find(Film); // Determines if the given film is in the storage
    bool find_by_title(string); // Determines if a filme with the given title is in the storage

    virtual string get_title_by_index(int) { return "Implement if needed"; }
    virtual void export_html() { return; }
    virtual void export_csv() { return; }

    virtual vector<Film> get_films_by_genre(int) { return vector<Film>(); }
    virtual vector<string> get_genres() { return vector<string>(); }
};

#endif // REPOSITORY_H
