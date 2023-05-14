#include<iostream>
#include<string.h>
using namespace std;

class prostor{

    private:

    char *lokacija;
    int kvadratura;
    float cena;

    public:

    prostor(char *lok = "", int k = 1, float c = 0.0){

        lokacija = new char[strlen(lok) + 1];
        strcpy(lokacija, lok);

        kvadratura = k >= 1 ? k : 1;

        cena = c >= 0.0 ? c : 0.0;
    }

    prostor(const prostor &p){

        lokacija = new char[strlen(p.lokacija) + 1];
        strcpy(lokacija, p.lokacija);

        kvadratura = p.kvadratura;

        cena = p.cena;

    }

    prostor &operator=(const prostor &p){

        if(this == &p){
            return *this;
        }

        kvadratura = p.kvadratura;

        cena = p.cena;

        delete [] lokacija;

        lokacija = new char[strlen(p.lokacija) + 1];
        strcpy(lokacija, p.lokacija);

        return *this;

    }

    ~prostor(){
        delete [] lokacija;
    }

    void pechati(){
        cout<<"Lokacija: "<<lokacija<<endl;
        cout<<"Kvadratura: "<<kvadratura<<endl;
        cout<<"Cena: "<<cena<<endl;
    }

    float presmetajCena(float cenaKvadrat){
        return cena = cenaKvadrat * kvadratura;
    }

    float getCena(){
        return cena;
    }


};

class stanbenProstor : public prostor {

    private:

    int brParking;

    public:

    stanbenProstor(char *lok = "", int k = 1, float c = 0.0, int brP = 0) : prostor(lok, k, c) {
        brParking = brP >= 0 ? brP : 0;
    }

    stanbenProstor(const stanbenProstor &s) : prostor(s) {
        brParking = s.brParking;
    }

    stanbenProstor& operator=(const stanbenProstor& s){

    if (this == &s) {
        return *this;
    }

    prostor::operator=(s);

    brParking = s.brParking;

    return *this;

    }

    void pechati(){
        prostor::pechati();
        cout<<"Broj na parking mesta: "<<brParking<<endl;
    }

    float presmetajCena(float cenaKvadrat){
    
        float osnovnaCena = prostor::presmetajCena(cenaKvadrat);
    
        float cena = osnovnaCena + brParking * 5000;

        return cena;

    }

};

class maloprodazhenProstor : public prostor {

    private:

    int brBrendovi;

    public:

    maloprodazhenProstor(char *lok = "", int k = 1, float c = 0.0, int brB = 0) : prostor(lok, k, c) {
        brBrendovi = brB >= 0 ? brB : 0;
    }

    maloprodazhenProstor(const maloprodazhenProstor &m) : prostor(m) {
        brBrendovi = m.brBrendovi;
    }

    maloprodazhenProstor &operator=(const maloprodazhenProstor &m){

        if(this == &m){
            return *this;
        }

        prostor::operator=(m);

        brBrendovi = m.brBrendovi;

        return *this;

    }

    void pechati(){
        prostor::pechati();
        cout<<"Broj na brendovi: "<<brBrendovi<<endl;
    }

    float presmetajCena(float cenaKvadrat) {
        
        float osnovnaCena = prostor::presmetajCena(cenaKvadrat);
        
        float discount = brBrendovi / 100.0;
        
        float cena = osnovnaCena - (osnovnaCena * discount);

        return cena;

    }

};


