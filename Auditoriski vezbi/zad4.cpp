#include<iostream>
#include<string.h>
using namespace std;

class ucenik{

    private:
    char *ime;
    float prosek;
    int godina;

    public:

    ucenik(char *i = "", float p = 0.0, int g = 1){
        ime = new char[strlen(i) + 1];
        strcpy(ime,i);

        if(p >= 0.0 && p <= 5.0){
            prosek = p;
        }else{
            prosek = 0.0;
        }

        if(g >= 1 && g <= 4){
            godina = g;
        }else{
            godina = g;
        }
    }

    ucenik(const ucenik &u){

        ime = new char[strlen(u.ime)+1];
        strcpy(ime, u.ime);
        prosek = u.prosek;
        godina = u.godina;

    }

    char *getIme(){
        return ime;
    }

    float getProsek(){
        return prosek;
    }

    int getGodina(){
        return godina;
    }

    void setProsek(float p){
        if(p >= 0.0 && p <= 5.0){
            prosek = p;
        }else{
            prosek = 0.0;
        }
    }

    void setGodina(int g){
        if(g >= 1 && g <= 4){
            godina = g;
        }else{
            godina = g;
        }
    }

    void setIme(char *i){
        delete [] ime;
        ime = new char[strlen(i) + 1];
        strcpy(ime,i);
    }

    void zgolemiGod(){
        godina++;
        if(godina > 4){
            godina = 4;
        }
    }

    void pechati(){
        cout<<ime<<" prosek "<<prosek<<" godina "<<godina<<endl;
    }

    ~ucenik(){
        delete[] ime;
    };

};

class paralelka{

    private:
    ucenik *lista;
    int N;

    public:

    paralelka(ucenik *l = NULL, int d = 0){
        N = d >=0 ? d : 0;

        lista = new ucenik[N];
        for(int i = 0; i<N; i++){
            lista[i] = l[i];
        }
    }

    paralelka(const paralelka &p){
        N = p.N;
        lista = new ucenik[N];
        for(int i = 0; i<N; i++){
            lista[i] = p.lista[i];
        }
    }

    ~paralelka(){
        delete [] lista;
    }

    void zgolemiGod(){
        for(int i = 0; i<N; i++){
            lista[i].zgolemiGod();
        }
    }

    void dodadi(ucenik nov){
        ucenik *pom = new ucenik[N+1];
        for(int i = 0; i<N; i++){
            pom[i] = lista[i];
        }
        pom[N] = nov;

        delete [] lista;
        N++;
        lista = new ucenik[N];

        for(int i = 0; i<N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;
    }

    void pechati(){
        for(int i = 0; i < N; i++){
            lista[i].pechati();
        }
    }

    void pechati5(){
        for(int i = 0; i < N; i++){
            if(lista[i].getProsek() == 5.0){
                lista[i].pechati();
            }
        }
    }
};


//  class ucenik{
    
//     ucenik &operator = (const ucenik &U){
//             if(this == &u){
//                 return *this;
//             }
//         delete [] ime;
//         ime = new char[strlen(u.ime)+1];
//         strcpy(ime,u.ime);
//         prosek = u.prosek;
//         godina = u.prosek;

//         return *this;
//     }
//  };
    

