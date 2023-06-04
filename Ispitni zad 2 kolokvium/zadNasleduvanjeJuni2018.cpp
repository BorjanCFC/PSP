#include<iostream>
#include<string.h>
using namespace std;

class vagon {

    private:

    int tezhina;
    string ID;

    public:

    vagon(int t = 0, string id = ""){
        tezhina = t >= 0 ? t : 0;
        ID = id;
    }

    string getID(){
        return ID;
    }

    int getTezhina(){
        return tezhina;
    }
};

class voz {

    protected:

    int seriskiBr;
    int N;
    vagon *lista;

    public:

    voz(int sbr = 0, int brv = 0, vagon *l = NULL){
        seriskiBr = sbr >= 0 ? sbr : 0;
        N = brv >= 0 ? brv : 0;

        lista = new vagon[N];
        for(int i = 0; i < N; i++){
            lista[i] = l[i];
        }
    }

    voz(const voz &v){
        seriskiBr = v.seriskiBr;
        N = v.N;

        lista = new vagon[N];
        for(int i = 0; i < N; i++){
            lista[i] = v.lista[i];
        }

    }

    voz &operator=(const voz &v){
        if(this == &v){
            return *this;
        }

        delete [] lista;

        seriskiBr = v.seriskiBr;
        N = v.N;

        lista = new vagon[N];
        for(int i = 0; i < N; i++){
            lista[i] = v.lista[i];
        }

        return *this;

    }

    ~voz(){
        delete [] lista;
    }

    voz &operator--(){
        vagon *pom = new vagon[N-1];

        for(int i = 0; i < N-1; i++){
            pom[i] = lista[i];
        }

        delete [] lista;

        N--;

        lista = new vagon[N];
        for(int i = 0; i < N; i++){
            lista[i] = pom[i];
        }

        delete [] pom;

        return *this;
    }

    friend ostream &operator<<(ostream &o, const voz &v){
        o<<"Seriski broj: "<<v.seriskiBr<<endl;
        o<<"Broj na vagoni: "<<v.N<<endl;
        o<<"Vagoni: "<<endl;
        for(int i = 0; i < v.N; i++){
            o<<"ID: "<<v.lista[i].getID()<<endl;
            o<<"Tezhina: "<<v.lista[i].getTezhina()<<endl;
        }
        return o;
    }
    
    virtual float presmetajCena(){
        return 0;
    }


};

class dizel : public voz {

    private:

    float potroshuvacka;
    float cena;
    int taksa;

    public:

    dizel(int sbr = 0, int brv = 0, vagon *l = NULL, float p = 0.0, float c = 0.0, int t = 0) : voz(sbr, brv, l) {
        potroshuvacka = p >= 0.0 ? p : 0.0;
        cena = c >= 0.0 ? c : 0.0;
        taksa = t >= 0 ? t : 0;
    }

    dizel &operator=(const dizel &d){
        if(this == &d){
            return *this;
        }

        voz::operator=(d);

        potroshuvacka = d.potroshuvacka;
        cena = d.cena;
        taksa = d.taksa;

        return *this;
    }

    dizel &operator--(){
        voz::operator--();

        return *this;
    }

    friend ostream &operator<<(ostream &o, const dizel &d){
        o<<"Osnovna potroshuvacka: "<<d.potroshuvacka<<endl;
        o<<"Prosecna cena: "<<d.cena<<endl;
        o<<"Visina na eko taksa: "<<d.taksa<<endl;
        o<<"Seriski broj: "<<d.seriskiBr<<endl;
        o<<"Broj na vagoni: "<<d.N<<endl;
        o<<"Vagoni: "<<endl;
        for(int i = 0; i < d.N; i++){
            o<<"ID: "<<d.lista[i].getID()<<endl;
            o<<"Tezhina: "<<d.lista[i].getTezhina()<<endl;
        }
        return o;
    }

    float presmetajCena() {
        float vkupno = 0.0;

        for(int i = 0; i < N; i++){
            float tezhina = (lista[i].getTezhina()) * 0.05; 
            vkupno += potroshuvacka + tezhina;
        }

        float vrednost = (vkupno * cena) + taksa;

        return vrednost;
        
    }


};

class elektricni : public voz {

    private:

    float potroshuvacka;
    float cena;

    public:

    elektricni(int sbr = 0, int brv = 0, vagon *l = NULL, float p = 0.0, float c = 0.0) : voz(sbr, brv, l) {
        potroshuvacka = p >= 0.0 ? p : 0.0;
        cena = c >= 0.0 ? c : 0.0;
    }

    elektricni &operator=(const elektricni &e){
        if(this == &e){
            return *this;
        }

        voz::operator=(e);

        potroshuvacka = e.potroshuvacka;
        cena = e.cena;

        return *this;
    }

    elektricni &operator--(){
        voz::operator--();

        return *this;
    }

    friend ostream &operator<<(ostream &o, const elektricni &d){
        o<<"Osnovna potroshuvacka: "<<d.potroshuvacka<<endl;
        o<<"Prosecna cena: "<<d.cena<<endl;
        o<<"Seriski broj: "<<d.seriskiBr<<endl;
        o<<"Broj na vagoni: "<<d.N<<endl;
        o<<"Vagoni: "<<endl;
        for(int i = 0; i < d.N; i++){
            o<<"ID: "<<d.lista[i].getID()<<endl;
            o<<"Tezhina: "<<d.lista[i].getTezhina()<<endl;
        }
        return o;
    }

    float presmetajCena() {
        float vkupno = 0.0;

        for(int i = 0; i < N; i++){
            float tezhina = (lista[i].getTezhina()) * 0.1; 
            vkupno += potroshuvacka + tezhina;
        }

        float vrednost = vkupno * cena;

        return vrednost;
        
    }


};

int najekonomichen(voz **lista, int N){
    voz *min = lista[0];
    int rbr = 0;

    for(int i = 0; i < N; i++){
        if(lista[i]->presmetajCena() < min->presmetajCena()){
            min = lista[i];
            rbr = i;
        }
    }

    return rbr;
}

int main()
{
    vagon v1[2] = {vagon(1, "1"), vagon(2, "10")};
    dizel D1(1, 2, v1, 20, 61, 15000);
    vagon v2[3] = {vagon(5, "12"), vagon(6, "5"), vagon(8, "30")};
    elektricni E1(2, 3, v2, 200, 10);
    vagon v3[4] = {vagon(9, "2"), vagon(10, "1"), vagon(12, "5"), vagon(13, "15")};
    elektricni E2(3, 4, v3, 300, 10);
    vagon v4[3] = {vagon(16, "12"), vagon(17, "10"), vagon(20, "7")};
    dizel D2(4, 3, v4, 15, 61, 10000);
    voz *V[] = {&D1, &E1, &D2, &E2};

    int ind = najekonomichen(V, 4);
    cout << "Najeftin za transport e vozot so reden broj: " << ind << endl;

    cout << *V[ind] << endl;

    --(*V[1]);

    ind = najekonomichen(V, 4);
    cout << "Najeftin za transport e vozot so reden broj: " << ind << endl;

    cout << *V[ind] << endl;

    return 0;
}



