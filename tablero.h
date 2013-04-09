#ifndef TABLERO_H
#define TABLERO_H
#include <QPixmap>
#include <QPainter>
#include <QString>
#include <QWidget>

class Tablero : public QWidget
{
public:
    Tablero(QWidget *parent=0);
    void cambiarDir(int pos,QString dir);
    int getCantidad()const;
    void aumentarCantidad();
    QString mainDir;
    void refresh();
    void paintEvent(QPaintEvent *event);
    void reset();
private:
    int cantidad;
    QPixmap *cartas;

protected:
};

#endif // TABLERO_H
