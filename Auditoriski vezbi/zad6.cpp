#include<iostream>
#include<string.h>
using namespace std;

class smetka{

    protected:

    char imep[50];
    int broj;
    float saldo;

    public:

    smetka(char *ip = "", int b = 0, float s = 0.0){

        strncpy(imep, ip, 49);
        imep[49] = 0;
        broj = b;
        saldo = s >= 0.0 ? s : 0.0;
    }

    void deponiraj(float s){

        if(s >= 0.0){
            saldo += s;
        }
    }

    bool podigni(float s){

        if(s >= 0.0 && s <= saldo){

            saldo -= s;
            return true;

        }else{

        return false;

        }

    }

    void pregled(){
        cout<<"Korisnik "<<imep<< "so broj na smetka "<<broj<<" ima saldo "<<saldo<<endl;
    }

};

class smetkaPlus : public smetka{

    private:

    float maxZaem;
    float kamata;
    float minus;

    public:

    smetkaPlus(char *ip = "", int b = 0, float s = 0.0, float z = 0.0, float k = 0.0, float m = 0.0) : smetka(ip, b, s) {

        if(z >= 0.0 && k>= 0.0 && m == 0.0){
            maxZaem = z;
            kamata = k;
            minus = m;

        }else{

            maxZaem = kamata = minus = 0.0;
        }
    }

    smetkaPlus(smetka &o, float z = 0.0, float k = 0.0, float m = 0.0) : smetka(o){

        if(z >= 0.0 && k>= 0.0 && m == 0.0){
            maxZaem = z;
            kamata = k;
            minus = m;

        }else{
            maxZaem = kamata = minus = 0.0;

        }
    }

    void deponiraj(float s){

        if(minus == 0){
            
            smetka::deponiraj(s);

        }else{

            if(s <= minus){
                minus -= s;
            }else{
                smetka::deponiraj(s-minus);
                minus = 0.0;
            }
            
        }
    }

    bool podigni(float s){

        if(minus == 0.0 && saldo > s){
            smetka::podigni(s);
            return true;
        }else{

            if(((saldo + maxZaem) - minus) >= s){
                minus += s - saldo;
                saldo = 0;
                return true;
            }else{
                return false;
            }        
        }
    }    
    
};