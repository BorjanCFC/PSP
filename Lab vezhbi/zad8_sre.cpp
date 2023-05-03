#include<iostream>
#include<string.h>
using namespace std;

struct sostojka{
    char ime[30];
    int masa;
};

class proizvod{

    private:

    char *ime;
    int cena;
    int N;
    sostojka *lista;

    public:

    proizvod() {
        ime = new char[50];

        strcpy(ime, "Becutan krema za sonchanje");
        cena = 318;
        N = 4;

        lista = new sostojka[N];

        strcpy(lista[0].ime, "maslinovo maslo");
        lista[0].masa = 20;

        strcpy(lista[1].ime, "ekstrakt od kamilica");
        lista[1].masa = 10;

        strcpy(lista[2].ime, "vitamin E");
        lista[2].masa = 1;

        strcpy(lista[3].ime, "de pantenol");
        lista[3].masa = 20;

   }

   proizvod(char *i, int c, int d, sostojka *l){

        ime = new char[strlen(i) + 1];
        strcpy(ime, i);

        cena = c >= 0 ? c : 0;
        N = d >= 0 ? d : 0;

        lista = new sostojka[N];

        for(int i = 0; i < N; i++){
            strcpy(lista[i].ime, l[i].ime);
            lista[i].masa = l[i].masa;
        }

   }

   proizvod(const proizvod &p){
        cena = p.cena;
        N = p.N;

        ime = new char[strlen(p.ime) + 1];
        strcpy(ime, p.ime);

        lista = new sostojka[N];

        for(int i = 0; i < N; i++){
            strcpy(lista[i].ime, p.lista[i].ime);
            lista[i].masa = p.lista[i].masa;
        }

   }

   void pechati() {
        cout<<"Ime na prozivodot: "<<ime<<endl;
        cout<<"Cena: "<<cena<< endl;
        cout<<"Broj na sostojki: "<< N<<endl;
        cout<<"Sostojki: "<<endl;
        for(int i = 0; i < N; i++) {
            cout<<lista[i].ime<<" "<<lista[i].masa<<" grama"<<endl;
        }
    }

    ~proizvod(){
        delete [] lista;
        delete [] ime;
    }

    void dodadiSostojka(sostojka &m){

    sostojka *pom = new sostojka[N + 1]; 

    
    strcpy(pom[0].ime, m.ime);
    pom[0].masa = m.masa;

    
    for(int i = 0; i < N; i++) {
        strcpy(pom[i+1].ime, lista[i].ime);
        pom[i+1].masa = lista[i].masa;
    }

    
    delete [] lista;
    N++;

    lista = new sostojka[N];

        for(int i = 0; i<N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;
    }

    void brishiSostojka(sostojka &m){

        sostojka *pom = new sostojka[N-1];
        int k = 0;

        for(int i = 0; i < N; i++){
            if(strcmp(lista[i].ime, m.ime) != 0 && (lista[i].masa, m.masa) != 0){
                pom[k] = lista[i];
                k++;
            }
        }

        delete [] lista;

        N--;

        lista = new sostojka[N];

        for(int i = 0; i<N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;

    }


};

int main() {
    
    proizvod p1;
    p1.pechati();

    
    sostojka s1 = {"aloe vera", 15};
    p1.dodadiSostojka(s1);

    cout<<endl;

    cout<<"Proizvodot so dodadena sostojka: "<<endl;
    p1.pechati();

    
    sostojka s2 = {"vitamin E", 1};
    p1.brishiSostojka(s2);

    cout<<endl;

    cout<<"Proizvodot so izbrisana sostojka: " << endl;
    p1.pechati();

    return 0;
    
}