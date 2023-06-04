#include <iostream>
#include <cstring>
using namespace std;

class kniga {

    protected:

    char ISBN[20];
    char naslov[50];
    char avtor[30];
    float cena;

    public:

    kniga(const char* isbn = "", const char* n = "", const char* a = "", float c = 0.0) {
        strncpy(ISBN, isbn, 19);
        ISBN[19] = '\0';

        strncpy(naslov, n, 49);
        naslov[49] = '\0';

        strncpy(avtor, a, 29);
        avtor[29] = '\0';

        cena = c >= 0.0 ? c : 0.0;
    }

    virtual void pechati(ostream &o) const {
        o<<"ISBN: "<<ISBN<<endl;
        o<<"Naslov: "<<naslov<<endl;
        o<<"Avtor: "<<avtor<<endl;
        o<<"Cena: "<<cena<<endl;
    }

    friend ostream& operator<<(ostream &o, const kniga &k) {
        k.pechati(o);
        return o;
    }

    friend bool operator>(kniga& k1, kniga& k2) {
        return k1.presmetajCena() > k2.presmetajCena();
    }

    virtual float presmetajCena() = 0;
};

class online : public kniga {
    
    private:

    char* lista;
    int golemina;

    
    public:

    online(const char* isbn = "", const char* n = "", const char* a = "", float c = 0.0, const char* l = "", int g = 0)
        : kniga(isbn, n, a, c) {
        lista = new char[strlen(l) + 1];
        strcpy(lista, l);

        golemina = g >= 0 ? g : 0;
    }

    float presmetajCena() override {
        if (golemina > 20) {
            float zgolemuvanje = cena * 0.2;
            cena += zgolemuvanje;
        }
        return cena;
    }

    void pechati(ostream& o) const override {
        kniga::pechati(o);
        o<<"URL: "<<lista<<endl;
        o<<"Golemina vo MB: "<<golemina<<endl;
    }

    ~online() {
        delete[] lista;
    }
};

class pechatena : public kniga {

    private:

    float masa;
    bool dali;

    public:

    pechatena(const char* isbn = "", const char* n = "", const char* a = "", float c = 0.0, float m = 0.0, bool d = false)
        : kniga(isbn, n, a, c) {
        masa = m >= 0.0 ? m : 0.0;
        dali = d;
    }

    float presmetajCena() override {
        if (masa > 0.7) {
            float zgolemuvanje = cena * 0.15;
            cena += zgolemuvanje;
        }
        return cena;
    }

    void pechati(ostream& o) const override {
        kniga::pechati(o);
        o<<"Masa: "<<masa<<endl;
        if(dali){
            o<<"Da, ja ima na zaliha!"<<endl;
        }
        else{
            o<<"Ne, ja nema na zaliha!"<<endl;
        }
    }

};

void najskapaKniga(kniga** lista, int N) {
    kniga *max = lista[0];
    for (int i = 1; i < N; i++) {
        if (lista[i]->presmetajCena() > max->presmetajCena()) {
            max = lista[i];
        }
    }

    cout << *max << endl;
}

int main() {
    kniga* knigi[4];

    knigi[0] = new online("123456789", "Book1", "Author1", 10.99, "www.book1.com", 30);
    knigi[1] = new online("987654321", "Book2", "Author2", 15.99, "www.book2.com", 15);

    knigi[2] = new pechatena("111222333", "Book3", "Author3", 19.99, 0.5, true);
    knigi[3] = new pechatena("444555666", "Book4", "Author4", 24.99, 1.2, false);

    najskapaKniga(knigi, 4);


    return 0;
}
