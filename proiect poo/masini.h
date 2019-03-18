#include <iostream>
#include "lap.h"
using namespace std;

class masini
{
public:
    char marca[30];
    char model[30];
    int cai_putere;
    float motor;
    float viteza;
    float drum_parcurs;
    int d;
    float consum;
    float rezervor;


    masini();//constructor fara parametrii
    masini(char [] ,char [] ,int ,float);//constructor cu parametrii
    ~masini();//destructor
    friend ostream& operator<<(ostream&, masini);
    friend istream& operator>>(istream&, masini&);
    masini operator++();
    masini operator++(int);
    masini operator--();
    masini operator--(int);
    masini operator=(masini);
    friend int mia_de_km(masini);
    friend class lap;
    friend float drum_parcurs_de(masini);
    friend float drum_maxim(masini,masini,masini);
};
