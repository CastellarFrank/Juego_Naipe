#include "tablero.h"


Tablero::Tablero(QWidget *parent) : QWidget(parent)
{
    this->mainDir=":/mazo/";
    this->cartas=new QPixmap[15];
    this->reset();


}
void Tablero::reset(){
    this->cantidad=0;
    QString text;
    for(int i=0;i<15;i++){
        if(i<=2)
            text=mainDir+"Reverso.png";
        else
            text=mainDir+"blankwhite.png";
        cartas[i].load(text);
        this->aumentarCantidad();
    }
}

void Tablero::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    int varX=0,varY=0;
    int e=0,j=0,k=0;
    painter.drawPixmap(0,0,QPixmap(":/mazo/fondo.jpg"));
    for(int i=0;i<this->cantidad;i++){
        if(i==0){
            varX=varY=0;
        }else if(i<=2){
            varX=(250+(85*i));
        }else if(i>2){
            if(i==3){
                k=i;
            }
            if(i==9){
                k=0;
                j=i;
                e=116;
            }
            varX=85*(i-j-k);
            varY=220+e;
        }
        painter.drawPixmap(varX+9,varY+5,cartas[i]);
    }

}
void Tablero::aumentarCantidad(){
    this->cantidad++;
}
int Tablero::getCantidad()const{
    return cantidad;
}
void Tablero::cambiarDir(int pos, QString dir){
    QString temp;
    temp=this->mainDir+dir;
    this->cartas[pos].load(temp);
}
void Tablero::refresh(){
    update();

}



