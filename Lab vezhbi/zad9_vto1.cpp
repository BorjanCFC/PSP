#include<iostream>
#include<string.h>
using namespace std;

class restoran{

    private:

    char *ime;
    int brVraboteni;

    public:

    restoran(char *i = "", int brV = 0){
        ime = new char[strlen(i) + 1];
        strcpy(ime, i);

        brVraboteni = brV >=0 ? brV : 0;
    }

    restoran(const restoran &r){
        ime = new char[strlen(r.ime) + 1];
        strcpy(ime, r.ime);

        brVraboteni = r.brVraboteni;
    }

    char *getIme(){
        return ime;
    }

    int getVraboteni(){
        return brVraboteni;
    }

    void setIme(char *i){
        delete [] ime;
        ime = new char[strlen(i) + 1];
        strcpy(ime, i);
    }

    void setVraboteni(int brV){
        brVraboteni = brV >=0 ? brV : 0;
    }

    ~restoran(){
        delete [] ime;
    }

};

class lanec{

    private:

    char *ime;
    char *lokacija;
    int N;
    restoran *lista;

    public:

    lanec(char *i = "", char *lok = "", int d = 0, restoran *l = NULL){
        ime = new char[strlen(i) + 1];
        strcpy(ime, i);

        lokacija = new char[strlen(lok) + 1];
        strcpy(lokacija, lok);

        N = d >= 0 ? d : 0;

        lista = new restoran[N];
        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }
    }

    lanec(const lanec &lc){
        ime = new char[strlen(lc.ime) + 1];
        strcpy(ime, lc.ime);

        lokacija = new char[strlen(lc.lokacija) + 1];
        strcpy(lokacija, lc.lokacija);

        N = lc.N;

        lista = new restoran[N];
        for(int i = 0; i < N; i++){
            lista[i] = lc.lista[i];
        }
    }

    lanec &operator+=(restoran &r){
        restoran *pom = new restoran[N+1];

        for(int i = 0; i < N; i++){
            pom[i].setIme(lista[i].getIme());
            pom[i].setVraboteni(lista[i].getVraboteni());
        }

        delete [] lista;

        pom[N].setIme(r.getIme());
        pom[N].setVraboteni(r.getVraboteni());

        N++;

        lista = new restoran[N];
        for(int i = 0; i < N; i++){
            lista[i].setIme(pom[i].getIme());
            lista[i].setVraboteni(pom[i].getVraboteni());
        }

        delete [] pom;

        return *this;

    }

    lanec &operator-=(restoran &r){
        restoran *pom = new restoran[N+1];

        pom[0].setIme(r.getIme());
        pom[0].setVraboteni(r.getVraboteni());

        for(int i = 0; i < N; i++){
            pom[i+1].setIme(lista[i].getIme());
            pom[i+1].setVraboteni(lista[i].getVraboteni());
        }

        delete [] lista;

        N++;

        lista = new restoran[N];
        for(int i = 0; i < N; i++){
            lista[i].setIme(pom[i].getIme());
            lista[i].setVraboteni(pom[i].getVraboteni());
        }

        delete [] pom;

        return *this;
    }

    lanec &operator++(){
        restoran *pom = new restoran[N-1];

        for(int i = 0; i < N - 1; i++){
            pom[i].setIme(lista[i].getIme());
            pom[i].setVraboteni(lista[i].getVraboteni());
        }

        delete [] lista;

        N--;

        lista = new restoran[N];

        for(int i = 0; i < N; i++){
            lista[i].setIme(pom[i].getIme());
            lista[i].setVraboteni(pom[i].getVraboteni());
        }

        delete [] pom;

        return *this;

    }

    lanec &operator--(){
        restoran *pom = new restoran[N-1];

        for(int i = 1; i < N ; i++){
            pom[i-1].setIme(lista[i].getIme());
            pom[i-1].setVraboteni(lista[i].getVraboteni());
        }

        delete [] lista;

        N--;

        lista = new restoran[N];

        for(int i = 0; i < N; i++){
            lista[i].setIme(pom[i].getIme());
            lista[i].setVraboteni(pom[i].getVraboteni());
        }

        delete [] pom;

        return *this;
    }

    friend ostream &operator<<(ostream &o, const lanec &r){
        o<<"Ime na lanecot: "<<r.ime<<endl;
        o<<"Lokacija: "<<r.lokacija<<endl;
        o<<"Broj na restorani: "<<r.N<<endl;
        o<<"Restoranite: "<<endl;
        for(int i = 0; i < r.N; i++){
            o<<r.lista[i].getIme()<<" ima "<<r.lista[i].getVraboteni()<<" vraboteni"<<endl;
        }
        return o;
    }

    ~lanec(){
        delete [] ime;
        delete [] lokacija;
        delete [] lista;
    }

};

int main() {
    
    restoran r1("Giovani - Karposh", 7);
    restoran r2("Giovani - Aerodrom", 14);
    restoran r3("Giovani - Centar", 17);
    restoran r4("Martini - Karposh", 23);
    restoran r5("Baking Bread", 16);

    restoran lista[] = {r1, r2};
    lanec l1("LoungeBars", "Skopje", 2, lista);

    cout << l1 << endl;

    l1 += r3;
    l1 += r4;
    l1 -= r5;

    cout << l1 << endl;

    ++l1;
    --l1;

    cout << l1 << endl;

    return 0;
}
