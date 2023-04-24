//let pilot aviokompanija

#include<iostream>
#include<string.h>
using namespace std;

class let{

    private:

    int sifra;
    char grad1[30];
    char grad2[30];
    int pilot;

    public:

    let(int s = 0, char *g1 = "", char *g2 = "",int p = 0){
        strncpy(grad1, g1, 29);
        grad1[29] = 0;
        strncpy(grad2, g2, 29);
        grad2[29] = 0;

        sifra = s >= 0 ? s : 0;
        pilot = p >= 0 ? p : 0;
    }

    void pechati(){
        cout<<sifra<<" :"<<grad1<<","<<grad2<<endl;
    }

    int getPilot(){
        return pilot;
    }

};

class pilot{

    private:

    int sifra;
    char ime[30];
    float plata;
    
    public:

    pilot(char *i = "", int s = 0, float p = 0.0){
        strncpy(ime, i, 29);
        ime[29] = 0;

        sifra = s >= 0 ? s : 0;
        plata = p >= 0 ? p : 0;  
    }

    float getPlata(){
        return plata;
    }

    int getSifra(){
        return sifra;
    }

    char *getIme(){
        return ime;
    }

};

class avioKompanija{

    private:

    let lista[15];
    int N;
    char ime[30];

    public:

    avioKompanija(let *l = NULL, int n = 0, char *i = ""){
        if(n >= 0){
            N = n;
        }else{
            N = 0;
        }

        for(int i = 0; i<N; i++){
            lista[i] = l[i];
        }

        strncpy(ime, i, 29);
        ime[29] = 0;
    }

    int proveri(int sifra){
        for(int i = 0; i<N; i++){
            if(lista[i].getPilot() == sifra){
                return i;
            }
        }
        return -1;
    }

    void plata(pilot *piloti, int d){
        for(int i = 0; i<d; i++){
            float plata = 0.0;
            for(int j = 0; j<N; j++){
                if(lista[j].getPilot() == piloti[i].getSifra()){
                    plata += piloti[i].getPlata();
                }
            }
            cout<<piloti[i].getIme()<<" plata"<<plata<<endl;
        }
    }

};
