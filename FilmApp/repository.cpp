#include "repository.h"

#include <iostream>
#include <vector>
#include <fstream>

#include "film.h"
#include "validate.h"
#include "filmnotvalidexception.h"
#include "filmalreadyaddedexception.h"
#include "filmnotfoundexception.h"

Repository::Repository() {}

Repository::~Repository() {}

// Returns the size of the storage
int Repository::size() const {
    return storage.size();
}

// Returns the storage
vector<Film> Repository::get_storage() const {
    return storage;
}

// Add new film
void Repository::add(Film film) {

    // Checking if the film is valid
    Validate validator(&film);
    if(!validator.valid()) // Not valid
        throw FilmNotValidException();

    if(find(film)) // Film already in the storage
        throw FilmAlreadyAddedException();

    storage.push_back(film); // Adding film
}

// Delete film
void Repository::delete_film(int index) {
    storage.erase(storage.begin()+index);
}

// Returns pointer to the film on given index
Film* Repository::get_film_by_index(int index) {
    return &storage[index];
}

// Returns pointer to the film by given title
Film* Repository::get_film_by_title(string title) {
    for(Film& film: storage)
        if(film.get_title() == title)
            return &film;
    throw FilmNotFoundException();
}

// Determines whether the given film is in the storage
bool Repository::find(Film film) {
    for(Film& f: storage)
        if(f.get_title() == film.get_title())
            return true;
    return false;
}

// Determines whether the film with the given title is in the storage
bool Repository::find_by_title(string title) {
    for(Film& f: storage)
        if(f.get_title() == title)
            return true;
    return false;
}

//template<typename T> // Maybe make find general?
//bool Repository::find(T t) {
//    for(Film& f: storage)
//        if(f.get_title() == t)
//            return true;
//    return false;
//}
