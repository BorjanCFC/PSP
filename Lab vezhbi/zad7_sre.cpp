#include<iostream>
#include<string.h>
using namespace std;

class student{

    private:

    char ime[30];
    char prezime[30];
    char indeks[10];
    int brPred;
    float procent;

    public:

    student(char *i = "", char *p = "", char *ind = "", int br = 0, float proc = 0.0 ){
        
        strncpy(ime, i, 29);
        ime[29] = 0;

        strncpy(prezime, p, 29);
        prezime[29] = 0;

        strncpy(indeks, ind, 9);
        indeks[9] = 0;

        brPred = br >= 0 ? br : 0;
        procent = proc >= 0.0 ? proc : 0.0;
    }

    void pechati(){
        cout<<ime<<" "<<prezime<<" "<<indeks[0]<<"/"<<indeks[1]<<" "<<brPred<<" broj na polozheni predmeti "<<procent<<" procent na sovladanost"<<endl;
    }

    float presmetaj(int brPred){
            float procentPolozheni = (float)brPred / 40 * 100; 
            return procentPolozheni;
    }
};

class fakultet{

    private:
    
    char ime[30];
    int N;
    student lista[100];

    public:

    fakultet(char *i = "", int n = 0, student *l = NULL){

        strncpy(ime, i, 29);
        ime[29] = 0;

        N = n >=0 ? n : 0;

        for(int i = 0; i < n; i++){
            lista[i] = l[i];
        }
    }

    void pechati() {
        cout<<"Ime na fakultetot: "<<ime<<endl;
        cout<<"Broj na studenti: "<<N<<endl;
        cout<<"Podatoci za studentite: "<<endl;
        for (int i = 0; i < N; i++) {
            lista[i].pechati();
        }
    }

};

int main() {
    
    char ime[30];
    char prezime[30];
    char indeks[10];
    int brPred;
    float procent;
    student studenti[5];

    cout << "Vnesete podatoci za 5 studenti: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Student #" << i + 1 << ":" << endl;
        cout << "Ime: ";
        cin >> ime;
        cout << "Prezime: ";
        cin >> prezime;
        cout << "Indeks: ";
        cin >> indeks;
        cout << "Broj na polozheni predmeti: ";
        cin >> brPred;

        
        studenti[i] = student(ime, prezime, indeks, brPred, 0.0);
    }


char imeFakultet[30];
cout << "Ime na fakultetot: ";
cin >> imeFakultet;


fakultet fakultetObjekt(imeFakultet, 5, studenti);


cout << endl;
fakultetObjekt.pechati();


for (int i = 0; i < 5; i++) {
    float procentPolozheni = studenti[i].presmetaj(brPred);
    cout << "Student #" << i + 1 << ": Procent na polozheni predmeti: " << procentPolozheni << "%" << endl;
}

return 0;
}