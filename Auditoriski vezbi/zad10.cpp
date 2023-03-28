// На шалтерот на МВР се чека за вадење на лични карти, пасоши и возачки дозволи. Секој човек, за кој
// се знае името, презимето и информација на кои шалтери треба да чека, застанува во редицата за
// исправата која ја вади. Ако треба да вади повеќе исправи прво вади лична карта, па пасош, па возачка
// дозвола (откако ќе биде услужен во приоритетната редица, застанува во друга редица). Кога се отвора
// шалтерот, најпрво се опслужуваат луѓето кои вадат лични карти, па пасоши, па возачки дозволи. Да се
// напише програма која го симулира гореопишаното дејство.

#include<iostream>
using namespace std;

#define MAX 50
const int QUEUESIZE = 20;

struct covek{

    string ime;
    string prezime;
    bool l,p,v;
};

typedef covek info_t;

struct Queue{

    covek lista[MAX];
    int f, r;

    void init();
    bool isFull();
    bool isEmpty();
    void enqueue(info_t e);
    info_t dequeue();
    info_t peek();
    void QueueOverflow();
    void QueueUnderflow();

};

void Queue::init(){
    r=f=-1;
}

bool Queue::isFull(){
    return r == MAX-1;
}

bool Queue::isEmpty(){
    return f < 0;
}

void Queue::enqueue(info_t x){

    if(r >= QUEUESIZE-1)
        QueueOverflow();
    else{
        if(f == -1)
            f = 0;
        lista[++(r)] = x;
    }
    
}

info_t Queue::dequeue(){

    if(isEmpty())
        QueueUnderflow();
    info_t x = lista[f];
    if (f == r)
        r = f = -1;
    else
        f++;
    return x;

}

info_t Queue::peek(){

    if (f==-1)
        QueueUnderflow();
    return lista[f];

}

void Queue::QueueOverflow(){

    cout<<"ERROR:QueueOverflow"<<endl;
    exit(-1);

}

void Queue::QueueUnderflow(){

    cout<<"ERROR:QueueUnderflow"<<endl;
    exit(-1);

}

void opsluzhi(Queue &r1, Queue &r2, Queue &r3){

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
        cout<<"Opsluzheni za vozacka "<<k.ime<<" "<<k.prezime<<endl;
    }

}

int main(){

    Queue r1,r2,r3;
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