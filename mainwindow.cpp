#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->iniciado=false;
    this->resize(632,500);
    this->setWindowTitle("Juego Naipe - 21");
    this->mazo=new Barajas();
    tablero=new Tablero();
    this->cartasSacadas=new QString[14];
    this->cantCartasSacadas=0;
    this->iniciarMazo();
    ui->gridLayout->addWidget(tablero,0,0,0,0);
    this->stay=false;


}
void MainWindow::iniciarMazo(){
    for(int i=0;i<4;i++){
        QString val;
        if(i==0){
            val="c";
        }else if(i==1){
            val="d";
        }else if(i==2){
            val="t";
        }else if(i==3){
            val="e";
        }
        for(int e=0;e<13;e++){
            mazo->addCartaPos(mazo->getCuantas(),Carta(e+1,val));
        }
    }
}

void MainWindow::inicio(){
    this->liberar();
    this->cartasSacadas=new QString[14];
    this->mazo->revolverBaraja();
    this->tablero->reset();
    this->cantCartasSacadas=0;
    this->nuevoJuego();
    this->dibujarCartas();
    this->tablero->refresh();
    this->stay=false;
    this->terminarJuego();
}

void MainWindow::nuevoJuego(){
    for(int i=0;i<4;i++){
        this->tomarCarta();
    }
}

QString MainWindow::SacarCarta()const{
    return this->mazo->getTipo_Valor_Carta(this->cantCartasSacadas);
}

void MainWindow::tomarCarta(){
    this->cartasSacadas[this->cantCartasSacadas]=this->SacarCarta();
    this->cantCartasSacadas++;
}

void MainWindow::dibujarCartas(){
    for(int i=2;i<this->cantCartasSacadas;i++){
        this->dibujar(i);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dibujar(int pos){
    QString temp=this->cartasSacadas[pos]+".gif";
    this->tablero->cambiarDir(pos+1,temp);
}


void MainWindow::liberar(){
    delete [] this->cartasSacadas;
}


void MainWindow::sumar(){
    this->sumaPC=this->sumaJugador=0;
    this->sumaPC=this->mazo->getNumeroCarta(0)+this->mazo->getNumeroCarta(1);
    for(int i=2;i<this->cantCartasSacadas;i++){
        this->sumaJugador+=this->mazo->getNumeroCarta(i);
    }
}
int MainWindow::verificar(){
    int var=0;
    if(stay){
        if(this->sumaJugador>21 && this->sumaPC<=21){
            var=1;
        }else if(sumaJugador<=21 && this->sumaPC>21){
            var=2;
        }else if(sumaJugador==this->sumaPC){
            var=3;
        }else if(sumaJugador>21 && sumaPC>21){
            var=4;
        }else if(sumaJugador<21 || sumaPC<21){
            int valor1=sumaJugador-21;
            int valor2=sumaPC-21;
            var=(valor1>valor2?6:5);
        }
    }else{
        if(this->sumaJugador>21){
            this->on_btnStay_clicked();
        }
    }

    return var;
}
void MainWindow::terminarJuego(){
    this->sumar();
    int num=this->verificar();
    if(num!=0){
        QString title,text;
        if(num==1){
            title="¡Has perdido!";
            text="Tu juego de cartas ha excedido el número 21.\nDeseas jugar un nuevo juego?";
        }else if(num==2){
            title="¡Has ganado!";
            text="¡Felicidades! Has sido el ganador de esta ronda.\nDeseas jugar un nuevo juego?";
        }else if(num==3){
            title="¡Empate!";
            text="Ha sido un empate.\nDeseas jugar un nuevo juego?";
        }else if(num==4){
            title="¡Han perdido!";
            text="Al parecer ambos jugadores han perdido.\nDeseas jugar un nuevo juego?";
        }else if(num==5){
            title="¡Has perdido!";
            text="Tu adversario ha estado más cerca al número 21.\nDeseas jugar un nuevo juego?";
        }else if(num==6){
            title="¡Has ganado!";
            text="Tu juego de cartas ha estado más cerca al número 21.\nDeseas jugar un nuevo juego?";
        }
        this->volterCartasPc();
        QMessageBox::StandardButton replay;
        replay=QMessageBox::information(this,title,text,
                                        QMessageBox::Retry | QMessageBox::Close,
                                        QMessageBox::Retry);
        if(replay==QMessageBox::Retry){
            this->on_btnNew_clicked();
        }else if(replay==QMessageBox::Close){
            this->on_btnExit_clicked();
        }
    }
}


void MainWindow::on_btnNew_clicked()

{
    this->iniciado=true;
    this->inicio();
}



void MainWindow::on_btnDeal_clicked()
{
    if(this->iniciado){
        this->tomarCarta();
        this->dibujar(this->cantCartasSacadas-1);
        this->tablero->refresh();
        this->terminarJuego();
    }


}

void MainWindow::on_btnStay_clicked()
{
    if(this->iniciado){
        this->stay=true;
        this->volterCartasPc();
        this->terminarJuego();
    }
}
void MainWindow::volterCartasPc(){
    this->dibujar(0);
    this->dibujar(1);
    this->tablero->refresh();
}

void MainWindow::on_btnExit_clicked()
{
    qApp->exit();
}
