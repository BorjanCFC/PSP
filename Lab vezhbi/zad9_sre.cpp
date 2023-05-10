#include<iostream>
#include<string.h>
using namespace std;

class loto{

    private:

    int *lista;
    int N;

    public:

    loto(int *l = NULL, int d = 0){

        if(l == NULL){
            d = 1;
            lista = new int[1];
            lista[0] = 1;
        }else{
            N = d >= 0 ? d : 0;

            lista = new int[N];
            for(int i = 0; i < N; i++){
                lista[i] = l[i];
            }
        }

    }

    loto(const loto &l){
        N = l.N;
        lista = new int[l.N];
        for(int i = 0; i < N; i++){
                lista[i] = l.lista[i];
            }

    }

    ~loto(){
        delete [] lista;
    }

    friend istream &operator>>(istream &is, loto &l) {
    
    cout<<"Vnesi dolzina na listata: ";
    is>>l.N;

    delete[] l.lista;

    l.lista = new int[l.N];

    cout<<"Vnesi gi elementite od listata:"<<endl;
    for (int i = 0; i < l.N; i++) {
        is>>l.lista[i];
    }

    return is;
    }

    friend ostream &operator<<(ostream &o, const loto &l){
        o<<endl;
        o<<"Dolzhinata na listata e "<<l.N<<endl;
        o<<"Elementite od listata se: "<<endl;
        for(int i = 0; i < l.N; i++){
            o<<l.lista[i]<<"\t";
        }
        return o;
    }

    loto &operator=(const loto &l){

        if(this == &l){
            return *this;
        }

        N = l.N;

        delete [] lista;

        lista = new int[l.N];

        for(int i = 0; i < N; i++){
            lista[i] = l.lista[i];
        }
        return *this;
    }

    friend bool operator==(const loto &l1, const loto &l2){

    if(l1.N != l2.N){
        return false;
    }

    for(int i = 0; i < l1.N; i++) {
        if(l1.lista[i] != l2.lista[i]){
            return false;
        }
    }

    return true;
    }

    int &operator[](const int poz){
        if(poz > N){
            cout<<"Nevalidna pozicija!"<<endl;
            exit(-1);
        }
        return lista[poz];
    }

    loto &operator++(){

        int *pom = new int[N+1];

        for(int i = 0; i < N; i++){
            pom[i] = lista[i];
        }

        delete [] lista;

        int br;

        cout<<"Vnesi nov broj: ";
        cin>>br;

        pom[N] = br;

        N++;

        lista = new int[N];
        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

    }

};

int main() {

    loto l1; 
    cout<<"Vnesi podatoci za livceto 1"<<endl;
    cin>>l1;

    loto l2; 
    cout<<"Vnesi podatoci za livceto 2"<<endl;
    cin>>l2;

    cout<<"Livce 1: "<<l1<<endl;
    cout<<"Livce 2: "<<l2<<endl; 

    if(l1 == l2){
        cout<<"Livcinjata se isti."<<endl;
    }else{
        cout<<"Livcinjtata se razlichni."<<endl;
    }

    int index1;
    int index2;

    cout<<"Vnesi indeks na element od livceto 1: ";
    cin>>index1;

    cout<<"Elementot na pozicija "<<index1<<" vo livceto 1 e: "<<l1[index1]<<endl;

    cout<<"Vnesi indeks na element od livceto 2: ";
    cin>>index2;

    cout<<"Elementot na pozicija "<<index2<<" vo livceto 2 e: "<<l2[index2]<<endl;

    ++l1; 

    cout<<"Livce 1 po dodavanjeto na element: "<<l1<<endl;

    ++l2;

    cout<<"Livce 2 po dodavanje na element: "<<l2<<endl;

    return 0;
}
