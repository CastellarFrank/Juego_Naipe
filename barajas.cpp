#include "barajas.h"

Barajas::Barajas(int tam){
    this->tam=tam;
    this->cuantas=0;
    this->cartas=new Carta[tam];
}

int Barajas::getCuantas() const{
    return this->cuantas;
}

int Barajas::getNumeroCarta(int pos) const{
    return this->cartas[pos].getNumero();
}
QString Barajas::getTipoCarta(int pos) const{
    return this->cartas[pos].getTipo();
}
void Barajas::add_Al_Fondo(const Carta &c){
    this->addCartaPos(cuantas,c);
}
void Barajas::add_Al_Tope(const Carta &c){
    this->addCartaPos(0,c);
}
void Barajas::liberar(){
    delete [] this->cartas;
}

void Barajas::addCartaPos(int pos, const Carta &c){
    if(!cuantas<tam)
        tam+=10;
    Carta *temp=new Carta[tam];
    int e=0;
    for(int i=0;i<cuantas;i++){
        if(i==pos)
            e++;
        temp[e]=this->cartas[i];
        e++;
    }
    temp[pos].setNumero(c.getNumero());
    temp[pos].setTipo(c.getTipo());
    this->liberar();
    this->cartas=temp;
    this->cuantas++;

}
Carta Barajas::getCartaTope()const{
    return this->cartas[0];
}

Carta Barajas::getCartaFondo()const{
    return this->cartas[this->cuantas-1];
}
Carta Barajas::getCartaPos(int pos) const{
    return this->cartas[pos];
}
QString Barajas::getTipo_Valor_Carta(int pos) const{
    QString val;
    char num[10];
    val+=this->cartas[pos].getTipo();
    val+=itoa(this->cartas[pos].getNumero(),num,10);
    return val;
}
Barajas::~Barajas(){
    this->liberar();
}
void Barajas::revolverBaraja(){
    Carta *temp=new Carta[this->cuantas];
    srand(time(0));
    for(int i=0;i<this->cuantas;i++){
       int random=(rand()%this->cuantas);
       while(this->verificarAdd(random)){
           random=(rand()%this->cuantas);
       }
       temp[random]=this->cartas[i];
       temp[random].setAdd(false);
    }
    this->liberar();
    this->cartas=temp;
}


bool Barajas::verificarAdd(int pos) const{
    if(!this->cartas[pos].getAdd()){
        this->cartas[pos].setAdd(true);
        return false;
    }else{
        return true;
    }
}
int Barajas::getTam()const{
    return this->tam;
}

