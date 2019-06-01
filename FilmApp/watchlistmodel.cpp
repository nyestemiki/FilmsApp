#include "watchlistmodel.h"
#include <QListView>
#include <QWidget>
#include <QAbstractListModel>
#include "repositoryfilm.h"
#include "repositorywatchlist.h"
#include "film.h"
#include "error.h"
#include "filmalreadyaddedexception.h"

WatchlistModel::WatchlistModel(QObject* parent) : DataModel (parent) {
    this->repo = new RepositoryWatchlist();
}

// Returns title of the film on the given index
string WatchlistModel::get_title_by_index(int index) {
    return repo->get_title_by_index(index);
}

// Exports storage into HTML format
void WatchlistModel::export_html() {
    repo->export_html();
}

// Exports storage into CSV format
void WatchlistModel::export_csv() {
    repo->export_csv();
}
