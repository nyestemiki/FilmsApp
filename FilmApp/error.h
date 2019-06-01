#ifndef ERROR_H
#define ERROR_H

#include <QDialog>
#include "myexception.h"

namespace Ui { class error; }

class error : public QDialog {
    Q_OBJECT

    Ui::error *ui; // error window

    MyException* EXP; // Derived exception

public:
    explicit error(MyException*, QWidget *parent = nullptr);
    ~error();

private slots:
    void on_pushButton_clicked(); // Acknowledgeing the error message
};

#endif // ERROR_H
