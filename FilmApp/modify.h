#ifndef MODIFY_H
#define MODIFY_H

#include <QDialog>

#include "filmsmodel.h"

namespace Ui { class modify; }

class modify : public QDialog {
    Q_OBJECT

    Ui::modify *ui;

    int index; // Index of film in the datamodel

    FilmsModel* films_model; // Datamodel for films

public:
    explicit modify(FilmsModel* fm, int, QWidget *parent = nullptr);
    ~modify();

private slots:
    void on_cancel_clicked(); // Cancel window
    void on_modify_2_clicked(); // Modify film to changed attributes
    void on_delete_2_clicked(); // Delete selected film
};

#endif // MODIFY_H
