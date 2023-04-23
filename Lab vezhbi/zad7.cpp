#include <iostream>
#include <string>

using namespace std;

class kosarkar {
    private:

        string ime;
        int plata;

    public:

        kosarkar(){
            ime = "";
            plata = 0;
        }

        kosarkar(string i, int p){
            ime = i;
            plata = p;
        }

        void pechati(){
            cout<<"Ime: "<<ime<<endl;
            cout<<"Plata: "<<plata<<" denari"<<endl;
        }

        float func(double prosek) {
            return plata + 50 * prosek;
        }

};

class ekipa {
    private:

        string ime;
        int brojKosarkari;
        float prosekPoeni;
        kosarkar kosarkari[8];

    public:

        ekipa(){
            ime = "";
            brojKosarkari = 0;
            prosekPoeni = 0.0;
        }

        ekipa(string i, int brK, float p, kosarkar k[]) {
            ime = i;
            brojKosarkari = brK;

            if (p >= 0.0){
                prosekPoeni = p;
            }else{
                prosekPoeni = 0.0;
            }

            for(int j=0;j<brojKosarkari;j++) {
                kosarkari[j] = k[j];
            }
        }

        void pechati(){

            cout<<"Ime na ekipata: "<<ime<<endl;
            cout<<"Broj na kosarkari: "<<brojKosarkari<<endl;
            cout<<"Prosek poeni: "<<prosekPoeni<<endl;

            for(int i=0;i<brojKosarkari;i++){
                kosarkari[i].pechati();
                float plata = kosarkari[i].func(prosekPoeni);
                cout<<"Plata: "<<plata<<" denari"<<endl;
            }
        }
};

int main(){
    
    kosarkar players[5];
    string imeEkipa;
    float prosekPoeni;

    for(int i=0;i<5;i++){
        string ime;
        int plata = 30000;

        cout<<"Vnesi ime na kosarkar "<<i+1<< ": ";
        cin>>ime;
        players[i] = kosarkar(ime, plata);
    }

    cout<<"Vnesi ime na ekipata: ";
    cin>>imeEkipa;

    cout<<"Vnesi prosek poeni: ";
    cin>>prosekPoeni;

    ekipa team(imeEkipa, 5, prosekPoeni, players);

    cout<<"Podatoci za ekipata: " << endl;
    team.pechati();

    return 0;
}