#include "film.h"
#include <iostream>
#include <string>
using namespace std;

Film::Film() {
    title = "";
    genre = "";
    year = 0;
    likes = 0;
    trailer = "";
}

Film::Film(string title, string genre, int year, int likes, string trailer) {
    this->title = title;
    this->genre = genre;
    this->year = year;
    this->likes = likes;
    this->trailer = trailer;
}

// Getters
string Film::get_title() const { return title; }
string Film::get_genre() const { return genre; }
int Film::get_year() const { return year; }
int Film::get_likes() const { return likes; }
string Film::get_trailer() const { return trailer; }

// Setters
void Film::set_title(string title) { this->title = title; }
void Film::set_genre(string genre) { this->genre = genre; }
void Film::set_year(int year) { this->year = year; }
void Film::set_likes(int likes) { this->likes = likes; }
void Film::set_trailer(string trailer) { this->trailer = trailer; }
