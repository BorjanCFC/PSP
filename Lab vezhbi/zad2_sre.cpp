#include<iostream>
using namespace std;

enum disciplina {skiSkokac,skijac,biatlonec};

struct reprezentativec{
    string ime;
    disciplina dis;
    int medali;

    void init(string i, disciplina d, int med){
        ime=i;
        dis=d;
        medali=med;
    }

    void pechati(){
    cout<<ime<<" ";
    switch(dis){
        case skiSkokac:
            cout<<"Skiskokac";
            break;
        case skijac:
            cout<<"Skijac";
            break;
        case biatlonec:
            cout<<"biatlonec";
            break;
    }
    cout<<" i ima  "<<medali<<" medali "<<endl;
    cout<<endl;
}
};

struct reprezentacija{
    string ime;
    int brReprezetativci;
     reprezentativec reprezentativci [10];
    
    void init(string i, int brR, reprezentativec rep[]){
        ime=i;
        brReprezetativci=brR;

        for(int i=0; i<brReprezetativci;i++){
            reprezentativci[i]=rep[i];
        }
    }

    void pechati(string ime){
        int i;
        for(i=0;i<brReprezetativci;i++){
            if (reprezentativci[i].ime==ime) {
                reprezentativci[i].pechati();
                
            }
        }
        cout<<"Nema takov reprezentativec!"<<endl;
    }

    void pechati(disciplina dis){
        int i;
        for(i=0;i<brReprezetativci;i++){
            if(reprezentativci[i].dis==dis){
                reprezentativci[i].pechati();
            }
        }
    }

    void najTrofeen(reprezentacija rep) {
    reprezentativec maxMedali = rep.reprezentativci[0]; 
    int i;
    for (i=1;i<rep.brReprezetativci;i++) { 
        if (rep.reprezentativci[i].medali>maxMedali.medali) { 
            maxMedali=rep.reprezentativci[i]; 
        }
    }

    maxMedali.pechati(); 
}
};

int main() {
    reprezentativec r1, r2, r3, r4, r5, r6, r7, r8, r9;
    r1.init("Janko", skiSkokac, 2);
    r2.init("Petko", skiSkokac, 1);
    r3.init("Stanko", skijac, 3);
    r4.init("Vlatko", skijac, 2);
    r5.init("Trajko", skijac, 1);
    r6.init("Goran", biatlonec, 4);
    r7.init("Ivan", biatlonec, 2);
    r8.init("Pero", biatlonec, 1);
    r9.init("Zoran", biatlonec, 3);

    reprezentativec rep1[] = {r1, r2, r3};
    reprezentativec rep2[] = {r4, r5, r6};
    reprezentativec rep3[] = {r7, r8, r9};

    reprezentacija Reprezentacija1;
    Reprezentacija1.init("Reprezentacija1", 3, rep1);

    reprezentacija Reprezentacija2;
    Reprezentacija2.init("Reprezentacija2", 3, rep2);

    reprezentacija Reprezentacija3;
    Reprezentacija3.init("Reprezentacija3", 3, rep3);

    cout<<"Reprezentacija1:" << endl;
    Reprezentacija1.pechati(skiSkokac);
    Reprezentacija1.pechati(skijac);
    Reprezentacija1.pechati(biatlonec);

    cout<<"Reprezentacija2:" << endl;
    Reprezentacija2.pechati(skiSkokac);
    Reprezentacija2.pechati(skijac);
    Reprezentacija2.pechati(biatlonec);

    cout<<"Reprezentacija3:" << endl;
    Reprezentacija3.pechati(skiSkokac);
    Reprezentacija3.pechati(skijac);
    Reprezentacija3.pechati(biatlonec);

    cout<<"Najtrofeen vo Reprezentacija1:"<<endl;
    Reprezentacija1.najTrofeen(Reprezentacija1);
    cout<<endl;

    cout<<"Najtrofeen vo Reprezentacija2:"<<endl;
    Reprezentacija2.najTrofeen(Reprezentacija2);
    cout<<endl;

    cout<<"Najtrofeen vo Reprezentacija3:"<<endl;
    Reprezentacija3.najTrofeen(Reprezentacija3);
    cout<<endl;

    return 0;
}