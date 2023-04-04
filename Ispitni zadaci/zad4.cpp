#include<iostream>
#include<string>
using namespace std;

#define MAX 50
const int QUEUESIZE = 20;
typedef int info_t;

struct Queue{

    int lista[MAX];
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

Queue kreiraj(int x){
    Queue r;
    r.init();

    while(x>0){
        int cifra=x%10;
        x/=10;
        r.enqueue(cifra);
    }
    return r;
}

Queue func(Queue r1, Queue r2){

    Queue r;
    r.init();

    int p=0;

    while(!r2.isEmpty()){
        int e1 = r1.dequeue() - p;
        int e2 = r2.dequeue();

        int e3 = e1-e2;

        if(e3<0){
            e3= 10 + e3;
            p=1;
        }else{
            p=0;
        }

        r.enqueue(e3);
    }

    while(!r1.isEmpty()){
        if(p){
            r.enqueue((r1.dequeue)-p);
            p=0;
        }else{
            r.enqueue(r1.dequeue());
            return r;
        }
    }
}