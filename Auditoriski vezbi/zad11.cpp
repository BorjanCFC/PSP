#include<iostream>
#include<string.h>
using namespace std;

class sportist {

    private:

    string ime;
    string *tituli;
    int N;

    public:

    sportist(string i = "", string *t = NULL, int n = 0){
        N = n >= 0 ? n : 0;
        ime = i;

        tituli = new string[N];
        for(int i = 0; i < N; i++){
            tituli[i] = t[i];
        }

    }

    sportist(const sportist &s){
        N = s.N;
        ime = s.ime;

        tituli = new string[N];
        for(int i = 0; i < N; i++){
            tituli[i] = s.tituli[i];
        }
    }
    
    sportist &operator=(const sportist &s){

        if(this == &s){
            return *this;
        }

        delete [] tituli;

        N = s.N;
        ime = s.ime;

        tituli = new string[N];
        for(int i = 0; i < N; i++){
            tituli[i] = s.tituli[i];
        }

        return *this;
    }

    ~sportist(){
        delete [] tituli;
    }

    virtual float potencijal(){
        return N / 2.0;
    }

    virtual void pechati(){
        cout<<"Ime: "<<ime<<endl;
        cout<<"Broj na tituli: "<<N<<endl;
        for(int i = 0; i < N; i++){
            cout<<tituli[i]<<endl;
        }
    }

    sportist &operator+=(string t){
        string *pom = new string[N+1];

        for(int i = 1; i <= N; i++){
            pom[i] = tituli[i-1];
        }

        pom[0] = t;

        N++;

        delete [] tituli;

        tituli = new string[N];
        for(int i = 1; i <= N; i++){
            tituli[i] = pom[i];
        }

        delete [] pom;

        return *this;
    }

};

class teniser : public sportist {

    private:

    int atp;

    public:

    teniser(string i = "", string *t = NULL, int n = 0, int a = 0) : sportist(i, t, n) {
        atp = a >= 0 ? a : 0;
    }

    float potencijal(){
        float p = sportist::potencijal();
        if(atp >= 1 && atp <= 60){
            p += (60 - atp + 1);
        }
        return p;
    }

    void pechati(){
        sportist::pechati();
        cout<<"ATP: "<<atp<<endl;
    }

};

class fudbaler : public sportist {

    private:

    string poz;
    bool rep;

    public:

    fudbaler(string i = "", string *t = NULL, int n = 0, string p = "Napad", bool r = false) : sportist(i, t, n) {

        if(p == "Napad" || p == "Odbrana" || p == "Sreden red"){
            poz = p;
        }else{
            poz = "Napad";
        }

        rep = r;
    }

    float potencijal(){
        float p = sportist::potencijal();

        if(poz == "Napad"){
            p += 15;
        }else if(poz == "Sreden red"){
            p += 5;
        }

        if(rep){
            p *= 2;
        }
        return p;
    }

    void pechati(){
        sportist::pechati();
        cout<<"Pozicija: "<<poz<<endl;
        if(rep){
            cout<<"Igra za reprezentacija."<<endl;
        }else{
            cout<<"Ne igra za reprezentacija. "<<endl;
        }
    }

};

void povekjePotencijal(sportist *p1, sportist *p2){
    if(p1->potencijal() > p2->potencijal()){
        p1->pechati();
    }else{
        p2->pechati();
    }
}

// int main(){

//     string ime;
//     int atp;
//     int N;

//     string poz;
//     bool rep;

//     cout<<"Vnesi ime na teniser i ATP"<<endl;
//     cin>>ime>>atp;

//     teniser t(ime, NULL, 0, atp);

//     cout<<"Vnesi broj na tituli: "<<endl;
//     cin>>N;

//     cout<<"Vnesi gi titulite"<<endl;
//     for(int i = 0; i < N; i++){
//         string titula;
//         cin>>titula;
//         t += titula;
//     }

//     cout<<"Vnesi ime na fudbaler, pozicija, dali igra za reprezentacija: "<<endl;
//     cin>>ime>>poz>>rep;

//     fudbaler f(ime, NULL, 0, poz, rep);

//     cout<<"Vnesi broj na tituli: "<<endl;
//     cin>>N;

//     cout<<"Vnesi gi titulite"<<endl;
//     for(int i = 0; i < N; i++){
//         string titula;
//         cin>>titula;
//         f += titula;
//     }

//     povekjePotencijal(&t, &f);

//     return 0;
    
// }

int main() {
    string tituli1[] = {"Titula 1", "Titula 2", "Titula 3"};
    string tituli2[] = {"Titula 4", "Titula 5"};
    
    sportist s1("Sportist 1", tituli1, 3);
    teniser t1("Teniser 1", tituli2, 2, 30);
    fudbaler f1("Fudbaler 1", NULL, 0, "Napad", true);
    
    s1.pechati();
    cout << "Potencijal: " << s1.potencijal() << endl;
    cout << "--------------------------" << endl;
    
    t1.pechati();
    cout << "Potencijal: " << t1.potencijal() << endl;
    cout << "--------------------------" << endl;
    
    f1.pechati();
    cout << "Potencijal: " << f1.potencijal() << endl;
    cout << "--------------------------" << endl;
    
    
    povekjePotencijal(&t1, &f1);
    
    return 0;
}
