#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

enum tip {umetnicki, strucni};

class polica{

    private:

    char kod[50];
    int starost;

    public:

    polica(char *k = "", int s = 0){
        strncpy(kod, k, 49);
        kod[49] = 0;

        starost = s >= 0 ? s : 0;
    }

    virtual float vrednost(){
        float cena = 6000.0;
        cena *= pow(0.93, starost);  
        return cena;
    }

    virtual void pechati(){
        cout<<"Kod: "<<kod<<endl;
        cout<<"Godina na starost: "<<starost<<endl;
        cout<<"Vrednost na policata: "<<vrednost()<<endl;
    }

};

class knigi : public polica {

    private:

    tip book;
    int N;
    string *lista;

    public:

    knigi(char *k = "", int s = 0, tip b = umetnicki, int n = 0, string *l = NULL) : polica(k, s) {
        book = b;

        N = n >= 0 && n <= 20 ? n : 0;

        lista = new string[N];

        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }
    }

    knigi(const knigi &k) : polica(k){
        book = k.book;
        N = k.N;

        lista = new string[N];
        for(int i = 0; i < N; i++){
            lista[i] = k.lista[i];
        }
    }

    float vrednost(){
        float vrednost = polica::vrednost();

        if(book == strucni){
            vrednost += (vrednost * 0.2); 
        }

        for(int i = 0; i < N; i++){

            string naslov = lista[i];

            if(naslov[0] == 'A' || naslov[0] == 'E' || naslov[0] == 'I' || naslov[0] == 'O' || naslov[0] == 'U' || naslov[0] == 'a' || naslov[0] == 'e' || naslov[0] == 'i' || naslov[0] == 'o' || naslov[0] == 'u') {
                vrednost += 200.0;
            }else{
                vrednost += 300.0;
            }
        }

        return vrednost;
    }

    void pechati(){
        polica::pechati();
        cout<<"Tip na kniga: "<<book<<endl;
        cout<<"Broj na knigi na policata: "<<N<<endl;
        cout<<"Naslovite na knigite: "<<endl;

        for(int i = 0; i < N; i++){
            cout<<lista[i]<<endl;
        }
    }

    ~knigi(){
        delete [] lista;
    }

};

class alati : public polica {

    private:

    int N;
    int *lista;

    public:

    alati(char *k = "", int s = 0, int n = 0, int *l = NULL) : polica(k, s) {
        N = n >= 0 && n <= 10 ? n : 0;

        lista = new int[N];

        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }

    }

    alati(const alati &a) : polica(a) {
        N = a.N;

        lista = new int[N];
        for(int i = 0; i < N; i++){
            lista[i] = a.lista[i];
        }
    }

    float vrednost(){
        float vrednost = polica::vrednost();
        for(int i = 0; i < N; i++){
            vrednost += lista[i];
        }

        return vrednost;
    }

    ~alati(){
        delete [] lista;
    }

    void pechati(){
        polica::pechati();
        cout<<"Broj na alati na policata: "<<N<<endl;
        cout<<"Cenite na alatite: "<<endl;

        for(int i = 0; i < N; i++){
            cout<<lista[i]<<" denari"<<endl;
        }
    }


};

void najvredna(polica **lista, int N){

    polica *max = lista[0];

    for(int i = 0; i < N; i++){
        if(lista[i]->vrednost() > max->vrednost()){
            max = lista[i];
        }
    }

    cout<<"Najvredna polica e "<<endl;
    max->pechati();
}

float vkVrednost(polica **lista, int N){
    float vkupno = 0.0;

    for(int i = 0; i < N; i++){
        vkupno += lista[i]->vrednost();
    }
    cout<<"Vkupnata vrednost na policite e "<<vkupno<<" denari"<<endl;
    return vkupno;
}

int main()
{
    polica *E[4];
    string Naslovi1[3] = {"Programiranje i algoritmi", "Osnovi na elektrotehnika", "Fizika 1"};
    string Naslovi2[4] = {"Kako se kaleshe chelikot", "Kasni i porasni", "Papokot na svetot", "Ana Karenina"};
    
    knigi M1("A1Z1", 1, umetnicki, 3, Naslovi1);
    knigi M2("A2Z1", 1, strucni, 4, Naslovi2);
    
    int ceni[2] = {500, 5000};
    alati V1("A1Z2", 10, 2, ceni);
    
    E[0] = &M1;
    E[1] = &M2;
    E[2] = &V1;

    M1.pechati();
    cout<<endl;

    M2.pechati();
    cout<<endl;
    
    V1.pechati();
    cout<<endl;

    
    najvredna(E, 3);
    cout<<endl;
    vkVrednost(E, 3);
    
    return 0;
}
