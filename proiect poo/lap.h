class masini;

class lap
{
    masini *masina;
    //masina tre sa devina pointer + modificarile necesare in lap.cpp
    public:
    lap();
    lap(masini* );
    ~lap();

    //speed:
    lap operator++(int);
    lap operator++();
    //low:
    lap operator--(int);
    lap operator--();
    //consum mare:
    friend lap operator+(float,lap);
    friend lap operator+(lap,float);
    //consum mic:
    friend lap operator-(lap,float);
    //plin de rezervor:
    void plin_de_rezervor();
    friend void winner(lap,lap,lap);
};

