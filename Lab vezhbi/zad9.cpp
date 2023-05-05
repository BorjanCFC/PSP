#include<iostream>
#include<string.h>
using namespace std;

class rechenica{

    private:

    string *lista;
    int N;

    public:

    rechenica(string *l = NULL, int d = 0){

        N = d >= 0 ? d : 0;

        if(l == NULL){

            lista = new string[1];

            lista[0] = "default";

            N = 1;
            

        }else{

        lista = new string[N];
        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }

        }
    }

    ~rechenica(){
        delete [] lista;
    }

    friend ostream &operator<<(ostream &o, const rechenica &r){
        for(int i = 0; i < r.N; i++){
            o<<r.lista[i]<<" ";
        }
        cout<<endl;
        return o;
    }

    rechenica &operator=(const rechenica &r){
        if(this == &r){
            return *this;
        }

        N = r.N;

        delete [] lista;

        lista = new string[r.N + 1];

        for(int i = 0; i < N; i++){
            lista[i] = r.lista[i];
        }

    }

    friend bool operator>(const rechenica &r1, const rechenica &r2){
        return r1.N > r2.N;
    }

    rechenica &operator-=(string zbor){

        string *pom = new string[N + 1];

        pom[0] = zbor;

        for(int i = 0; i < N; i++){
            pom[i+1] = lista[i];
        }

        delete [] lista;

        N++;

        lista = new string[N];

        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;

    }

    rechenica &operator++(int){

        rechenica pom(*this);

        delete [] lista;
        N--;

        lista = new string[N];

        for(int i = 0; i < N; i++){
            lista[i] = pom.lista[i];
        }

        return pom;

    }

    string &operator[](const int index){
        return lista[index];
    }

};

int main(){

    string zborovi[6] = {"sakam", "da", "polozam", "psp", "vo", "juni"};
    rechenica r1 = rechenica();
    rechenica r2 = rechenica(zborovi, 6);
    rechenica r3;

    r3 = r2;

    cout<<r1;
    cout<<r2;
    cout<<r3;

    r2 -= "Jas";
    cout<<r2;
    cout<<(r2 > r1);

    r1[0] = "Nov";

    cout<<endl;
    cout<<r1[0];
    
    cout<<endl;
    cout<<r2[0];

    return 0;
}