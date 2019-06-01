#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filmsmodel.h"
#include "watchlistmodel.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
    Q_OBJECT

    Ui::MainWindow *ui;

    // Storages
    FilmsModel* films_model; // Datamodel for films
    WatchlistModel* watchlist_model; // Datamodel for watchlist

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_admin_clicked(); // Selecting admin mode
    void on_user_clicked(); // Selectiing user mode
    void on_add_clicked(); // Adding new film
    void on_back_clicked(); // Back to main menu
    void on_edit_clicked(); // Edit film (selected)
    void on_back_2_clicked(); // Back to main menu
    void on_discover_clicked(); // Discover new films
    void on_export_2_clicked(); // EXport to CSV or HTML
    void on_remove_clicked(); // Remove film from watchlist (selected)
};

#endif // MAINWINDOW_H
