#include "repositoryfilm.h"
#include "validate.h"
#include "filmnotvalidexception.h"
#include "filmnotfoundexception.h"
#include "filmalreadyaddedexception.h"

RepositoryFilm::RepositoryFilm() {
    fill(); // Loads some sample data
    read(); // Reads data from file

    // Loading the genres
    genres.push_back("Action");
    genres.push_back("Comedy");
    genres.push_back("Drama");
    genres.push_back("Horror");
    genres.push_back("Thriller");
}

RepositoryFilm::~RepositoryFilm() {
    write(); // Saves storage into file
}

// Returns vector of films by given genre
// NOTE: if no film exists by selected genre, returns all films
vector<Film> RepositoryFilm::get_films_by_genre(int genre) {
    vector<Film> films_by_genre;

    for(Film& film : storage)
        if(film.get_genre() == genres[genre])
            films_by_genre.push_back(film);

    return films_by_genre.empty() ? storage : films_by_genre;
}

// Loads sample films
void RepositoryFilm::fill() {
    add(Film("Alibi.com", "Comedy", 2017, 37, "https://www.imdb.com/title/tt5657028/videoplayer/vi2961029657?ref_=tt_ov_vi"));
    add(Film("American Pie", "Comedy", 1999, 46, "https://www.imdb.com/title/tt0163651/videoplayer/vi1622540569?ref_=tt_ov_vi"));
    add(Film("Before I Go To Sleep", "Thriller", 2014, 42, "https://www.imdb.com/title/tt1726592/videoplayer/vi2264837913?ref_=tt_ov_vi"));
    add(Film("Failure To Launch", "Comedy", 2006, 28, "https://www.imdb.com/title/tt0427229/videoplayer/vi3915186713?ref_=tt_ov_vi"));
    add(Film("Flatliners", "Thriller", 2017, 30, "https://www.imdb.com/title/tt2039338/videoplayer/vi537508121?ref_=tt_ov_vi"));
    add(Film("Inception", "Thriller", 2010, 64, "https://www.imdb.com/title/tt1375666/videoplayer/vi4219471385?ref_=tt_ov_vi"));
    add(Film("Johnny English", "Action", 2003, 23, "https://www.imdb.com/title/tt0274166/videoplayer/vi1284702489?ref_=tt_ov_vi"));
    add(Film("Killers", "Action", 2010, 33, "https://www.imdb.com/title/tt1103153/videoplayer/vi3390441241?ref_=tt_ov_vi"));
    add(Film("Marley And Me", "Drama", 2008, 40, "https://www.imdb.com/title/tt0822832/videoplayer/vi2121072665?ref_=tt_ov_vi"));
    add(Film("The Choice", "Drama", 2016, 51, "https://www.imdb.com/title/tt3797868/videoplayer/vi2516497689?ref_=tt_ov_vi"));
}

// Reads from file into the storage
void RepositoryFilm::read() {
    ifstream fin("films.csv");

    string title, genre, trailer, year, likes;

    while (getline(fin, title, ',')) {
        getline(fin, genre, ',');
        getline(fin, year, ',');
        getline(fin, likes, ',');
        getline(fin, trailer);

        Film film(title, genre, stoi(year), stoi(likes), trailer);
        try {
            add(film);
        } catch (FilmAlreadyAddedException e) {
            continue;
        }
    }

    fin.close();
}

// Saves storage in file
void RepositoryFilm::write() {
    ofstream fout("films.csv");

    if (fout.fail())
        return;

    for(Film& film: storage) {
        fout << film.get_title() << ",";
        fout << film.get_genre() << ",";
        fout << film.get_year() << ",";
        fout << film.get_likes() << ",";
        fout << film.get_trailer() << "\n";
    }

    fout.close();
}

vector<string> RepositoryFilm::get_genres() {
    return genres;
}
