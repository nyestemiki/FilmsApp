#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add.h"
#include "modify.h"
#include "rate.h"
#include "exportwindow.h"
#include "discover.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0); // Application starts with the main menu

    // Model for films
    films_model = new FilmsModel(this);
    ui->filmList->setModel(films_model);

    // Model for watchlist
    watchlist_model = new WatchlistModel(this);
    ui->watchList->setModel(watchlist_model);
}

MainWindow::~MainWindow() {
    delete ui;
}


/*Main Menu*/

// Switches to admin window
void MainWindow::on_admin_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

// Switches to user window
void MainWindow::on_user_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}


/*Admin*/

// Goes back to main menu
void MainWindow::on_back_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

// Opens add-window
void MainWindow::on_add_clicked() {
    add window(films_model);
    window.setModal(true);
    window.exec();
}

// Opens edit-window
void MainWindow::on_edit_clicked() {
    int index = ui->filmList->selectionModel()->selectedIndexes().first().row(); // Index of selected film
    modify window(films_model, index);
    window.setModal(true);
    window.exec();
}


/*User*/

// Goes back to main menu
void MainWindow::on_back_2_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

// Opens discover-window
void MainWindow::on_discover_clicked() {
    discover window(films_model, watchlist_model); // Rate popup-window
    window.setModal(true);
    window.exec();
}

// Export popup-window
void MainWindow::on_export_2_clicked() {
    exportwindow window(watchlist_model); // Rate popup-window
    window.setModal(true);
    window.exec();
}

// Removes film from watchlist
void MainWindow::on_remove_clicked() {
    int index = ui->watchList->selectionModel()->selectedIndexes().first().row(); // Index of selected film
    string title = watchlist_model->get_title_by_index(index); // Title of selected film
    watchlist_model->delete_film(index); // Removes film from the storage (watchlist)

    rate window(films_model, title); // Rate popup-window
    window.setModal(true);
    window.exec();
}
