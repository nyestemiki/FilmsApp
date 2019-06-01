#include "datamodel.h"
#include "film.h"
#include "filmalreadyaddedexception.h"
#include "filmnotvalidexception.h"
#include "filmalreadyinwatchlistexception.h"
#include "error.h"

DataModel::DataModel(QObject *parent) :
    QAbstractListModel(parent) {}

// Returns size of storage
int DataModel::rowCount(const QModelIndex& parent) const {
     return repo->size();
}

QVariant DataModel::data (const QModelIndex& index, int role) const {
    std::vector<Film> data = repo->get_storage();

    if (role == Qt::DisplayRole) {
        Film film = data[index.row()];

        string output = film.get_title();
        output += "\n\t\t(";
        output += film.get_genre();
        output += " movie from ";
        output += to_string(film.get_year());
        output += " with ";
        output += to_string(film.get_likes());
        output += " likes)";

        return QVariant(output.c_str());
    }

    return QVariant();
}

void DataModel::add_film(Film film) { // Add new film to repository
    try {
        beginInsertRows(QModelIndex(), repo->size(), repo->size());
        repo->add(film); // Film added
        endInsertRows();
    } catch (FilmNotValidException e) { // Error window
        error window(&e);
        window.setModal(true);
        window.exec();
    } catch (FilmAlreadyAddedException e) {
        error window(&e);
        window.setModal(true);
        window.exec();
    }
}

void DataModel::delete_film(int index) { // Delete film from repository
    if(index == repo->size()-1)
        beginRemoveRows(QModelIndex(), index, index);
    else
        beginRemoveRows(QModelIndex(), index, index+1);

    repo->delete_film(index);

    endRemoveRows();
}
