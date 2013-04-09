#include "carta.h"

Carta::Carta(int n, QString t)
{
    this->numero=n;
    this->tipo=t;
    this->add=false;
}
Carta::Carta(){
    this->numero=0;
    this->tipo="N/A";
}

int Carta::getNumero()const{
    return this->numero;
}
QString Carta::getTipo() const{
    return this->tipo;
}
void Carta::setNumero(int n){
    this->numero=n;
}
void Carta::setTipo(QString t){
    this->tipo=t;
}
bool Carta::igual(const Carta &c) const{
    return (c.getNumero() == this->numero ? true : false);
}
bool Carta::mayor(const Carta &c) const{
    return (c.getNumero() > this->numero ? true : false);
}
bool Carta::menor(const Carta &c) const{
    return (c.getNumero() < this->numero ? true : false);
}
bool Carta::getAdd()const{
    return this->add;
}
void Carta::setAdd(bool v){
    this->add=v;
}
