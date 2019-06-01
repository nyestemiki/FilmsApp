#ifndef REPOSITORYWATCHLIST_H
#define REPOSITORYWATCHLIST_H

#include <iostream>
#include <vector>
#include <fstream>
#include "film.h"
#include "repository.h"

class RepositoryWatchlist : public Repository {
public:
    RepositoryWatchlist();
    ~RepositoryWatchlist();

    void fill(); // Loads some sample data into the storage
    void export_html(); // Exports storage into HTML format
    void export_csv(); // Exports storage into CSV format

    std::string get_title_by_index(int); // Returns title of the film at the given index
};

#endif // REPOSITORYWATCHLIST_H
