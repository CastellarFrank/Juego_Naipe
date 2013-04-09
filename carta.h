#ifndef CARTA_H
#define CARTA_H
#include <QString>
using namespace std;

class Carta
{
public:
    Carta();
    Carta(int n,QString t);
    int getNumero()const;
    QString getTipo() const;
    bool getAdd()const;
    void setNumero(int n);
    void setTipo(QString t);
    void setAdd(bool v);
    bool igual(const Carta &c)const;
    bool mayor(const Carta &c)const;
    bool menor(const Carta &c)const;


private:
    int numero;
    QString tipo;
    bool add;
};

#endif // CARTA_H

