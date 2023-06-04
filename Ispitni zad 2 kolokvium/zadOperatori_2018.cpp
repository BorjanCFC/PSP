#include<iostream>
#include<string.h>
using namespace std;

struct sostojka {

    string ime;
    float masa;

};

class kozmetika{

    private:

    string ime;
    float cena;
    int N;
    sostojka *lista;

    public:

    kozmetika(string i = "", float c = 0.0, int n = 0, sostojka *l = NULL){
        ime = i;
        cena = c >= 0 ? c : 0;
        N = n >= 0 ? n : 0;

        lista = new sostojka[N];
        for(int i = 0; i < N; i++){
            lista[i].ime = l[i].ime;
            lista[i].masa = l[i].masa;
        }
    }

    kozmetika(const kozmetika &k){
        ime = k.ime;
        cena = k.cena;
        N = k.N;

        lista = new sostojka[N];
        for(int i = 0; i < N; i++){
            lista[i].ime = k.lista[i].ime;
            lista[i].masa = k.lista[i].masa;
        }

    }

    ~kozmetika(){
        delete [] lista;
    }

    kozmetika &operator+=(sostojka &m){
        sostojka *pom = new sostojka[N+1];

        for(int i = 0; i < N; i++){
            pom[i].ime = lista[i].ime;
            pom[i].masa = lista[i].masa;
        }

        pom[N].ime = m.ime;
        pom[N].masa = m.masa;

        N++;

        delete [] lista;

        lista = new sostojka[N];

        for(int i = 0; i < N; i++){
            lista[i].ime = pom[i].ime;
            lista[i].masa = pom[i].masa;
        }

        delete [] pom;

        return *this;
    }

    kozmetika &operator-=(sostojka &m){
        sostojka *pom = new sostojka[N+1];

        pom[0].ime = m.ime;
        pom[0].masa = m.masa;

        for(int i = 0; i < N; i++){
            pom[i+1].ime = lista[i].ime;
            pom[i+1].masa = lista[i].masa;
        }

        N++;

        delete [] lista;

        lista = new sostojka[N];

        for(int i = 0; i < N; i++){
            lista[i].ime = pom[i].ime;
            lista[i].masa = pom[i].masa;
        }

        delete [] pom;

        return *this;

    }

    kozmetika &operator++(){
        sostojka *pom = new sostojka[N-1];

        for(int i = 0; i < N - 1; i++){
            pom[i].ime = lista[i].ime;
            pom[i].masa = lista[i].masa;
        }

        N--;

        delete [] lista;

        lista = new sostojka[N];

        for(int i = 0; i < N; i++){
            lista[i].ime = pom[i].ime;
            lista[i].masa = pom[i].masa;
        }

        delete [] pom;

        return *this;
    }

    kozmetika &operator--(){
        sostojka *pom = new sostojka[N-1];

        for(int i = 1; i < N; i++){
            pom[i-1].ime = lista[i].ime;
            pom[i-1].masa = lista[i].masa;
        }

        N--;

        delete [] lista;

        lista = new sostojka[N];

        for(int i = 0; i < N; i++){
            lista[i].ime = pom[i].ime;
            lista[i].masa = pom[i].masa;
        }

        delete [] pom;

        return *this;
    }

    friend ostream &operator<<(ostream &o, const kozmetika &k){

        o<<"Ime na proizvodot: "<<k.ime<<endl;
        o<<"Cena: "<<k.cena<<endl;
        o<<"Broj na sostojki: "<<k.N<<endl;
        o<<"Sostojki: "<<endl;

        for(int i = 0; i < k.N; i++){
            o<<k.lista[i].ime<<" "<<k.lista[i].masa<<" grama"<<endl;
        }
        return o;
    }

};

int main() {
    sostojka s1 = {"Maslinovo maslo", 20.0};
    sostojka s2 = {"Ekstrakt od kamilica", 10.0};
    sostojka s3 = {"Vitamin E", 1.0};

    sostojka sostojki[3] = {s1, s2, s3};

    kozmetika k1("Bekutan krema za sonchanje", 318.0, 3, sostojki);

    cout<<k1<<endl;

    sostojka s4 = {"De Pantenol", 20.0};
    k1 += s4;

    cout<<k1<<endl;

    sostojka s5 = {"Aloe vera", 15.0};
    k1 -= s5;
    
    cout<<k1<<endl;

    ++k1;

    
    cout<<k1<<endl;

    --k1;


    cout<<k1<<endl;

    return 0;
}
