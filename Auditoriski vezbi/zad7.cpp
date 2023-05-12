#include<iostream>
#include<string.h>
using namespace std;

class kredit{

    private:

    char ime[20];
    char prezime[30];
    int visina;
    float kamata;
    int meseci;
    int status;
    float rata;

    protected:
    int proverki;

    public:

    kredit(char *i = "", char *p = "", int v = 0, float k = 0.0, int m = 1, int s = 1, float r = 0.0){

        strncpy(ime, i, 19);
        ime[19] = 0;
        
        strncpy(prezime, p, 29);
        prezime[29] = 0;

        visina = v >= 0 ? v : 0;
        kamata = k >= 0.0 ? k : 0.0;
        meseci = m >= 0 ? m : 0;
        status = s == 0 || s == 1 ? s : 1;
        rata = r >= 0.0 ? r : 0.0;

        proverki = 0;

    }

    float getRata(){
        return rata;
    }

    int getVisina(){
        return visina;
    }

    int getMeseci(){
        return meseci;
    }

    void setRata(float r){
        rata = r >= 0.0 ? r : 0.0;
    }

    void setKamata(float k){
        kamata = k >= 0.0 ? k : 0.0;
    }

    float retDolg(){
        proverki++;
        return rata * meseci;
    }

    float zarabotka(){
        return retDolg() - visina;
    }

    void print(){
        cout<<"Korisnik "<<ime<<" "<<prezime<<" visina na kredit "<<visina<<" so mesechna rata od "<<rata<<" na "<<meseci<<" meseci "<<endl;
    }

    int brProverki(){
        return proverki;
    }

};

class godishenKredit : public kredit {

    private:

    float procent; // 0 - 100

    public:

    godishenKredit(char *i = "", char *p = "", int v = 0, float k = 0.0, int s = 1, float r = 0.0, float pro = 0.0) : kredit(i, p , v, k, 12, s, r) {
        procent = pro >= 0.0 && pro <= 100.0 ? pro : 0.0;
    }

    float retDolg(){
        proverki++;
        return ((getRata() - getRata() * (procent / 100)) * 6 + getRata() * 6);
    }

    float zarabotka(){
        return retDolg() - getVisina();
    }

    void print(){
        kredit::print();
        cout<<"Godisen kredit so procent na namaluvanje za prvite 6 meseci od "<<procent<<endl;
    }

};

class fiksniKrediti : public kredit{

    private:

    float minimum;

    public:

    fiksniKrediti(char *i = "", char *p = "", int v = 0, float k = 0.0, int m = 1, int s = 1, float r = 0.0 , float min = 0.0) : kredit(i, p, v, k, m ,s ,r) {
        minimum = min >= 0.0 ? min : 0.0;

        if(minimum > getVisina()){
            setKamata(0.0);
            setRata(getVisina() / getMeseci());
        }

    }

    float getdolg(){
            if(minimum > getVisina()){
                proverki++;
                return getVisina();
            }else{
                kredit::retDolg();
            }
    }

    void print(){
        kredit::print();
        cout<<" so minimum kredit od "<<minimum<<endl;
    }

};