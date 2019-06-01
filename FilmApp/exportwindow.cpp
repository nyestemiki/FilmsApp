#include "exportwindow.h"
#include "ui_exportwindow.h"

exportwindow::exportwindow(WatchlistModel* wm, QWidget *parent) :
    QDialog(parent), ui(new Ui::exportwindow), watchlist_model(wm) {
    ui->setupUi(this);
}

exportwindow::~exportwindow() {
    delete ui;
}

// Cancel window
void exportwindow::on_cancel_clicked() {
    this->close();
}

// Export storage to CSV format
void exportwindow::on_csv_clicked() {
    watchlist_model->export_csv();
    this->close();
}

// Export storage to HTML format
void exportwindow::on_html_clicked() {
    watchlist_model->export_html();
    this->close();
}
