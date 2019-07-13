#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QDialog>

namespace Ui {
class playlist;
}

class playlist : public QDialog
{
    Q_OBJECT

public:
    explicit playlist(QWidget *parent = nullptr);
    void AddtoList(const QString);
    ~playlist();

private:
    Ui::playlist *ui;
};

#endif // PLAYLIST_H
