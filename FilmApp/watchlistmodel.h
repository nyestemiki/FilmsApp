#ifndef WATCHLISTMODEL_H
#define WATCHLISTMODEL_H

#include <QListView>
#include <QWidget>
#include <QAbstractListModel>

#include "repositorywatchlist.h"
#include "film.h"
#include "datamodel.h"

class WatchlistModel : public DataModel {
public:
    WatchlistModel(QObject *parent);

    string get_title_by_index(int); // Returns title of the film on the given index

    void export_html(); // Exports storage into HTML format
    void export_csv(); // Exports the storage into CSV format
};

#endif // WATCHLISTMODEL_H
