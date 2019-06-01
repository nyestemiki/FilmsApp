#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include "filmsmodel.h"

namespace Ui { class add; }

class add : public QDialog {
    Q_OBJECT

    Ui::add *ui;

    FilmsModel* films_model; // Datamodel for the window

public:
    explicit add(FilmsModel*, QWidget *parent = nullptr);
    ~add();

private slots:
    void on_cancel_clicked(); // Cancel window
    void on_addfilm_clicked(); // Add new film
};

#endif // ADD_H
