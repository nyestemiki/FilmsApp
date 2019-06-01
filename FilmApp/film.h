#ifndef FILM_H
#define FILM_H

#include <string>

using namespace std;

class Film {

    string title;
    string genre;
    string trailer;
    int year;
    int likes;

public:
    Film();
    Film(string, string, int, int, string);

    // Getters
    string get_title() const;
    string get_genre() const;
    int get_year() const;
    int get_likes() const;
    string get_trailer() const;

    // Setters
    void set_title(string);
    void set_genre(string);
    void set_year(int);
    void set_likes(int);
    void set_trailer(string);
};

#endif // FILM_H
