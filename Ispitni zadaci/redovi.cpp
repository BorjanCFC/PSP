#include<iostream>
using namespace std;

typedef int info_t;
const int QUEUESIZE = 20;

struct Queue{
    info_t r, f;
    info_t lista[QUEUESIZE];

    void init(){
        r = f = -1;
    }

    void QueueOverflow(){
        cout<<"QueueOverflow!"<<endl;
        exit(-1);
    }

    void QueueUnderflow(){
        cout<<"QueueUnderflow!"<<endl;
        exit(-1);
    }

    bool isFull(){
        return r = QUEUESIZE - 1;
    }

    bool isEmpty(){
        return f<0;
    }

    void enqueue(info_t x){
        if(r >= QUEUESIZE - 1){
            QueueOverflow();
        }else{
            if(f == -1){
                f = 0;
                lista[++r] = x;
            }
        }
        
    }

    info_t dequeue(){
        if(isEmpty()){
            QueueUnderflow();
        }else{
            info_t x = lista[f];
            if(f == r){
                f = r = -1;
            }else{
                f++;
            }
            return x;
        }
    }

    info_t peek(){
        if(f == -1){
            QueueUnderflow();
        }else{
            return lista[f];
        }
    }

};