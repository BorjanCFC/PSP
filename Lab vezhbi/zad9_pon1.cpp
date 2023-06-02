#include<iostream>
#include<string.h>
using namespace std;

struct ocila {
    string brend;
    int primeroci;
};

class prodavnica {

    private:

    string ime;
    string lokacija;
    ocila *lista;
    int N;

    public:

    prodavnica(string i = "", string lok = "", int n = 0, ocila *l = NULL){
        ime = i;
        lokacija = lok;
        N = n >= 0 ? n : 0;

        lista = new ocila[N];
        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }

    }

    prodavnica(const prodavnica &p){
        ime = p.ime;
        lokacija = p.lokacija;
        N = p.N;

        lista = new ocila[N];
        for(int i = 0; i < N; i++){
            lista[i] = p.lista[i];
        }

    }

    prodavnica &operator=(const prodavnica &p){
        if(this == &p){
            return *this;
        }

        delete [] lista;

        ime = p.ime;
        lokacija = p.lokacija;
        N = p.N;

        lista = new ocila[N];
        for(int i = 0; i < N; i++){
            lista[i] = p.lista[i];
        }

        return *this;
    }

    prodavnica &operator+=(ocila &o){
        ocila *pom = new ocila[N+1];

        for(int i = 0; i < N; i++){
            pom[i] = lista[i];
        }

        pom[N] = o;

        delete [] lista;

        N++;

        lista = new ocila[N];
        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;

        return *this;
        
    }

    prodavnica &operator-=(ocila &o){
        ocila *pom = new ocila[N+1];
        pom[0] = o;

        for(int i = 0; i < N; i++){
            pom[i+1] = lista[i];
        }

        delete [] lista;

        N++;

        lista = new ocila[N];
        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;

        return *this;
    }

    prodavnica &operator++(){
        ocila *pom = new ocila[N-1];

        for(int i = 0; i < N - 1; i++){
            pom[i] = lista[i];
        }

        delete [] lista;

        N--;

        lista = new ocila[N];
        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;

        return *this;

    }

    prodavnica &operator--(){
        ocila *pom = new ocila[N-1];

        for(int i = 1; i < N; i++){
            pom[i-1] = lista[i];
        }

        delete [] lista;

        N--;

        lista = new ocila[N];
        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;

        return *this;

    }

    friend ostream &operator<<(ostream &o, const prodavnica &p){
        o<<"Ime na prodavnicata: "<<p.ime<<endl;
        o<<"Lokacija na prodavnicata: "<<p.lokacija<<endl;
        o<<"Broj na naocari: "<<p.N<<endl;
        o<<endl;
        o<<"Listata od naocari: "<<endl;
        for(int i = 0; i < p.N; i++){
            o<<"Brend: "<<p.lista[i].brend<<endl;
            o<<"Primeroci: "<<p.lista[i].primeroci<<endl;
        }

        return o;
    }


};

int main() {
    ocila ocila1 = {"Brend1", 5};
    ocila ocila2 = {"Brend2", 3};
    ocila ocila3 = {"Brend3", 7};

    prodavnica prod("Prodavnica", "Lokacija", 0, nullptr);
    cout << prod << endl;

    prod += ocila1;
    prod += ocila2;
    prod += ocila3;
    cout << prod << endl;

    prod -= ocila2;
    cout << prod << endl;

    ++prod;
    cout << prod << endl;

    --prod;
    cout << prod << endl;

    return 0;
}
