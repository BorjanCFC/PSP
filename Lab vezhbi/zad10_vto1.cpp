#include<iostream>
#include<string.h>
using namespace std;

class prevoz {

    private:

    int tezhina;
    float potroshuvacka;

    public:

    prevoz(int t = 0, float p = 0) {
        tezhina = t >= 0 ? t : 0;
        potroshuvacka = p >= 0.0 ? p : 0.0;
    }

    ~prevoz() {}

    virtual void pechati(){
        cout<<"Tezhina: "<<tezhina<<" kg"<<endl;
        cout<<"Potroshuvacka na 100km: "<<potroshuvacka<<endl;
    }

    virtual float presmetajPotroshuvacka(){
        return tezhina * potroshuvacka;
    }

    int getTezhina(){
        return tezhina;
    }
    
    float getPotroshuvachka(){
        return potroshuvacka;
    }

};

class avion : public prevoz {

    private:

    bool tip; // 1 - mlazen, 0 - propeler

    public:

    avion(int t = 0, float p = 0, bool tp = false) : prevoz(t, p) {
        tip = tp;
    }

    ~avion() {}

    void pechati(){
        prevoz::pechati();
        if(tip){
            cout<<"Avionot e mlazen."<<endl;
        }else{
            cout<<"Avionot e so propeler."<<endl;
        }
    }

    float presmetajPotroshuvacka(){
        float p = prevoz::presmetajPotroshuvacka();

        if(tip){
            p += (p * 0.3);
        }

        return p;
    }

};

class voz : public prevoz {

    private:

    int *tezhini;
    int N;

    public:

    voz(int t = 0, float p = 0, int *te = NULL, int n = 0) : prevoz(t, p) {
        N = n >= 0 && n <= 10 ? n : 0;

        tezhini = new int{N};
        for(int i = 0; i < N; i++){
            tezhini[i] = te[i];
        }
    }

    ~voz(){
        delete [] tezhini;
    }

    void pechati(){
        prevoz::pechati();
        cout<<"Broj na vagoni: "<<N<<endl;
        cout<<"Tezhini na vagonite "<<endl;
        for(int i = 0; i < N; i++){
            cout<<tezhini[i]<<" kg"<<endl;
        }
    }

    int presmetajTezhina(){
        int tezhina = getTezhina();
        for (int i = 0; i < N; i++) {
            tezhina += tezhini[i]; 
        }
        return tezhina;
    }

    float presmetajPotroshuvacka() {
        return presmetajTezhina() * prevoz::getPotroshuvachka(); 
    }


};

int pomalaPotroshuvacka(prevoz *p1, prevoz *p2){
    if(p1->presmetajPotroshuvacka() < p2->presmetajPotroshuvacka()){
        return 1;
    }else{
        return 0;
    }
}

int najmalaPotroshuvachka(prevoz** lista) {

    int index = 0;
    float min = lista[0]->presmetajPotroshuvacka();

    for (int i = 1; lista[i] != NULL; i++) {
        if (lista[i]->presmetajPotroshuvacka() < min) {
            min =  lista[i]->presmetajPotroshuvacka();
            index = i;
        }
    }

    cout<<"Indeks: "<<index<<endl;
    return index;

}

int main() {
    prevoz* E[5];

    avion G1(3000, 0.01, true);
    avion G2(2000, 0.015, false);

    int vagoni1[10] = {2000, 4000, 4000, 3000};
    voz K1(10000, 0.001, vagoni1, 4);
    int vagoni2[10] = {4000, 8000, 8000, 10000, 3000, 3000};
    voz K2(8000, 0.0009, vagoni2, 6);
    
    E[0] = &G1;
    E[1] = &G2;
    E[2] = &K1;
    E[3] = &K2;
    E[4] = NULL;

    cout << (pomalaPotroshuvacka(E[0], E[1]) ? "Prvoto prevozno sretstvo" : "Vtoroto prevozno sretstvo") << " troshi pomalku" << endl;
    E[najmalaPotroshuvachka(E)]->pechati();

    return 0;
}
