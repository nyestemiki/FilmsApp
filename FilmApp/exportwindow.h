#ifndef EXPORTWINDOW_H
#define EXPORTWINDOW_H

#include <QDialog>
#include "watchlistmodel.h"

namespace Ui { class exportwindow; }

class exportwindow : public QDialog {
    Q_OBJECT

    Ui::exportwindow *ui;

    WatchlistModel* watchlist_model; // Datamodel for watchlist

public:
    explicit exportwindow(WatchlistModel*, QWidget *parent = nullptr);
    ~exportwindow();

private slots:
    void on_cancel_clicked(); // Cancel window
    void on_csv_clicked(); // Export watchlist to CSV format
    void on_html_clicked(); // Export watchlist to HTML format
};

#endif // EXPORTWINDOW_H
