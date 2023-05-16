#include<iostream>
#include<string.h>
using namespace std;

class registracija{

    private:

    string ime;
    int brs;
    int motor;
    float cena;
    char **zemji;
    int brZ;

    public:

    registracija(string i = "", int s = 0, int m = 0, float c = 0.0, char **z = NULL, int b = 0){
        ime = i;
        brs = s;
        motor = m >= 0 ? m : 0;
        cena = c >= 0.0 ? c : 0.0; 

        brZ = b >= 0 ? b : 0;

        zemji = new char*[brZ];
        for(int i = 0; i < brZ; i++){
            zemji[i] = new char[strlen(z[i]) + 1];
            strcpy(zemji[i], z[i]);
        }
    }

    registracija(const registracija &r){
        ime = r.ime;
        brs = r.brs;
        motor = r.motor;
        cena = r.cena;
        brZ = r.brZ;

        zemji = new char*[brZ];
        for(int i = 0; i < brZ; i++){
            zemji[i] = new char[strlen(r.zemji[i]) + 1];
            strcpy(zemji[i], r.zemji[i]);
        }

    }

    registracija &operator=(const registracija &r){
        if(this == &r){
            return *this;
        }

        for(int i = 0; i < brZ; i++){
            delete [] zemji[i];
        }

        delete [] zemji;

        ime = r.ime;
        brs = r.brs;
        motor = r.motor;
        cena = r.cena;
        brZ = r.brZ;

        zemji = new char*[brZ];
        for(int i = 0; i < brZ; i++){
            zemji[i] = new char[strlen(r.zemji[i]) + 1];
            strcpy(zemji[i], r.zemji[i]);
        }

        return *this;

    }

    ~registracija(){
        for(int i = 0; i < brZ; i++){
            delete [] zemji[i];
        }

        delete [] zemji;
    }

    virtual float iznos(){
        return cena;
    }

    int getMotor(){
        return motor;
    }

    void pechati(){
        cout<<"Ime: "<<ime<<endl;
        cout<<"Broj na shasija: "<<brs<<endl;
        cout<<"Cena: "<<cena<<endl;
        cout<<"Zafatnina na motor: "<<motor<<endl;
        cout<<"Broj na zemji: "<<brZ<<endl;
        cout<<"Zemji: "<<endl;

        for(int i = 0; i < brZ; i++){
            cout<<zemji[i]<<endl;
        }
    }

};

class reg_avto : public registracija {

    private:

    bool nezgoda;

    public:

    reg_avto(string i = "", int s = 0, int m = 0, float c = 0.0, char **z = NULL, int b = 0, bool n = false) : registracija(i, s, m, c, z, b) {
        nezgoda = n;
    }

    float iznos(){
        float c = registracija::iznos();

        if(getMotor() > 2000){
            c = c * 1.1;
        }

        if(!nezgoda){
            c = c * 0.95;
        }
    }

};

class reg_kamion : public registracija {

    private:

    int starost;

    public:

    reg_kamion(string i = "", int s = 0, int m = 0, float c = 0.0, char **z = NULL, int b = 0, int st = 0) : registracija(i, s, m, c, z, b) {
        starost = st >= 0 ? st : 0;
    }

    float iznos(){
        float c = registracija::iznos();
        int god = starost / 12;
        int procent = (god / 6) * 4;

        c = c*(1 + (procent/100));

        return c;
    }

};

float vkupno(registracija **lista, int N){

    float c = 0.0;

    for(int i =0 ; i < N; i++){
        c = c + lista[i]->iznos();
    }

    cout<<"Vkupniot iznos e: "<<c<<endl;
    return c;

}

// void minCena(registracija **lista, int N){

//     registracija *min = lista[0];

//     for(int i = 0; i < N; i++){
//         if(lista[i]->iznos() < min->iznos()){
//             min = lista[i];
//         }
//     }

//     min->pechati();
// }

registracija *sporedi_min(registracija *r1, registracija *r2){
    if(r1->iznos() < r2->iznos()){
        return r1;
    }else{
        return r2;
    }
}

void minCena(registracija **lista, int N){

    registracija *min = lista[0];

    for(int i = 1; i < N; i++){
        min = sporedi_min(min, lista[i]);
    }

    min->pechati();
}