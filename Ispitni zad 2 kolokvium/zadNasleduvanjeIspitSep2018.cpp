#include<iostream>
#include<string.h>
using namespace std;

class inventar {

    private:

    char tip; 
    string ID;

    public:

    inventar(char t = 'M', string id = ""){

        if(t == 'M' || t == 'S'){
            tip = t;
        }else{
            tip = 'M';
        }

        ID = id;
    }

    string getID(){
        return ID;
    }

    char getTip(){
        return tip;
    }

};

class kancelarija {

    protected:
    
    int br;
    int N;
    inventar *lista;

    public:

    kancelarija(int b = 0, int n = 0, inventar *l = NULL){
        br = b >= 0 ? b : 0;
        N = n >= 0 ? n : 0;

        lista =  new inventar[N];
        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }

    }

    kancelarija(const kancelarija &k){
        br - k.br;
        N = k.N;

        lista = new inventar[N];
        for(int i = 0; i < N; i++){
            lista[i] = k.lista[i];
        }
    }

    ~kancelarija(){
        delete [] lista;
    }

    kancelarija &operator=(const kancelarija &k){
        if(this == &k){
            return *this;
        }

        delete [] lista;

        br - k.br;
        N = k.N;

        lista = new inventar[N];
        for(int i = 0; i < N; i++){
            lista[i] = k.lista[i];
        }

        return *this;
    }

    kancelarija &operator+=(inventar &e){

        inventar *pom = new inventar[N+1];
        pom[0] = e;

        for(int i = 0; i < N; i++){
            pom[i+1] = lista[i];
        }

        delete [] lista;

        N++;

        lista = new inventar[N];
        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;

        return *this;
    }

    friend ostream &operator<<(ostream &o, const kancelarija &k){
        o<<"Reden broj: "<<k.br<<endl;
        o<<"Broj na inventarni elementi: "<<k.N<<endl;
        for(int i = 0; i < k.N; i++){
            o<<k.lista[i].getID()<<" "<<k.lista[i].getTip()<<endl;
        }
        return o;
    }

    virtual float vrednost() {
        float cena = 0.0;
        for(int i = 0; i < N; i++){
            if(lista[i].getTip() == 'M'){
                cena += 5000.0;
            }else if(lista[i].getTip() == 'S'){
                cena += 4000.0;
            }
        }

        return cena;
    }

    virtual void pechatiRedenBroj(){
        cout<<"Reden broj: "<<br<<endl;
    }

};

class asistentska : public kancelarija {

    private:

    int brTetratki;

    public:

    asistentska(int b = 0, int n = 0, inventar *l = NULL, int brT = 0) : kancelarija(b, n, l) {
        brTetratki = brT >= 0 ? brT : 0;
    }

    asistentska &operator=(const asistentska &a) {
        if(this == &a){
            return *this;
        }

        kancelarija::operator=(a);

        brTetratki = a.brTetratki;

        return *this;
    }

    asistentska &operator+=(inventar &a){
        kancelarija::operator+=(a);

        return *this;
    }

    friend ostream &operator<<(ostream &o, const asistentska &k) {
        o<<"Broj na ispitni tetratki: "<<k.brTetratki<<endl;
        o<<"Reden broj: "<<k.br<<endl;
        o<<"Broj na inventarni elementi: "<<k.N<<endl;
        for(int i = 0; i < k.N; i++){
            o<<k.lista[i].getID()<<" "<<k.lista[i].getTip()<<endl;
        }
        return o;
        
    }

    float vrednost(){
        float cena = 0.0;
        cena = kancelarija::vrednost();

        float cenaTetratki = brTetratki * 20;

        cena += cenaTetratki;

        return cena;
    }

    void pechatiRedenBroj(){
        kancelarija::pechatiRedenBroj();
    }

};

class profesorska : public kancelarija {

    private:

    bool proektor;
    int brP;

    public:

    profesorska(int b = 0, int n = 0, inventar *l = NULL, bool p = false, int brp = 0) : kancelarija(b, n, l) {
        proektor = p;
        brP = brp >= 0 && brp <= 1 ? brp : 0;
    }

    profesorska &operator=(const profesorska &p){
        if(this == &p){
            return  *this;
        }

        kancelarija::operator=(p);

        proektor = p.proektor;
        brP = p.brP;

        return *this;
    }

    profesorska &operator+=(inventar &a){
        kancelarija::operator+=(a);

        return *this;
    }

    friend ostream &operator<<(ostream &o, const profesorska &k) {

        if(k.proektor){
            o<<"Ima proektor"<<endl;
        }else{
            o<<"Nema proektor"<<endl;
        }

        o<<"Reden broj: "<<k.br<<endl;
        o<<"Broj na inventarni elementi: "<<k.N<<endl;
        for(int i = 0; i < k.N; i++){
            o<<k.lista[i].getID()<<" "<<k.lista[i].getTip()<<endl;
        }
        return o;
        
    }

    float vrednost() {
        float cena = 0.0;
        cena = kancelarija::vrednost();

        if(proektor){
            cena += 18000.0;
        }

        return cena;
    }

    void pechatiRedenBroj(){
        kancelarija::pechatiRedenBroj();
    }

};

void najneopremena(kancelarija **lista, int N){
    kancelarija *min = lista[0];

    for(int i = 1; i < N; i++){
        if(lista[i]->vrednost() < min->vrednost()){
            min = lista[i];
        }
    }

    min->pechatiRedenBroj();
}

int main() {
    
    inventar i1('M', "ID1");
    inventar i2('S', "ID2");

    
    inventar lista[] = {i1, i2};
    kancelarija k1(1, 2, lista);

    
    inventar i3('M', "ID3");
    k1 += i3;

    asistentska a1(2, 1, lista, 5);

    
    inventar i4('S', "ID4");
    a1 += i4;

    profesorska p1(3, 1, lista, true, 1);

    cout<<"Kancelarija:\n"<<k1<<endl;
    cout<<"Asistentska:\n"<<a1<<endl;
    cout<<"Profesorska:\n"<<p1<<endl;

    
    cout<<"Kancelarija vrednost: "<<k1.vrednost()<<endl;
    cout<<"Asistentska vrednost: "<<a1.vrednost()<<endl;
    cout<<"Profesorska vrednost: "<<p1.vrednost()<<endl;
    cout<<endl;

    kancelarija* kancelarije[] = {&k1, &a1, &p1};

    
    najneopremena(kancelarije, 3);

    return 0;
}
