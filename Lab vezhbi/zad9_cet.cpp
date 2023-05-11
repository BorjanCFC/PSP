#include<iostream>
#include<string.h>
using namespace std;

struct tipuvanje{

    string domakjin;
    string gostin;
    int tip;
    float koeficient;

};

class livche{

    private:

    tipuvanje *lista;
    int N;

    public:

    livche(tipuvanje *l = NULL, int n = 0){
        
        N = n > 0 ? n : 0;

        lista = new tipuvanje[N];
        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }

    }

    livche(const livche &l){
        N = l.N;

        lista = new tipuvanje[N];
        for(int i = 0; i < N; i++){
            lista[i] = l.lista[i];
        }

    }

    ~livche(){
        delete [] lista;
    }

    friend istream &operator>>(istream &is, livche &l){
        
        cout<<endl;
        cout<<"Vnesi broj na natprevari: ";
        is>>l.N;
        cout<<endl;

        delete [] l.lista;

        l.lista = new tipuvanje[l.N];
        for(int i = 0; i < l.N; i++){

            cout<<"Vnesi go imeto na domakjinot "<<i+1<<": ";
            is>>l.lista[i].domakjin;
            cout<<endl;

            cout<<"Vnesi go imeto na gostinot "<<i+1<<": ";
            is>>l.lista[i].gostin;
            cout<<endl;

            cout<<"Vnesi go tipot (1 , 0, 2): ";
            is>>l.lista[i].tip;

            if(l.lista[i].tip != 0 && l.lista[i].tip != 1 && l.lista[i].tip != 2){
                cout<<"Nevaliden tip!"<<endl;
                exit(-1);
            }

            cout<<endl;
            cout<<"Vnesi koeficient za natprevarot: ";
            is>>l.lista[i].koeficient;

            cout<<endl;
        }

        return is;
    }

    friend ostream &operator<<(ostream &o, const livche &l){

        o<<"Pishavte "<<l.N<<" natprevari."<<endl;
        o<<"Natprevarite se vo prilog: "<<endl;

        for(int i = 0; i < l.N; i++){
            o<<l.lista[i].domakjin<<" - "<<l.lista[i].gostin<<"     Tip - "<<l.lista[i].tip<<"  Koeficient - "<<l.lista[i].koeficient<<endl;
        }

        return o;

    }

    friend bool operator>(const livche &l1, const livche &l2){

        float koef1 = 1.0;
        float koef2 = 1.0;

        for(int i = 0; i < l1.N; i++){
            koef1 *= l1.lista[i].koeficient;
        }

        for(int i = 0; i < l2.N; i++){
            koef2 *= l2.lista[i].koeficient;
        }

        if(koef1 > koef2){
            return true;
        }else{
            return false;
        }
    }

    livche &operator+=(tipuvanje &l){

        tipuvanje *pom = new tipuvanje[N+1];

        for(int i = 0; i < N; i++){

            pom[i].domakjin = lista[i].domakjin;
            pom[i].gostin = lista[i].gostin;
            pom[i].koeficient = lista[i].koeficient;
            pom[i].tip = lista[i].tip;

        }

        delete [] lista;

        pom[N].domakjin = l.domakjin;
        pom[N].gostin = l.gostin;
        pom[N].koeficient = l.koeficient;
        pom[N].tip = l.tip;

        N++;

        lista = new tipuvanje[N];
        for(int i = 0; i < N; i++){

            lista[i].domakjin = pom[i].domakjin;
            lista[i].gostin = pom[i].gostin;
            lista[i].koeficient = pom[i].koeficient;
            lista[i].tip = pom[i].tip;

        }

        delete [] pom;

        return *this;
        
    }

    livche &operator--(){

        tipuvanje *pom = new tipuvanje[N-1];

        for(int i = 0; i < N - 1; i++){

            pom[i].domakjin = lista[i].domakjin;
            pom[i].gostin = lista[i].gostin;
            pom[i].koeficient = lista[i].koeficient;
            pom[i].tip = lista[i].tip;

        }

        delete [] lista;

        N--;

        lista = new tipuvanje[N];
        for(int i = 0; i < N; i++){

            lista[i].domakjin = pom[i].domakjin;
            lista[i].gostin = pom[i].gostin;
            lista[i].koeficient = pom[i].koeficient;
            lista[i].tip = pom[i].tip;
            
        }

        delete [] pom;

        return *this;
    }

};

int main() {

    livche l1; 
    cout<<"Vnesi podatoci za livceto 1"<<endl;
    cin>>l1;

    livche l2; 
    cout<<"Vnesi podatoci za livceto 2"<<endl;
    cin>>l2;

    cout<<l1<<endl;
    cout<<l2<<endl; 

    if(l1 > l2){
        cout<<"Livceto 1 ima pogolem vkupen koeficient."<<endl;
    }else{
        cout<<"Livceto 2 ime pogolem vkupen koeficient."<<endl;
    }

    cout<<endl;

    
    --l1;
    cout<<l1<<endl;

    cout<<endl;

    tipuvanje t;
    cout<<"Vnesete podatoci za natprevarot sto sakate da go dodadete."<<endl;

    cout<<"Vnesete go imeto na domakjinot: ";
    cin>>t.domakjin;
    cout<<endl;

    cout<<"Vnesete go imeto na gostinot: ";
    cin>>t.gostin;
    cout<<endl;

    cout<<"Vnesi go tipot (1 , 0, 2): ";
    cin>>t.tip;

    if(t.tip != 0 && t.tip != 1 && t.tip != 2){
        cout<<"Nevaliden tip!"<<endl;
        exit(-1);
    }

    cout<<endl;

    cout<<"Vnesi koeficient za natprevarot: ";
    cin>>t.koeficient;
    cout<<endl;

    l1 += t;
    
    cout<<l1<<endl;


    return 0;

}

