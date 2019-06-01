#include "repositorywatchlist.h"
#include "filmalreadyinwatchlistexception.h"

RepositoryWatchlist::RepositoryWatchlist() {
    fill();
}
RepositoryWatchlist::~RepositoryWatchlist() {}

std::string RepositoryWatchlist::get_title_by_index(int index) {
    return storage[index].get_title();
}

// Exports storage in HTML format
void RepositoryWatchlist::export_html() {
    ofstream fout("watchlist.html");

    string s = "";
    s += "<!DOCTYPE html>\n";
    s += "<html>\n";
    s += "\t<head>\n";
    s += "\t<title>Watchlist</title>\n";
    s += "\t<link rel='stylesheet' href='style.css'>\n";
    s += "\t</head>\n";
    s += "\t<body>\n";
    s += "\t<div class='wrapper'>\n";
    s += "\t<div class='title'>WATCHLIST</div>\n";
    s += "\t<div class='row header'>\n";
    s += "\t<span>Titel</span>\n";
    s += "\t<span>Genre</span>\n";
    s += "\t<span>Jahr</span>\n";
    s += "\t<span>Likes</span>\n";
    s += "\t<span>Trailer</span>\n";
    s += "\t</div>\n";
    for (Film& film : storage) {
        s += "\t<div class='row'>\n";
        s += "\t<span>" + film.get_title() + "</span>\n";
        s += "\t<span>" + film.get_genre() + "</span>\n";
        s += "\t<span>" + to_string(film.get_year()) + "</span>\n";
        s += "\t<span>" + to_string(film.get_likes()) + "</span>\n";
        s += "\t<span><a href='" + film.get_trailer() + "'> Watch </a></span>\n";
        s += "\t</div>\n";
    }
    s += "\t</div>\n";
    s += "\t</body>\n";
    s += "</html>\n";
    fout << s;

    fout.close();
}

// Exports storage in CSV format
void RepositoryWatchlist::export_csv() {
    ofstream fout("watchlist.csv");

    for (Film& film : storage) {
        fout << film.get_title() << ",";
        fout << film.get_genre() << ",";
        fout << film.get_year() << ",";
        fout << film.get_likes() << ",";
        fout << film.get_trailer() << "\n";
    }

    fout.close();
}

// Loads sample watchlist
void RepositoryWatchlist::fill() {
    add(Film("Alibi.com", "Comedy", 2017, 37, "https://www.imdb.com/title/tt5657028/videoplayer/vi2961029657?ref_=tt_ov_vi"));
    add(Film("Failure To Launch", "Comedy", 2006, 28, "https://www.imdb.com/title/tt0427229/videoplayer/vi3915186713?ref_=tt_ov_vi"));
    add(Film("Flatliners", "Thriller", 2017, 30, "https://www.imdb.com/title/tt2039338/videoplayer/vi537508121?ref_=tt_ov_vi"));
    add(Film("Johnny English", "Action", 2003, 23, "https://www.imdb.com/title/tt0274166/videoplayer/vi1284702489?ref_=tt_ov_vi"));
    add(Film("Killers", "Action", 2010, 33, "https://www.imdb.com/title/tt1103153/videoplayer/vi3390441241?ref_=tt_ov_vi"));
    add(Film("Marley And Me", "Drama", 2008, 40, "https://www.imdb.com/title/tt0822832/videoplayer/vi2121072665?ref_=tt_ov_vi"));
}
