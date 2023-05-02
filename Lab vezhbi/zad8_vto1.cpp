#include<iostream>
#include<string.h>
using namespace std;

class rechenica{

    private:

    string *lista;
    int N;

    public:

    rechenica(){
        N = 2;
        lista = new string[N];
        
        lista[0] = "Zdravo";
        lista[1] = "!";
    }

    rechenica(string *l, int d){
        N = d >= 0 ? d : 0;

        lista = new string[N];
        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }
    }

    rechenica(const rechenica &r){
        N = r.N;

        lista = new string[N];
        for(int i = 0; i < N; i++){
            lista[i] = r.lista[i];
        }
    }

    ~rechenica(){
        delete [] lista;
    }

    void pechati(){

        for(int i = 0; i < N; i++){
            cout<<lista[i]<<" ";
        }
        cout<<endl;

    }
    
    void dodadiElement(string m){
        string *pom = new string[N+1];

        for(int i = 0; i < N; i++){
            pom[i] = lista[i];
        } 

        pom[N] = m;

        delete [] lista;

        N++;
        lista = new string[N];

        for(int i = 0; i<N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;

    }

    void brishiElement(int poz){

    if(poz < 0 || poz >= N){ 
        cout<<"Greshka!"<<endl;
    }else{
        string *pom = new string[N-1];

        int k = 0;
        for(int i = 0; i < N; i++){
            if(i != poz){
                pom[k] = lista[i];
                k++;
            }
        }

        delete [] lista;

        N--;

        lista = new string[N];

        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;
    }
    }

};

int main(){

    string lista[] = {"Mnogu", "sakam", "da", "ucham", "PSP", "!"};
    int N = 6;

    rechenica r1(lista, N);
    r1.pechati();

    string lista2[] = {"za", "copy", "konstruktor."};
    int M = 3;

    rechenica r2(lista2, M);

    for(int i = 0; i < M; i++){
        r1.dodadiElement(lista2[i]);
    }

    r1.pechati();

    r1.brishiElement(5);

    r1.pechati();

    return 0;
}