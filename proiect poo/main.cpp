#include <iostream>
#include <time.h>
#include "masini.h"
#include <string.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int finish=5000,i,r;
    char x[10];
    masini m1("opel","astra",200,2000),m2,m3;

    cin>>m3;
    cout<<endl;
    cout<<"Datele masinii m1: "<<endl;
    cout<<m1<<endl;
    cout<<"Datele masinii m2: "<<endl;
    cout<<m2<<endl;
    cout<<"Datele masinii m3: "<<endl;
    cout<<m3<<endl;
    cout<<endl<<endl;

    lap l1(&m1),l2(&m2),l3(&m3);

    cout<<"Incepeti cursa?\n";
    cin>>x;

    while(strcmp(x,"da")!=0 && strcmp(x,"Da")!=0 && strcmp(x,"DA")!=0)
    {
        cout<<"Dar acum?\n";
        cin>>x;
    }
    unsigned int sec;
    clock_t t1,t2;
    t1=clock()/(CLOCKS_PER_SEC);
    int timp=0;

    while (drum_maxim(m1,m2,m3)<finish)
    {
        t2=clock()/(CLOCKS_PER_SEC);
        sec=t2-t1;
        if(sec>=1)
        {
            timp=timp+sec;
            t1=t2;
            m1++;
            m2++;
            m3++;
            m1--;
            m2--;
            m3--;

            for(i=1; i<=3; i++)
            {
                masini m;
                lap l;
                if(i==1)
                {
                    m=m1;
                    l=l1;
                }
                else if (i==2)
                {
                    m=m2;
                    l=l2;
                }
                else
                {
                    m=m3;
                    l=l3;
                }
                if(drum_parcurs_de(m)>mia_de_km(m))
                {
                    r=rand() %5 + 1;
                    switch(r)
                    {
                    case 1://se mareste viteza
                        l++;
                        break;
                    case 2://se micsoreaza viteza
                        l--;
                        break;
                    case 3://se mareste consumul
                        l=l+2;
                        break;
                    case 4://se micsoreaza consumul
                        l=l-2;
                        break;
                    case 5://se face un plin de rezervor
                        l.plin_de_rezervor();
                        break;
                    }
                }
                if(i==1)
                {
                    m=m1;
                    l=l1;
                }
                else if (i==2)
                {
                    m=m2;
                    l=l2;
                }
                else
                {
                    m=m3;
                    l=l3;
                }

            }
        }


    }

    winner(l1,l2,l3);

    return 0;
}
