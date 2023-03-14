#include <iostream>
using namespace std;

struct student{
    string prezime,predmet;
    int indeks,poeni;
};

const int QueueMax = 10;
typedef student info_t;

struct queue{
    info_t lista[QueueMax];
    int f, r;
    void init();
    bool isFull();
    bool isEmpty();
    void enqueue(info_t e);
    info_t dequeue();
    info_t peek();
};

queue podredi(queue &PSP, queue &BIP){
    student p;
    queue izlez, pomPSP, pomBIP;

    izlez.init();
    pomPSP.init();
    pomBIP.init();

    while(!PSP.isEmpty()){
        p=PSP.dequeue();
        if(p.poeni>40){
            izlez.enqueue(p);
        }else{
            pomPSP.enqueue(p);
        }
    }

    while(!BIP.isEmpty()){
        p=BIP.dequeue();
        if(p.poeni>50){
            izlez.enqueue(p);
        }else{
            pomBIP.enqueue(p);
        }
    }

    while(!pomPSP.isEmpty()){
        p=pomPSP.dequeue();
        if(p.poeni>30){
            izlez.enqueue(p);
        }
    }

    while(!pomBIP.isEmpty()){
        p=pomBIP.dequeue();
        if(p.poeni>30){
            izlez.enqueue(p);
        }
    }
    return izlez;
}