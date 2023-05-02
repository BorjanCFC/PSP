#include<iostream>
#include<string.h>
using namespace std;

class fakultet{

    private:
    
    char *ime;
    int brPred;
    int *krediti;

    public:

    fakultet(char *i = "" , int br = 0 , int *kred = NULL){

        ime = new char[strlen(i) + 1];
        strcpy(ime, i);

        brPred = br >= 0 ? br : 0;

        krediti = new int[br];
        for(int i = 0; i < br; i++){
            krediti[i] = kred[i];
        }

    }

    fakultet(const fakultet &f){

        ime = new char[strlen(f.ime) + 1];
        strcpy(ime, f.ime);

        brPred = f.brPred;

        krediti = new int[f.brPred];
        for(int i = 0; i < f.brPred; i++){
            krediti[i] = f.krediti[i];
        }

    }

    int brojStandardniPredmeti(){
        int counter = 0;

        for(int i = 0; i < brPred; i++){
            if(krediti[i] == 6){
                counter++;
            }
        }
        return counter;
    }

    void pechati(){
        int r = brojStandardniPredmeti();
        cout<<ime<<" "<<brPred<<" predmeti i "<<r<<" predmeti nosat 6 krediti."<<endl;
    }

    ~fakultet(){
        delete [] ime;
        delete [] krediti;
    }

};

class univerzitet{

    private:

    char *ime;
    int N;
    fakultet *lista;

    public:

    univerzitet(char *i = "", int n = 0, fakultet *l = NULL){

        ime = new char[strlen(i) + 1];
        strcpy(ime, i);

        N = n >= 0 ? n : 0;

        lista = new fakultet[n];
        for(int i = 0; i < n; i++){
            lista[i] = l[i];
        }

    }

    univerzitet(const univerzitet &u){
        ime = new char[strlen(u.ime) + 1];
        strcpy(ime, u.ime);

        N = u.N;

        lista = new fakultet[u.N];
        for(int i = 0; i < u.N; i++){
            lista[i] = u.lista[i];
        }
    }

    fakultet najmnoguSo6KreditiFakultet(){
        fakultet max = lista[0];
        for(int i = 1; i < N; i++){
            if(lista[i].brojStandardniPredmeti() > max.brojStandardniPredmeti()){
                max = lista[i];
            }
        }
        return max;
    }

    ~univerzitet(){
        delete [] ime;
        delete [] lista;
    }

};

int main(){

    int k1[3] = {6, 6, 7};
    fakultet f1("FINKI", 3, k1);

    int k2[4] = {6, 6, 6, 7};
    fakultet f2("FEIT", 4, k2);

    fakultet fakulteti[2] = {f1, f2};
    univerzitet u("UKIM", 2, fakulteti);

    fakultet maxF = u.najmnoguSo6KreditiFakultet();
    maxF.pechati();

    return 0;
}