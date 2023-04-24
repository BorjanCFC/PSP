//kompanija evidencija vraboteni

#include <iostream>
#include<string.h>
using namespace std;

class Vraboten{

    private:
    char ime[30];
    float plata; // >= 0
    int pozicija;   // 0 - vraboten, 1 - rakovoditel, 2 - direktor

    public:

    Vraboten(){
        ime[0] = '\0';
        plata = 0.0;
        pozicija = 0;
    }

    Vraboten(char *i, float p, int poz){
        strncpy(ime, i, 29);
        ime[29] = 0;

        if(p >= 0.0){
            plata = p;
        }else{
            plata = 0.0;
        }

        if(poz >= 0 && poz <= 2){
            pozicija = poz;
        }else{
            pozicija = 0;
        }
    }

    void setIme(char *i){
        strncpy(ime, i, 29);
        ime[29] = 0;
    }

    void setPlata(float p){
        if(p >= 0.0){
            plata = p;
        }else{
            plata = 0.0;
        }
    }

    void setPozicija(int poz){
        if(poz >= 0 && poz <= 2){
            pozicija = poz;
        }else{
            pozicija = 0;
        }
    }

    char *getIme(){
        return ime;
    }

    float getPlata(){
        return plata;
    }

    int getPozicija(){
        return pozicija;
    }

    void pechati(){
        cout<<ime<<" "<<plata;
        switch(pozicija){
            case 0: 
            cout<<" vraboten"<<endl;
            break;
            case 1: 
            cout<<" rakovoditel"<<endl;
            break;
            case 2: 
            cout<<" direktor"<<endl;
            break;
            
        }
    }

};

int main(){

    int N;
    Vraboten lista[1000];

    cout<<"Vnesi go N:";
    cin>>N;

    char ime[200];
    int poz;
    float plata;

    for(int i = 0; i<N ; i++){

        cout<<"Vnesi podatoci za vraboten "<<i+1<<": ";
        cin>>ime>>plata>>poz;

        lista[i].setIme(ime);
        lista[i].setPlata(plata);
        lista[i].setPozicija(poz);

    }

    for(int i = 0; i<N; i++){
        for(int j = i+1; j<N; j++){
            if(lista[j].getPlata() > lista[i].getPlata()){
                Vraboten pom = lista[i];
                lista[i] = lista[j];
                lista[j] = pom;
            }
        }
    }

    for(int i = 0; i<N; i++){
        lista[i].pechati();
    }

    return 0;
}