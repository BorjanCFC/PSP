#include<iostream>
#include<string.h>
using namespace std;

class biblioteka {

    private:

    string *lista;
    int N;

    public:

    biblioteka(string *l = NULL, int n = 0){
        if(l == NULL && n == 0){
            N = 1;
            lista = new string[N];
            lista[0] = "Snezhana i sedumte dzudzinja";
        }else{

        N = n >= 0 ? n : 0;
        lista = new string[N];
        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }

        }

    }

    biblioteka(const biblioteka &b){
        N = b.N;

        lista = new string[N];
        for(int i = 0; i < N; i++){
            lista[i] = b.lista[i];
        }
    }

    biblioteka &operator=(const biblioteka &b){
        if(this == &b){
            return *this;
        }

        delete [] lista;

        N = b.N;

        lista = new string[N];
        for(int i = 0; i < N; i++){
            lista[i] = b.lista[i];
        }

        return *this;
    }

    ~biblioteka(){
        delete [] lista;
    }

    friend bool operator<(biblioteka &b1, biblioteka &b2){
        return b1.N < b2.N; 
    }

    friend ostream &operator<<(ostream &o, const biblioteka &b){
        o<<"Broj na knigi vo bibliotekata: "<<b.N<<endl;
        o<<"Naslovite na knigite vo bibliotekata: "<<endl;
        for(int i = 0; i < b.N; i++){
            o<<"Kniga "<<i+1<<": "<<b.lista[i]<<endl;
        }
        return o;
    }

    biblioteka &operator++(){
        string *pom = new string[N+1];

        string naslov;
        cout<<"Vnesi naslov na kniga: (eden zbor) "<<endl;
        cin>>naslov;

        pom[0] = naslov;

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

        return *this;
    }

    biblioteka &operator-=(string naslov){
        int found = -1;

        for(int i = 0; i < N; i++){
            if(lista[i] == naslov){
                found = i;
                break;
            }
        }

        if(found != -1){
            string *pom = new string[N-1];
            int j = 0;
            for(int i = 0; i < N; i++){
                if(i != found){
                    pom[j] = lista[i];
                    j++;
                }
            }

            delete [] lista;

            N--;

            lista = new string[N];
            for(int i = 0; i < N; i++){
                lista[i] = pom[i];
            }

            delete [] pom;

            return *this;
        }

        return *this;
    }

};


int main() {
    
    biblioteka library;

    
    cout << library;

    cout<<endl;

    
    ++library;

    cout<<endl;

    
    cout << library;

    cout<<endl;

    biblioteka library2;

    library2 = library;

    cout<<library2<<endl;

    
    library -= "Snezhana i sedumte dzudzinja";

    cout<<endl;
    
    cout << library<<endl;

    if(library < library2){
        cout<<"Vtorata biblioteka ima povekje knigi";
    }else{
        cout<<"Prvata biblioteka ima povekje knigi";
    }

    return 0;
}
