#ifndef RATE_H
#define RATE_H

#include <QDialog>
#include "filmsmodel.h"

namespace Ui { class rate; }

class rate : public QDialog {
    Q_OBJECT

    Ui::rate *ui;

    string title; // Film title

    FilmsModel* films_model; // Datamodel for films

public:
    explicit rate(FilmsModel*, string, QWidget *parent = nullptr);
    ~rate();

private slots:
    void on_cancel_clicked(); // Cancel window
    void on_like_clicked(); // Like film
};

#endif // RATE_H
