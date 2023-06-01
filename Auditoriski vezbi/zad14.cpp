#include<iostream>
#include<string.h>
using namespace std;

class ured {

    private:

    char klasa;
    float cena;

    public:

    ured(char k = 'A', float c = 0.0){
        if(k >= 'A' && k <= 'F'){
            klasa = k;
        }else{
            klasa = 'A';
        }

        cena = c >= 0.0 ? c : 0.0;
    }

    virtual float odnos(){
        int k;
        switch (klasa) {
            case 'A' : k = 100; break;
            case 'B' : k = 80; break;
            case 'C' : k = 60; break;
            case 'D' : k = 40; break;
            case 'E' : k = 20; break;
            case 'F' : k = 5;  break;      
        }
        return cena/k;
    }

    virtual void pechati(){
        cout<<"Klasa: "<<klasa<<endl;
        cout<<"Cena: "<<cena<<endl;
    }

    virtual int presmetajMokjnost() = 0;

    virtual float getCena(){
        return cena;
    }

    int getKoeficient(){
        int k;
        switch (klasa) {
            case 'A' : k = 100; break;
            case 'B' : k = 80; break;
            case 'C' : k = 60; break;
            case 'D' : k = 40; break;
            case 'E' : k = 20; break;
            case 'F' : k = 5;  break;      
        }
        return k;
    }

};

class klima : public ured {

    private:

    int nadvor;
    int vnatre[4];
    int N;

    public:

    klima(char k = 'A', float c = 0.0, int n = 0, int *v = NULL, int nn = 0) : ured(k, c) {
        nadvor = n >= 0 ? n : 0;
        N = nn >= 0 && nn <= 4 ? nn : 0;
        for(int i = 0; i < N; i++){
            vnatre[i] = v[i];
        }
    }

    void pechati(){
        ured::pechati();
        cout<<"Nadvoreshna edinica na mokjnost: "<<nadvor<<endl;
        for(int i = 0; i < N; i++){
            cout<<vnatre[i]<<endl;
        }
    }

    int presmetajMokjnost(){

        int p = nadvor;
        for(int i = 0; i < N; i++){
            p += vnatre[i];
        }

        return p;
    }

    float getCena(){
        float c = ured::getCena();
        return c + presmetajMokjnost() * 10;
    }

    float odnos(){
        return getKoeficient() / getCena();
    }

};

class frizhider : public ured {

    private:

    int volumen;
    bool tip; //  1 = zamrznuvanje, 0 = odrzhuvanje

    public:

    frizhider(char k = 'A', float c = 0.0, int v = 0, bool t = false) : ured(k, c) {
        volumen = v >= 0 ? v : 0;
        tip = t;
    }

    void pechati(){
        ured::pechati();
        cout<<"Volumen: "<<volumen<<endl;
        if(tip){
            cout<<"Frizhiderot e za zamrznuvanje."<<endl;
        }else{
            cout<<"Frizhiderot e za odrzhuvanje. "<<endl;
        }
    }

    int presmetajMokjnost(){
        int p = volumen * 100;

        if(tip){
            p *= 1.5;
        }
        return p;
    }

    float getCena(){
        float c = ured::getCena();
        return c + presmetajMokjnost() * 15;
    }

    float odnos(){
        return getKoeficient() / getCena();
    }

};

void najdobarOdnos(ured **lista, int N){
    ured *max = lista[0];

    for(int i = 1; i < N; i++){
        if(lista[i]->odnos() > max->odnos()){
            max = lista[i];
        }
    }

    max->pechati();
}