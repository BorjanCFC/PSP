#include<iostream>
#include<string.h>
using namespace std;

class rechenica{

    private:

    char *lista;

    public:

    rechenica(){

        lista = new char[7];
        strcpy(lista, "Zdravo!");

    }

    rechenica(const rechenica &r){

        lista = new char[strlen(r.lista) + 1];
        strcpy(lista, r.lista);

    }

    rechenica(char *niza){
        lista = new char[strlen(niza) + 1];
        strcpy(lista, niza);
    }

    ~rechenica(){
        delete [] lista;
    }

    void pechati(){
        cout<<lista<<endl;
    }

    void dodadiZnaci(char *niza, bool lok){

        char *pom = new char[(strlen(lista) + strlen(niza)) + 1];

        if(lok == true){
            
            strcpy(pom, lista);
            strcat(pom, " ");
            strcat(pom, niza);

        }else{

            strcpy(pom, niza);
            strcat(pom, " ");
            strcat(pom, lista);

        }

        delete [] lista;

        lista = new char[strlen(pom) + 1];
        strcpy(lista, pom);
        

        delete [] pom;
    }


    void brishiZnak(int poz){
        char *pom = new char[strlen(lista) - 1];

        int k = 0;
        for(int i = 0; i < strlen(lista); i++){
            if(i != poz){
                pom[k] = lista[i];
                k++;
            }
        }

        delete [] lista;

        lista = new char[strlen(pom) + 1];
        strcpy(lista, pom);

        delete [] pom;
    }


};

int main(){

    char niza[] = "Mnogu sakam da ucham PSP!";
    rechenica recenica(niza);
    recenica.pechati(); 

    char dodadeniZnaci[] = "za copy konstruktor.";
    recenica.dodadiZnaci(dodadeniZnaci, true);
    recenica.pechati(); 

    recenica.brishiZnak(24);
    recenica.pechati(); 
    
    return 0;
}