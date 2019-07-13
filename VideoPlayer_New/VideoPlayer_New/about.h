#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include "developers.h"
#include "license.h"

namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = 0);
    ~about();

private slots:
    void on_developers_button_clicked();

    void on_License_button_clicked();

private:
    Ui::about *ui;
    Developers *dev;
    License *license;
};

#endif // ABOUT_H
