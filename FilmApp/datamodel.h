#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QListView>
#include <QWidget>
#include <QAbstractListModel>
#include "repositoryfilm.h"
#include "film.h"

class DataModel : public QAbstractListModel {
public:
    Repository* repo;

    DataModel(QObject *parent);

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data (const QModelIndex& index, int role = Qt::DisplayRole) const;

    void add_film(Film); // Add new film to repository
    void delete_film(int); // Delete film from repository
};

#endif // DATAMODEL_H
