// Да се напише класа за опис на ученици. За секој ученик се чува името како динамички
// алоцирано поле од знаци, просекот како децимален број и школска година како цел број.
// Класата треба да ги содржи следните функции и преоптоварени оператори:
// • Конструктори
// • get() и set() методи
// • Оператор = за изедначување на два ученици
// • Оператор ++ за зголемување на запишаната школска година за еден.
// • Оператор << за печатење на ученик со сите негови податоци.
// Потоа треба да се креира класа паралелка која во себе содржи динамички алоцирано поле од
// ученици, како и број на елементи во полето. Класата треба да ги содржи следните функции и
// преоптоварени оператори:
// • Конструктори
// • Оператор ++ за зголемување на запишаната школска година за еден за сите ученици во
// полето.
// • Оператор += за додавање на еден ученик во полето од ученици
// Оператор << за печатење на сите ученици во класата 

#include<iostream>
#include<string.h>
using namespace std;

class ucenik{

    private:

    char *ime;
    float prosek;
    int godina;

    public:

    ucenik(char *i = "", float p = 1.0, int g = 1){

        ime = new char[strlen(i) + 1];
        strcpy(ime, i);
        prosek = p >= 1 && p <=5.0 ? p : 1.0;
        godina = g >= 1 && g <=4 ? g : 1;

    }

    ~ucenik(){
        delete [] ime;
    }

    ucenik(const ucenik &u){

        ime = new char[strlen(u.ime) + 1];
        strcpy(ime, u.ime);
        godina = u.godina;
        prosek = u.prosek;

    }

    ucenik &operator=(const ucenik &u){ 

        if (this == &u){
            return *this;
        }
        delete [] ime;

        ime = new char[strlen(u.ime) + 1];
        strcpy(ime, u.ime);
        godina = u.godina;
        prosek = u.prosek;
        
        return *this;
     
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

    void setIme(char *i){
        delete [] ime;
        ime = new char[strlen(i) + 1];
        strcpy(ime, i);
    }

    void setProsek(float p){
        prosek = p >= 1 && p <=5.0 ? p : 1.0;
    }

    void getGodina(int g){
        godina = g >= 1 && g <=4 ? g : 1;
    }

    ucenik &operator++(){

        godina++;
        if(godina > 4){
            godina = 4;
        }
        return *this;

    }

    ucenik &operator++(int){
        ucenik pom(*this);

        godina++;
        if(godina > 4){
            godina = 4;
        }

        return pom;

    }

    friend ostream &operator<<(ostream &o, const ucenik &u){
        o<<u.ime<<" godina: "<<u.godina<<" prosek: "<<u.prosek<<endl;
        return o;
    }

};

class paralelka{

    private:
    ucenik *lista;
    int N;

    public:

    paralelka(ucenik *l = NULL, int d = 0){
        N = d >= 0 ? d : 0;

        lista = new ucenik[N];
        for(int i = 0; i < N ; i++){
            lista[i] = l[i];
        }
    }

    paralelka(const paralelka &p){
        N = p.N;

        lista = new ucenik[N];

        for(int i = 0; i < N; i++){
            lista[i] = p.lista[i];
        }
    }

    paralelka &operator=(const paralelka &p){

        if(this == &p){
            return *this;
        }

        delete [] lista;

        N = p.N;

        lista = new ucenik[N];

        for(int i = 0; i < N; i++){
            lista[i] = p.lista[i];
        }
        return *this;

    }

    paralelka &operator++(){

        for(int i = 0; i < N; i++){
            ++lista[i];
        }

    }

    paralelka &operator+=(ucenik &u){

        ucenik *pom = new ucenik[N+1];
        for(int i = 0; i < N; i++){
            pom[i] = lista[i];
        }

        pom[N] = u;
        N++;

        delete [] lista;

        lista = new ucenik[N];
        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;
    }

    friend ostream &operator<<(ostream &o, paralelka &p){

        for(int i = 0; i < p.N; i++){
            o<<p.lista[i]<<endl;
            //o<<p.lista[i].getime<<p.lista[i].getGodina....
        }
        
    }


};
