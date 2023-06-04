#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

class kujnskiElementi {

    private:

    string ime;
    bool materijal;  // 1 - medijapan 0 - iverka
    float troshok;
    int meseci;

    public:

    kujnskiElementi(string i = "", bool mat = false, float t = 0.0, int m = 0){
        ime = i;
        materijal = mat;
        troshok = t >= 0.0 ? t : 0.0;
        meseci = m >= 0 ? m : 0;
    }

    virtual void pechati(){
        cout<<"Ime na proizvoditel: "<<ime<<endl;

        if(materijal){
            cout<<"Materijalot e medijapan"<<endl;
        }else{
            cout<<"Materijalot e iverka"<<endl;
        }

        cout<<"Mesechen troshok: "<<troshok<<endl;
        cout<<"Meseci: "<<meseci<<endl;
        cout<<"Cena: "<<presmetajCena()<<" denari"<<endl;
    }

    virtual float presmetajCena(){
        float cena;

        if(materijal){
            cena = 4000;
        }else{
            cena = 2000;
        }

        return cena + (troshok * meseci);
    }

    virtual float getCena(){
        return presmetajCena();
    }

};

class kujnskiMasi : public kujnskiElementi {

    private:

    int povrshina;
    int brFioki;
    float lista[10];

    public:

    kujnskiMasi(string i = "", bool mat = false, float t = 0.0, int m = 0, int p = 0, int br = 0, float *l = NULL) : kujnskiElementi(i, mat, t, m) {
        povrshina = p >= 0 ? p : 0;
        brFioki = br >= 0  && br <= 10 ? br : 0;

        for(int i = 0; i < brFioki; i++){
            lista[i] = l[i];
        }
    }

    void pechati(){
        kujnskiElementi::pechati();
        cout<<"Povrshina: "<<povrshina<<endl;
        cout<<"Broj na fioki: "<<brFioki<<endl;
        cout<<"Zafatnina na fiokite: "<<endl;

        for(int i = 0; i < brFioki; i++){
            cout<<lista[i]<<" metri kubni"<<endl;
        }
    }

    float presmetajCena(){

        float cena = kujnskiElementi::presmetajCena();
        cena += pow(0.75, povrshina);
        cena += pow(0.7, brFioki);

        return cena;
    }

    float getCena(){
        return presmetajCena();
    }

};
 
class visechkiElementi : public kujnskiElementi {

    private:

    int brVratichki;
    int brPolici;

    public:
     
    visechkiElementi(string i = "", bool mat = false, float t = 0.0, int m = 0, int brV = 0, int brP = 0) : kujnskiElementi(i, mat, t, m) {
        brVratichki = brV >= 0 ? brV : 0;
        brPolici = brP >= 0 ? brP : 0;
    }

    void pechati(){
        kujnskiElementi::pechati();
        cout<<"Broj na vratichki: "<<brVratichki<<endl;
        cout<<"Broj na polici: "<<brPolici<<endl;
    }

    float presmetajCena(){
        float cena = kujnskiElementi::presmetajCena();
        cena += 500 * brVratichki;
        cena += 2000 * brPolici;

        return cena;
    }

    float getCena(){
        return presmetajCena();
    }

};

void najevtin(kujnskiElementi **lista, int N){

    kujnskiElementi *min = lista[0];
    for(int i = 0; i < N; i++){
        if(lista[i]->getCena() < min->getCena()){
            min = lista[i];
        }
    }

    min->pechati();
}

float vkcena(kujnskiElementi **lista, int N){
    float cena = 0.0;
    for(int i = 0; i < N; i++){
        cena += lista[i]->getCena();
    }
    return cena;
} 

int main()
{
    kujnskiElementi *E[3];
    float Fioki1[3] = {0.2, 0.3, 0.25};

    kujnskiMasi M1("Simpo", false, 100, 2, 1.2, 3, Fioki1);
    float Fioki2[4] = {0.2, 0.1, 0.15, 0.15};

    kujnskiMasi M2("Kasa Italia", true, 120, 2, 1.5, 4, Fioki2);
    visechkiElementi V1("Solo Prom", false, 150, 3, 3, 2);

    E[0] = &M1;
    E[1] = &M2;
    E[2] = &V1;

    M1.pechati();
    M2.pechati();
    V1.pechati();

    najevtin(E, 3);
    cout << endl;

    cout << "Vkupnata cena na proizvodite e: " << vkcena(E, 3) << endl;
    return 0;
}




