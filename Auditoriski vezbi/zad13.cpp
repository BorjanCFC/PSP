#include<iostream>
#include<string.h>
using namespace std;

class velosipedist {

    private:
    
    string ime;
    string prezime;
    int godini;
    float poeni;

    public:

    velosipedist(string i = "", string p = "", int g = 0, float po = 0.0){
        ime = i;
        prezime = p;
        godini = g >= 0 ? g : 0;
        poeni = po >= 0.0 ? po : 0.0;
    }

    string getIme(){
        return ime;
    }

    string getPrezime(){
        return prezime;
    }

    int getGod(){
        return godini;
    }

    float getPoeni(){
        return poeni;
    }



};

class team {

    private:

    string ime;
    string sponzor;
    velosipedist *lista;
    int N;

    public:

    team(string i = "", string s = "", velosipedist *l = NULL, int n = 0) {
        ime = i;
        sponzor = s;
        N = n >= 0 ? n : 0;

        lista = new velosipedist[N];
        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }
    }

    team(const team &t){
        ime = t.ime;
        sponzor = t.sponzor;
        N = t.N;

        lista = new velosipedist[N];
        for(int i = 0; i < N; i++){
            lista[i] = t.lista[i];
        }

    }

    ~team(){
        delete [] lista;
    }

    team &operator=(const team &t){
        if(this == &t){
            return *this;
        }

        delete [] lista;

        ime = t.ime;
        sponzor = t.sponzor;
        N = t.N;

        lista = new velosipedist[N];
        for(int i = 0; i < N; i++){
            lista[i] = t.lista[i];
        }

    }

    float poeni_tim(){
        float p = 0.0;
        for(int i = 0; i < N; i++){
            p += lista[i].getPoeni();
        }

        return p;
    }

    team &operator+=(velosipedist &v){
        velosipedist *pom = new velosipedist[N];

        for(int i = 0; i < N; i++){
            pom[i] = lista[i];
        }

        pom[N] = v;

        N++;

        delete [] lista;

        
        lista = new velosipedist[N];
        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;

        return *this;
    }

    friend team &operator+(const team &t1, const team &t2){
        team t3;

        for(int i = 0; i < t1.N; i++){
            t3 += t1.lista[i];
        }

        for(int i = 0; i < t2.N; i++){
            t3 += t2.lista[i];
        }

        return t3;
    }

    team &operator--(){
        int min = 0;

        for(int i = 1; i < N; i++){
            if(lista[i].getPoeni() < lista[min].getPoeni()){
                min = i;
            }
        }

        velosipedist *pom = new velosipedist[N-1];
        for(int i = 0, j = 0; i < N; i++){
            if(i != min){
                pom[j] = lista[i];
                j++;
            }
        }

        delete [] lista;

        N--;

        lista = new velosipedist[N];
        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;

        return *this;
    }

    team &operator--(int){
        team p = *this;

        int min = 0;

        for(int i = 1; i < N; i++){
            if(lista[i].getPoeni() < lista[min].getPoeni()){
                min = i;
            }
        }

        velosipedist *pom = new velosipedist[N-1];
        for(int i = 0, j = 0; i < N; i++){
            if(i != min){
                pom[j] = lista[i];
                j++;
            }
        }

        delete [] lista;

        N--;

        lista = new velosipedist[N];
        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;

        return p;

    }

    friend bool operator>(team &t1, team &t2){
        return t1.poeni_tim() > t1.poeni_tim();
    }

    friend ostream &operator<<(ostream &o, const team &t){
        o<<"Ime: "<<t.ime<<endl;
        o<<"Sponzor: "<<t.sponzor<<endl;
        for(int i = 0; i < t.N; i++){
            o<<t.lista[i].getIme()<<" "<<t.lista[i].getPrezime()<<" "<<t.lista[i].getGod()<<" godini "<<t.lista[i].getPoeni()<<" poeni "<<endl;
        }
        return o;
    }

};