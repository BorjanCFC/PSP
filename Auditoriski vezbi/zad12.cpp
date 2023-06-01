#include<iostream>
#include<string.h>
using namespace std;

class izvidnik {

    private:

    string ime;
    string prezime;
    int god;

    public:

    izvidnik(string i = "", string p = "", int g = 0){
        ime = i; 
        prezime = p;
        god = g >= 0 ? g : 0;
    }

    int getGodini(){
        return god;
    }

    string getIme(){
        return ime;
    }

    string getPrezime(){
        return prezime;
    }

};

class drustvo {

    private:

    string ime;
    string oblast;
    int N;
    izvidnik *lista;

    public:

    drustvo(string i = "", string o = "", int d = 0, izvidnik *l = NULL){
        ime = i;
        oblast = o;
        N = d >= 0 ? d : 0;

        lista = new izvidnik[N];
        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }
    }

    drustvo(const drustvo &d){
        ime = d.ime;
        oblast = d.oblast;
        N = d.N;

        lista = new izvidnik[N];
        for(int i = 0; i < N; i++){
            lista[i] = d.lista[i];
        }

    }

    drustvo &operator=(const drustvo &d){
        if(this == &d){
            return *this;
        }

        ime = d.ime;
        oblast = d.oblast;
        N = d.N;

        delete [] lista;

        lista = new izvidnik[N];
        for(int i = 0; i < N; i++){
            lista[i] = d.lista[i];
        }

        return *this;
    }

    ~drustvo(){
        delete [] lista;
    }

    int maxGodiniIskustvo(){
        int g = lista[0].getGodini();
        for(int i = 0; i < N; i++){
            if(lista[i].getGodini() > g){
                g = lista[i].getGodini();
            }
        }
        return g;
    }

    drustvo &operator+=(izvidnik &t){
        izvidnik *pom = new izvidnik[N+1];

        for(int i = 0; i < N; i++){
            pom[i] = lista[i];
        }

        pom[N] = t;

        N++;

        delete [] lista;

        lista = new izvidnik[N];
        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }
        
        delete [] pom;

        return *this;
    }

    friend drustvo &operator+(const drustvo &d1, const drustvo &d2){
        drustvo d3;

        for(int i = 0; i < d1.N; i++){
            d3 += d1.lista[i];
        }

        for(int i = 0; i < d2.N; i++){
            d3 += d2.lista[i];
        }

        return d3;
    }

    drustvo &operator--(){
        int min = 0;

        for(int i = 1; i < N; i++){
            if(lista[i].getGodini() < lista[min].getGodini()){
                min = i;
            }
        }

        izvidnik *pom = new izvidnik[N-1];
        for(int i = 0, j = 0; j < N, i < N; i++){
            if(i != min){
                pom[j] = lista[i];
                j++;
            }
        }

        delete [] lista; 

        N--;

        lista = new izvidnik[N];
        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;

        return *this;
    }

    friend ostream &operator<<(ostream &o, const drustvo &d){
        o<<"Ime: "<<d.ime<<endl;
        o<<"Oblast: "<<d.oblast<<endl;
        o<<"Broj na izvidnici: "<<d.N<<endl;
        o<<"Izvidnici: "<<endl;
        // for(int i = 0; i < d.N; i++){
        //     o<<d.lista[i]<<endl;
        // }
    }


};

