#include <iostream>
#include <string.h>
#include "masini.h"

using namespace std;

lap::lap()
{
    masina=new masini;
}

lap::lap(masini *m)
{
    masina=m;
}
lap::~lap()
{
    delete (masina);
}
lap lap::operator++()//pentru viteza mai mare
{
    masina->viteza=masina->viteza + 50;
    masina->d+=1;
    cout<<"Masina "<<masina->marca<<" "<<masina->model<<" i s-a marit viteza\n";
    return *this;
}

lap lap::operator++(int)//pentru viteza mai mare
{
    masina->viteza=masina->viteza + 50;
    masina->d+=1;
    cout<<"Masina "<<masina->marca<<" "<<masina->model<<" i s-a marit viteza\n";
    return *this;
}

lap lap::operator--()//pentru viteza mai mica
{
    masina->viteza=masina->viteza - 50;
    masina->d+=1;
    cout<<"Masina "<<masina->marca<<" "<<masina->model<<" i s-a micsorat viteza\n";
    return *this;
}

lap lap::operator--(int)//pentru viteza mai mica
{
    masina->viteza=masina->viteza - 50;
    masina->d+=1;
    cout<<"Masina "<<masina->marca<<" "<<masina->model<<" i s-a micsorat viteza\n";
    return *this;
}

lap operator+(float n,lap l)//pentru consum mai mare
{
    l.masina->consum=l.masina->consum + n;
    l.masina->d+=1;
    cout<<"Masina "<<l.masina->marca<<" "<<l.masina->model<<" i s-a marit consumul\n";
    return l;
}

lap operator+(lap l,float n)//pentru consum mai mare
{

    l.masina->consum=l.masina->consum + n;
    l.masina->d+=1;
    cout<<"Masina "<<l.masina->marca<<" "<<l.masina->model<<" i s-a marit consumul\n";
    return l;
}

lap operator-(lap l,float n)//pentru consum mai mic
{
    l.masina->consum=l.masina->consum - n;
    if(l.masina->consum<1)
        l.masina->consum=1;
    l.masina->d+=1;
    cout<<"Masina "<<l.masina->marca<<" "<<l.masina->model<<" i s-a micsorat consumul\n";
    return l;
}

void lap::plin_de_rezervor()//pentru plin de rezervor
{
    masina->rezervor=masina->motor/10;
    cout<<"Masina "<<masina->marca<<" "<<masina->model<<" a primit un plin de rezervor\n";
}

void winner(lap l1 ,lap l2,lap l3)//castigatorul
{
        cout<<endl;
        if(l1.masina->drum_parcurs>=5000)
        cout<<"Castigatorul este: "<<l1.masina->marca<<" "<<l1.masina->model<<endl;
        else if(l2.masina->drum_parcurs>5000)
        cout<<"Castigatorul este: "<<l2.masina->marca<<" "<<l2.masina->model<<endl;
        else
        cout<<"Castigatorul este: "<<l3.masina->marca<<" "<<l3.masina->model<<endl;
        cout<<endl;
}
