#include<iostream>
#include<string.h>
using namespace std;

class destinacija{

    private:
    
    char *grad;
    int vreme;

    public:

    destinacija(char *g = "", int v = 0){

        grad = new char[strlen(g) + 1];
        strcpy(grad, g);

        vreme = v >= 0 ? v : 0;
    }

    destinacija(const destinacija &d){

        grad = new char[strlen(d.grad) + 1];
        strcpy(grad, d.grad);

        vreme = d.vreme;
    }

    char *getGrad(){
        return grad;
    }

    void setGrad(char *g){
        delete [] grad;
        grad = new char[strlen(g) + 1];
        strcpy(grad, g);
    }
    
    void setVreme(int v){
        vreme = v >= 0 ? v : 0;
    }

    int getVreme(){
        return vreme;
    }

    ~destinacija(){
        delete [] grad;
    }

};

class patuvanje{

    private:

    char *ime;
    int cena;
    int N;
    destinacija *lista;

    public:

    patuvanje(char *i = "", int c = 0, int d = 0, destinacija *l = NULL){

        ime = new char[strlen(i) + 1];
        strcpy(ime, i);

        cena = c >= 0 ? c : 0;
        N = d >= 0 ? d : 0;

        lista = new destinacija[N];
        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }
    }

    patuvanje(const patuvanje &p){

        ime = new char[strlen(p.ime) + 1];
        strcpy(ime, p.ime);

        cena = p.cena;
        N = p.N;

        lista = new destinacija[p.N];
        for(int i = 0; i < p.N; i++){
            lista[i] = p.lista[i];
        }
    }


    patuvanje &operator+=(destinacija &d){

        destinacija *pom = new destinacija[N+1];
        
        pom[0].setGrad(d.getGrad());
        pom[0].setVreme(d.getVreme());

        for(int i = 0; i < N; i++){
            pom[i+1].setGrad(lista[i].getGrad());
            pom[i+1].setVreme(lista[i].getVreme());
        }
        
        delete [] lista;

        N++;
        lista = new destinacija[N];

        for(int i = 0; i < N; i++){
            lista[i].setGrad(pom[i].getGrad());
            lista[i].setVreme(pom[i].getVreme());
        }

        delete [] pom;
        return *this;
    }

    patuvanje &operator-=(destinacija &d){

        destinacija *pom = new destinacija[N+1];

        for(int i = 0; i < N; i++){
            pom[i].setGrad(lista[i].getGrad());
            pom[i].setVreme(lista[i].getVreme());
        }
        
        delete [] lista;

        pom[N].setGrad(d.getGrad());
        pom[N].setVreme(d.getVreme());

        N++;
        lista = new destinacija[N];

        for(int i = 0; i < N; i++){
            lista[i].setGrad(pom[i].getGrad());
            lista[i].setVreme(pom[i].getVreme());
        }

        delete [] pom;
        return *this;

    }
    
    patuvanje &operator++(){

        destinacija *pom = new destinacija[N-1];

        for(int i = 1; i < N; i++){
            pom[i-1].setGrad(lista[i].getGrad());
            pom[i-1].setVreme(lista[i].getVreme());
        }

        delete [] lista;

        N--;

        lista = new destinacija[N];

        for(int i = 0; i < N; i++){
            lista[i].setGrad(pom[i].getGrad());
            lista[i].setVreme(pom[i].getVreme());
        }

        delete [] pom;

        return *this;
    }

    patuvanje &operator--(){
        destinacija *pom = new destinacija[N-1];

        for(int i = 0; i < N-1; i++){
            pom[i].setGrad(lista[i].getGrad());
            pom[i].setVreme(lista[i].getVreme());
        }

        delete [] lista;

        N--;

        lista = new destinacija[N];

        for(int i = 0; i < N; i++){
            lista[i].setGrad(pom[i].getGrad());
            lista[i].setVreme(pom[i].getVreme());
        }

        delete [] pom;

        return *this;
    }

    friend ostream &operator<<(ostream &o, const patuvanje &p){

        o<<"Ime na patuvanjeto: "<<p.ime<<endl;
        o<<"Cena na patuvanjeto: "<<p.cena<<" denari"<<endl;
        o<<"Broj na destinacii: "<<p.N<<endl;
        o<<endl;
        o<<"Dostapni destinacii: "<<endl;
        for(int i = 0; i < p.N; i++){
            o<<p.lista[i].getGrad()<<" vreme na prestoj "<<p.lista[i].getVreme()<<" dena"<<endl;
        }
        return o;
    }

    void setBroj(int n){
        N = n >= 0 ? n : 0;
    }

    void setIme(char *i){
        delete [] ime;
        ime = new char[strlen(i) + 1];
        strcpy(ime, i);
    }

    ~patuvanje(){
        delete [] ime;
        delete [] lista;
    }

};

int main() {

    destinacija d1("Split", 7);
    destinacija d2("Halkidiki", 14);
    destinacija d3("Dubrovnik", 17);
    destinacija d4("Barselona", 23);
    destinacija d5("Krit", 10);

    destinacija lista [] = {d1, d2};

    patuvanje p1("ElitnoPatuvanje", 30000, 2, lista);

    cout<<p1<<endl;

    p1 += d3;
    p1 += d4;
    p1 -= d5;

    cout<<p1<<endl;
    
    ++p1;
    --p1;

    cout<<p1<<endl;


    return 0;
}