#include<iostream>
#include<string.h>
using namespace std;

class medium{

    private:

    string ime;
    int brV;
    int brL;

    public:

    medium(string i = "", int br = 0, int bl = 0){
        brV = br >= 0 ? br : 0;
        brL = bl >= 0 ? bl : 0;
        ime = i;
    }

    virtual int index(){
        return brV * 5 - brL;
    }

    ~medium(){}

    virtual void pechati(){
        cout<<"Ime na mediumot: "<<ime<<endl;
        cout<<"Broj na vraboteni: "<<brV<<endl;
        cout<<"Broj na lazhni vesti: "<<brL<<endl;
    }


};

class TV : public medium {

    private:

    bool profil;

    public:

    TV(string i = "", int br = 0, int bl = 0, bool p = false) : medium(i, br, bl) {
        profil = p;
    }

    int index(){
        if(profil){
            return medium::index() + 20;
        }else{
            return medium::index();
        }
    }

    void pechati(){
        medium::pechati();
        cout<<profil<<endl;
    }

};

class portal : public medium {

    private:

    int brP;

    public:

    portal(string i = "", int br = 0, int bl = 0, int bp = 0) : medium(i, br, bl) {
        brP = bp >= 0 ? bp : 0;
    }

    int index(){
        int procent = (brP/20) * 5;
        return medium::index() * (1 + (procent / 100)); 
    }

    void pechati(){
        medium::pechati();
        cout<<"Broj na postovi: "<<brP<<endl;
    }


};

int pomalIndex(medium *m1, medium *m2){
    if(m1->index() < m2->index()){
        return 1;
    }else{
        return 0;
    }
}

int najmalIndex(medium **lista, int N){

    int min = 0;
    for(int i = 1; i < N; i++){
        if(pomalIndex(lista[i],lista[min]) == 1){
            min = i;
        }
    }

    return min;
}