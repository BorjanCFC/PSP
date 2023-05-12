#include<iostream>
#include<string.h>
using namespace std;

class TV{

    protected:

    char *proizvoditel;
    int godina;
    float oCena;
    char seriski[11];
    int boja;

    public:

    TV(char *p = "", int g = 1990, float oc = 0.0, char *s = "", int b = 0){
        proizvoditel = new char[strlen(p) + 1];
        strcpy(proizvoditel, p);

        godina = g >= 1990 && g<= 2023 ? g : 1990;
        oCena = oc >= 0.0 ? oc : 0.0;

        strncpy(seriski, s, 10);
        seriski[10] = 0;

        boja = b;
    }

    TV(const TV &t){

        proizvoditel = new char[strlen(t.proizvoditel) + 1];

        strcpy(proizvoditel, t.proizvoditel);
        strcpy(seriski,t.seriski);

        oCena = t.oCena;
        godina = t.godina;
        boja = t.boja;

    }

    TV &operator=(const TV &t){

        if(this == &t){
            return *this;
        }

        proizvoditel = new char[strlen(t.proizvoditel) + 1];

        strcpy(proizvoditel, t.proizvoditel);
        strcpy(seriski,t.seriski);

        oCena = t.oCena;
        godina = t.godina;
        boja = t.boja;

        return *this;
    }

    float getCena(){
        return oCena;
    }
    char *getProizvoditel(){
        return proizvoditel;
    }


};  

class HD : public TV {

    private:
    int rezolucija[2];
    int refresh;
    float dopCena;

    public:

    HD(char *p = "", int g = 1990, float oc = 0.0, char *s = "", int b = 0, int *rez = NULL, int ref = 0, float d = 0.0) : TV(p, g, oc, s, b) {

        rezolucija[0] = rez[0];
        rezolucija[1] = rez[1];

        refresh = ref;
        dopCena = d >= 0.0 ? d : 0.0;

    }

    float getCena(){

        if(strcmp(getProizvoditel(), "Samsung") == 0){
            return (oCena + dopCena)* 0.95;
        }else{
            return oCena + dopCena;
        }
    }

};

class triD : public TV {

    private:
    bool naocari;
    int brNaocari;
    float cena;

    public:

    triD(char *p = "", int g = 1990, float oc = 0.0, char *s = "", int b = 0, bool n = false, int brN = 0, float c = 0.0) : TV(p, g, oc, s, b) {
    
        if(n){
            naocari = true;
        }else{
            naocari = false;
        }

        brNaocari = brN >= 0 ? brN : 0;
        cena = c >= 0.0 ? c : 0.0;
    }

    float getCena(){
        if(naocari){
            return oCena + brNaocari*cena;
        }else{
            TV::getCena();
        }
    }

};