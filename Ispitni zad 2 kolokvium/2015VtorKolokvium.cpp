#include<iostream>
#include<string.h>
using namespace std;

class umetnichkoDelo {

    protected:

    char *avtor;
    float cena;

    public:

    umetnichkoDelo(char *a = "", float c = 0.0){
        if(a == NULL){
            avtor = new char[strlen("Nepoznat avtor") + 1];
            strcpy(avtor, "Nepoznat avtor");

            cena = c >= 0.0 ? c : 0.0;
        }else{
            avtor = new char[strlen(a) + 1];
            strcpy(avtor, a);

            cena = c >= 0.0 ? c : 0.0;
        }
    }

    umetnichkoDelo(const umetnichkoDelo &u){
        avtor = new char[strlen(u.avtor) + 1];
        strcpy(avtor, u.avtor);

        cena = u.cena;
    }

    virtual void pechati(){
        cout<<"Avtor: "<<avtor<<endl;
    }

    virtual float presmetajCena() = 0; 

};

class muzichkoDelo : public umetnichkoDelo {

    private:

    int godina;

    public:
    
    muzichkoDelo(char *a = "", float c = 0.0, int g = 0) : umetnichkoDelo(a, c) {
        godina = g >= 0 ? g : 0;
    }

    float presmetajCena(){
        float osnovnaCena = cena;
        if(godina < 1700){
            osnovnaCena += osnovnaCena * 0.1;
        }
        return osnovnaCena;
    }

    void pechati(){
        umetnichkoDelo::pechati();
        cout<<"Godina: "<<godina<<endl;
        cout<<"Cena: "<<presmetajCena()<<" denari"<<endl;
    }


};

class slikarskoDelo : public umetnichkoDelo {

    private:

    int stepen;

    public:

    slikarskoDelo(char *a = "", float c = 0.0, int s = 0) : umetnichkoDelo(a, c) {
        stepen = s >= 0 ? s : 0;
    }

    float presmetajCena(){
        float namalenaCena = cena;
        if(stepen > 0 && stepen <= 100) {
            namalenaCena = cena * (1 - (stepen / 100.0));
        }
        return namalenaCena;
    }

    void pechati(){
        umetnichkoDelo::pechati();
        cout<<"Stepen na oshtetenost: "<<stepen<<" %"<<endl;
        cout<<"Cena: "<<presmetajCena()<<" denari"<<endl;
    }

};

void najskapoDelo(umetnichkoDelo **lista, int N){
    umetnichkoDelo *max = lista[0];

    for(int i = 1; i < N; i++){
        if(lista[i]->presmetajCena() > max->presmetajCena()){
            max = lista[i];
        }
    }

    max->pechati();
}

int main() {

    umetnichkoDelo *dela[5];
    
    dela[0] = new muzichkoDelo("Avtor 1", 1000.0, 1700);
    dela[1] = new slikarskoDelo("Avtor 2", 2000.0, 50);
    dela[2] = new muzichkoDelo("Avtor 3", 1500.0, 1600);
    dela[3] = new slikarskoDelo("Avtor 4", 3000.0, 80);
    dela[4] = new slikarskoDelo("Avtor 5", 2500.0, 30);
    
    najskapoDelo(dela, 5);
    
    
    return 0;
}
