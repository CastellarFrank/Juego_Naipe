#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "tablero.h"
#include "barajas.h"
#include <cstdlib>
#include <QString>
#include <QMessageBox>
#include <QWidget>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void nuevoJuego();
    QString SacarCarta()const;
    void tomarCarta();
    void dibujarCartas();
    void dibujar(int pos);
    void inicio();
    void liberar();



private:
    Ui::MainWindow *ui;
    QString *cartasSacadas;
    Tablero *tablero;
    Barajas *mazo;
    int cantCartasSacadas;
    void sumar();
    int sumaPC;
    int sumaJugador;
    int verificar();
    void terminarJuego();
    bool stay;
    void iniciarMazo();
    void volterCartasPc();
    bool iniciado;



private slots:

    void on_btnExit_clicked();
    void on_btnStay_clicked();
    void on_btnDeal_clicked();
    void on_btnNew_clicked();
};

#endif // MAINWINDOW_H
