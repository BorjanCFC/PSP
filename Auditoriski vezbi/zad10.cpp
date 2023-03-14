#include<iostream>
using namespace std;

typedef int info_t;

#define MAX 50 

struct covek{

    string ime;
    string prezime;
    bool l,p,v;
};

struct queue{

    covek lista[MAX];
    int f, r;
    void init();
    bool isFull();
    bool isEmpty();
    void enqueue(covek e);
    covek dequeue();
    covek peek();
};


void opsluzhi(queue &r1, queue &r2, queue &r3){

    covek k;
    while(!r1.isEmpty()){
        k=r1.dequeue();
        cout<<"Opsluzheni za licni karti "<<k.ime<<" "<<k.prezime<<endl;
        k.l=false;
        if(k.p){
            r2.enqueue(k);
        }else if(k.v){
            r3.enqueue(k);
        }
    }

    while(!r2.isEmpty()){
        k=r2.dequeue();
        cout<<"Opsluzheni za pasosh "<<k.ime<<" "<<k.prezime<<endl;
        k.p=false;
        if(k.v){
            r3.enqueue(k);
        }
    }

     while(!r3.isEmpty()){
        k=r3.dequeue();
        cout<<"Opsluzheni za vozacka  "<<k.ime<<" "<<k.prezime<<endl;
    }

}

int main(){

    queue r1,r2,r3;
    r1.init();
    r2.init(); 
    r3.init();     
    char d = ' ';

    while(d!='.'){

        covek c;

        cout<<"Vnesi ime i prezime!"<<endl;
        cin>>c.ime>>c.prezime;
        cout<<"Dali kje cekas za licna karta?"<<endl;
        cin>>c.l;
        cout<<"Dali kje cekas za pasosh?"<<endl;
        cin>>c.p;
        cout<<"Dali kje cekas za vozacka?"<<endl;
        cin>>c.v;

        if(c.l){
            r1.enqueue(c);

        }else if(c.p){
            r2.enqueue(c);
        }else if(c.v){
            r3.enqueue(c);
        }

        cout<<"Vnesi tochka za kraj!"<<endl;
        cin>>d;
        
    }

opsluzhi(r1,r2,r3);
    return 0;
}