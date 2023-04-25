#include<iostream>
#include<string.h>
using namespace std;


class velosipedist{

    private:

    char ime[30];
    char prezime[30];
    int god;
    int poeni;

    public:

    velosipedist(char *i = "", char *p = "", int g = 0, int bod = 0){
        
        strncpy(ime, i, 29);
        ime[29] = 0;

        strncpy(prezime, p, 29);
        prezime[29] = 0;

        god = g >= 0 ? g : 0;
        poeni = bod >= 0 ? bod : 0;
    }

    ~velosipedist(){}

    int getPoeni(){
        return poeni;
    }

    void pechati(){
        cout<<ime<<" "<<prezime<<" "<<god<<" godini "<<poeni<<" poeni"<<endl;
    }

};

class veloTeam{

    private:

    char ime[30];
    char sponzor[20];
    int N;
    velosipedist lista[20];

    public:

    veloTeam(char *i = "", char *s = "", int d = 0, velosipedist *l = NULL){
        
        strncpy(ime, i, 29);
        ime[29] = 0;

        strncpy(sponzor, s, 19);
        sponzor[19] = 0;

        N = d >= 0 ? d : 0;

        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }
   
    }

    ~veloTeam(){}

    int poeni_tim(){
        int sum = 0;
        for(int i = 0; i < N; i++){
            sum += lista[i].getPoeni();
        }
        return sum;
    }

    void pechati(){
        cout<<"Ime na velosipedskiot team: "<<ime<<endl;
        cout<<"Sponzor na velosipedskiot team: "<<sponzor<<endl;
        cout<<"Broj na velosipedisti: "<<N<<endl;
        for(int i = 0; i< N; i++){
            lista[i].pechati();
        }
    }

};

int main(){

    velosipedist v1("Stole", "Dimitrievski", 25, 70);
    velosipedist v2("Domagoj", "Duvnjak", 28, 60);
    velosipedist v3("Stefan", "Ristovski", 22, 25);
    velosipedist v4("Enis", "Bardhi", 30, 100);
    velosipedist v5("Ilija", "Despotovski", 30, 120);

    velosipedist lista[5] = {v1, v2, v3, v4, v5};
    veloTeam team1("Phoenix", "Telekom", 5, lista);

    team1.pechati();
    cout<<"Vkupno poeni: "<<team1.poeni_tim()<<endl;

    return 0;
}