#include<iostream>
#include<string.h>
using namespace std;

class student{

    private:
    
    int ID;
    char kurs[50];
    float suma;

    public:

    student(int id = 0, char *imeKurs = "", float s = 0.0){

        strncpy(kurs, imeKurs, 49);
        kurs[49] = 0;

        ID = id >= 0 ? id : 0;

        suma = s >= 0.0 ? s : 0.0;
    }

    void pechati(){
        cout<<ID<<" "<<kurs<<" "<<" ima plateno "<<suma<<endl;
    }

    int getID(){
        return ID;
    }

    float getSuma(){
        return suma;    
    }

    char *getKurs(){
        return kurs;
    }

};  

class course{

    private:
    
    int N;
    student lista[20];
    float participacija;

    public:

    course(int n = 0, student *s = NULL, float p = 0.0){

        N = n>=0 ? n : 0;

        for(int i = 0; i<n; i++){
            lista[i] = s[i];
        }

        if(p>=0.0 && p<500.0){
            participacija = p;
        }else{
            participacija = 0.0;
        }
    }

    void pechati(){

        cout<<"Broj na studenti: "<<N<<endl;
        cout<<"Studenti: "<<endl;

        for(int i = 0; i<N; i++){
            lista[i].pechati();
        }
    }

    float presmetka(int id){

    float uplatena = 0.0;
    float doplata = 0.0;
    for(int i = 0; i < N; i++){
        if(lista[i].getID() == id){
            uplatena = lista[i].getSuma();
            break;
        }
    }

    float osnovna = participacija - (participacija * (N / 100.0));

    doplata = osnovna - uplatena;

    return doplata > 0.0 ? doplata : 0.0;
    }

};

