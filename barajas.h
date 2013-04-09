#ifndef BARAJAS_H
#define BARAJAS_H
#include "carta.h"
#include <QString>
#include <cstdlib>
#include <time.h>
using namespace std;

class Barajas
{
public:
    Barajas(int tam=52);
    int getCuantas()const;
    int getNumeroCarta(int pos) const; //las posiciones incician desde 0
    QString getTipoCarta(int pos) const; //las posiciones incician desde 0
    void add_Al_Tope(const Carta &c);
    void add_Al_Fondo(const Carta &c);
    void liberar();
    void liberarNum();
    void addCartaPos(int pos, const Carta &c); //las posiciones incician desde 0
    Carta getCartaTope()const;
    Carta getCartaFondo()const;
    Carta getCartaPos(int pos) const; //las posiciones incician desde 0
    QString getTipo_Valor_Carta(int pos)const; //las posiciones incician desde 0
    void revolverBaraja();
    bool verificarAdd(int pos)const;
    int getTam()const;
    ~Barajas();

private:
    int tam;
    int cuantas;
    Carta *cartas;
    bool verificarNum(int n) const;

};

#endif // BARAJAS_H
