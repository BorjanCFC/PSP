#include<iostream>
#include<string.h>
using namespace std;

class odmor {

    protected:

    char *ime;
    int N;
    int oCena;
    int poseti;
    int *listaCeni;

    public:

    odmor(char *i = "", int n = 0, int c = 0, int p = 0, int *l = NULL){
        ime = new char[strlen(i) + 1];
        strcpy(ime, i);

        N = n >= 0 ? n : 0;
        oCena = c >= 0 ? c : 0;
        poseti = p >= 0 ? p : 0;

        listaCeni = new int[poseti];
        for(int i = 0; i < poseti; i++){
            listaCeni[i] = l[i];
        }
    }

    odmor(const odmor &o){
        ime = new char[strlen(o.ime) + 1];
        strcpy(ime, o.ime);

        N = o.N;
        oCena = o.oCena;
        poseti = o.poseti;

        listaCeni = new int[poseti];
        for(int i = 0; i < poseti; i++){
            listaCeni[i] = o.listaCeni[i];
        }
    }

    ~odmor(){
        delete [] ime;
        delete [] listaCeni;
    }

    virtual int presmetajCena(){

        int vkupnaCena = oCena;
        for(int i = 0; i < poseti; i++){
            vkupnaCena += listaCeni[i];
        }

        return vkupnaCena;
    }


    friend bool operator>(odmor &o1, odmor o2) {
        return o1.presmetajCena() > o2.presmetajCena();
    }

    virtual void pechati(){
        cout<<"Destinacija: "<<ime<<endl;
        cout<<"Denovi: "<<N<<endl;
        cout<<"Osnovna cena na aranzhmanot: "<<oCena<<" evra"<<endl;
        cout<<"Broj na fakultativni poseti: "<<poseti<<endl;
        cout<<endl;
        cout<<"Ceni na fakultativnite poseti: "<<endl;
        for(int i = 0; i < poseti; i++){
            cout<<listaCeni[i]<<" evra"<<endl;
        }
    }

    char *getIme(){
        return ime;
    }

    int getN(){
        return N;
    }

};

class leten : public odmor {

    private:

    int tipPrevoz;
    int aranzhman;

    public:

    leten(char *i = "", int n = 0, int c = 0, int p = 0, int *l = NULL, int tip = 0, int a = 1) : odmor(i, n, c, p, l) {

        if(tip == 0 || tip == 1 || tip == 2){
            tipPrevoz = tip;
        }else{
            tipPrevoz = 0;
        }

        if(a == 1 || a == 2){
            aranzhman = a;
        }else{
            aranzhman = 1;
        }
    }

    int presmetajCena(){
       int cena = odmor::presmetajCena();

       if(aranzhman == 1){
            cena += 100;
       }else if(aranzhman == 2){
            cena += 150;
       }

       if(tipPrevoz == 2){
            cena += 100;
       }

       return cena;
    }

    friend bool operator>(leten &l1, leten &l2){
        return l1.presmetajCena() > l2.presmetajCena();
    } 

    void pechati(){
        odmor::pechati();

        if(tipPrevoz == 0){
            cout<<"Tip na prevoz: avtomobil"<<endl;
        }else if(tipPrevoz == 1){
            cout<<"Tip na prevoz: avtobus"<<endl;
        }else if(tipPrevoz == 2){
            cout<<"Tip na prevoz: avion"<<endl;
        }

        if(aranzhman == 1){
            cout<<"Polupansionski aranzhman"<<endl;
        }else if(aranzhman == 2){
            cout<<"Pansionski aranzhman"<<endl;
        }
        cout<<"Vkupnata cena na cel odmor e "<<presmetajCena()<<" evra"<<endl;
    }

};

class zimski : public odmor {

    private:

    bool ski;
    int cenaKarta;

    public:

    zimski(char *i = "", int n = 0, int c = 0, int p = 0, int *l = NULL, bool s = false, int cc = 0) : odmor(i, n, c, p, l) {
        ski = s;
        cenaKarta = cc >= 0 ? cc : 0;
    }

    int presmetajCena(){
        int vkCena = odmor::presmetajCena();
        if(ski){
            vkCena += cenaKarta * N;
        }

        return vkCena;
    }

    friend bool operator>(zimski &z1, zimski &z2){
        return z1.presmetajCena() > z2.presmetajCena();
    }

    void pechati(){
        odmor::pechati();

        if(ski){
            cout<<"Uplatena ski karta"<<endl;
            cout<<"Cena na ski kartata za eden den: "<<cenaKarta<<endl;
        }
        cout<<"Vkupnata cena na cel odmor e "<<presmetajCena()<<" evra"<<endl;
    }



};


void najdiSporedKategorija(odmor **lista, int brOdmori, int N, char *ime){
    odmor *max = lista[0];

    for(int i = 1; i < brOdmori; i++){
        if(strcmp(lista[i]->getIme(), ime) == 0 && lista[i]->getN() <= N && lista[i]->presmetajCena() > max->presmetajCena()){
            max = lista[i];
        }
    }

    max->pechati();
}

int main()
{
    odmor *odmori[3];
    int ceni1[] = {50, 30, 20, 60};
    int ceni2[] = {20, 25, 20};
    int ceni3[] = {10, 15, 30};

    odmori[0] = new leten("Maldivi", 10, 1000, 4, ceni1, 2, 2);
    odmori[1] = new zimski("Maldivi", 7, 500, 3, ceni2, true, 40);
    odmori[2] = new leten("Santorini", 7, 700, 3, ceni3, 2, 1);

    najdiSporedKategorija(odmori, 3, 8, "Maldivi");


    return 0;
}


