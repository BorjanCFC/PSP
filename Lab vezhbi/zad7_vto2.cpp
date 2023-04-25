#include<iostream>
#include<string.h>
using namespace std;

class muzicar{

    private:

    char ime[30];
    int br;
    float plata;

    public:

    muzicar(char *i = "", int b = 0, float p = 0.0){

        strncpy(ime, i, 29);
        ime[29] = 0;

        br = b >= 0 ? b : 0;
        plata = p >= 0.0 ? p : 0.0;
    }

    void pechati(){
        cout<<ime<<" "<<br<<" br na instrumenti "<<plata<<" plata"<<endl;
    }

    void presmetajPlata(int komp){
        plata += 100*komp;
        plata += 200*br;
    }

};

class orkestar{

    private:

    char ime[30];
    int N;
    int komp;
    muzicar lista[10];

    public:

    orkestar(char *i = "", int n = 0, int k = 0, muzicar *l = NULL){
        
        strncpy(ime, i, 29);
        ime[29] = 0;

        N = n >= 0 ? n : 0;
        komp = k >= 0 ? k : 0;

        for(int i = 0; i < n; i++){
            lista[i] = l[i];
        }

    }

    void pechati(){
        cout<<"Ime na orkestarot: "<<ime<<endl;
        cout<<"Broj na muzicari: "<<N<<endl;
        cout<<"Aktivni kompozicii: "<<komp<<endl;
        cout<<"Muzicari: ";
        for(int i = 0; i < N; i++){
            lista[i].pechati();
        }
    }

};

int main(){
    char imeOrkestar[30];
    int brojMuzicari = 5;
    int kompozicii;
    int komp;

    cout<<"Vnesete ime na orkestarot: ";
    cin>>imeOrkestar;

    cout<<"Vnesete broj na kompozicii: ";
    cin>>kompozicii;

    muzicar listaMuzicari[5];
    for(int i = 0; i < 5; i++){
        char imeMuzicar[30];
        int brInstrumenti;
        cout<<"Vnesete ime na muzicarot "<<i+1<<": ";
        cin>>imeMuzicar;
        cout<<"Vnesete broj na instrumenti za muzicarot "<<i+1<<": ";
        cin>>brInstrumenti;
        cout<<"Vnesete broj na kompozicii za muzicarot"<<i+1<<": ";
        cin>>komp;

        listaMuzicari[i] = muzicar(imeMuzicar, brInstrumenti, 20000);
        listaMuzicari[i].presmetajPlata(komp);
        listaMuzicari[i].presmetajPlata(brInstrumenti);
    }

    orkestar ork(imeOrkestar, brojMuzicari, kompozicii, listaMuzicari);
    cout<<endl;
    ork.pechati();

    return 0;
}