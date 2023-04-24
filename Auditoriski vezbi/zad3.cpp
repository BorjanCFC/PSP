//magacin sortiranje evidencija proizvodi

#include<iostream>
#include<string.h>
using namespace std;

class proizvod{

    private:

    char ime[20];
    int sifra; // 0
    int zaliha; // 1
    int kolicina; // 2

    public:

    proizvod(char *i = "", int s = 0, int z = 0, int k = 0){
        strncpy(ime, i, 19);
        ime[19] = 0;

        sifra = s >= 0 ? s : 0;
        zaliha = z >= 0 ? z : 0;
        kolicina = k >= 0 ? k : 0;
    }

    char *getIme(){
        return ime;
    }

    int getsifra(){
        return sifra;
    }

    int getZaliha(){
        return zaliha;
    }

    int getKolicina(){
        return kolicina;
    }

};

class magacin{

    private:

    proizvod lista[100];
    int N;

    public:

    magacin(proizvod *l = NULL, int n = 0){
        if(n >= 0){
            N = n;
        }else{
            N = 0;
        }

        for(int i = 0; i<N; i++){
            lista[i] = l[i];
        }
    }
    //false - nasoka na sortiranje(po opagjacki redosled)

    void sort(bool nasoka = false, int k = 1){
        for(int i = 0; i<N; i++){
            for(int j = i+1; j<N; j++){
                int v1, v2;
                if(k == 0){
                    v1 = lista[i].getsifra();
                    v2 = lista[j].getsifra();
                }else if(k == 1){
                    v1 = lista[i].getZaliha();
                    v2 = lista[j].getZaliha();
                }else if(k == 2){
                    v1 = lista[i].getKolicina();
                    v2 = lista[j].getKolicina();
                }
                if((nasoka == true && v2<v1) || (nasoka == false && v2>v1)){
                    proizvod pom = lista[i];
                    lista[i] = lista[j];
                    lista[j] = pom;
                }
            }
        }
    }

};