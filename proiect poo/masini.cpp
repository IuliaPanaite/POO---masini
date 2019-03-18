#include <iostream>
#include <string.h>
#include "masini.h"

using namespace std;

masini::masini() //constructor fara parametrii
{

     strcpy(marca,"Dacia");
     strcpy(model,"Logan");
     cai_putere=80;
     motor=1200;
     viteza=150;
     drum_parcurs=0;
     d=1;
     consum=3*cai_putere*motor/100000;
     rezervor=motor/10;
}

masini::masini(char marca[],char model[],int cai_putere,float motor) //constructor cu parametrii
{

    strcpy(this->marca,marca);
    strcpy(this->model,model);
    this-> cai_putere=cai_putere;
    this-> motor=motor;
    viteza=200+cai_putere*motor/5000;
    drum_parcurs=0;
    d=1;
    consum=3*cai_putere*motor/100000;
    rezervor=motor/10;
}

masini::~masini()//destructor
{

}

ostream& operator<<(ostream& out, masini m)
{
        out<<"\tMarca: "<<m.marca;
        out<<"\n\tModel: "<<m.model;
        out<<"\n\tCai putere: "<<m.cai_putere;
        out<<"\n\tMotor: "<<m.motor;
        out<<"\n\tViteza: "<<m.viteza;
        out<<"\n\tDrum parcurs: "<<m.drum_parcurs;
        out<<"\n\tConsum: "<<m.consum;
        out<<"\n\tRezervor: "<<m.rezervor;
        cout<<endl;
    return out;
}

istream& operator>>(istream& in, masini & m)
{
    cout<<"Marca: ";
    in>>m.marca;

    cout<<"Model: ";
    in>>m.model;



    cout<<"Cai putere: ";
    in>>m.cai_putere;

    cout<<"Motor: ";
    in>>m.motor;

    m.viteza=200+m.cai_putere*m.motor/5000;
    m.drum_parcurs=0;
    m.d=1;
    m.consum=8+m.cai_putere*m.motor/100000;
    m.rezervor=m.motor/10;
    return in;
}

masini masini::operator++()
{
    this->drum_parcurs+=this->viteza;
    return *this;
}

masini masini::operator++(int)
{
    this->drum_parcurs+=this->viteza;
    return *this;
}

masini masini::operator--()
{
    this->rezervor-=this->consum;
    return *this;
}

masini masini::operator--(int)
{
    this->rezervor-=this->consum;
    return *this;
}

masini masini::operator=(masini m2)
{
    strcpy(this->marca,m2.marca);
    strcpy(this->model,m2.model);
    this->cai_putere=m2.cai_putere;
    this->motor=m2.motor;
    this->viteza=m2.viteza;
    this->drum_parcurs=m2.drum_parcurs;
    this->d=m2.d;
    this->consum=m2.consum;
    this->rezervor=m2.rezervor;

}

int mia_de_km(masini m)
{
    return 1000*(m.d);
}

float drum_parcurs_de(masini m)
{
    return m.drum_parcurs;
}

float drum_maxim(masini m1,masini m2,masini m3)
{

    static masini maxim;
    if(m1.drum_parcurs>m2.drum_parcurs)
        maxim=m1;
        else
            maxim=m2;
        if(maxim.drum_parcurs<m3.drum_parcurs)
            maxim=m3;
    return maxim.drum_parcurs;
}
