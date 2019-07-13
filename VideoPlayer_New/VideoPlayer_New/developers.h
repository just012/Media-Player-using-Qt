#ifndef DEVELOPERS_H
#define DEVELOPERS_H

#include <QDialog>

namespace Ui {
class Developers;
}

class Developers : public QDialog
{
    Q_OBJECT

public:
    explicit Developers(QWidget *parent = 0);
    ~Developers();

private:
    Ui::Developers *ui;
};

#endif // DEVELOPERS_H
