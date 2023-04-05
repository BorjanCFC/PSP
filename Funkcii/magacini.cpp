#include<iostream>
using namespace std;

typedef int info_t;
const int STACKSIZE = 20;

struct stack{
    info_t top;
    info_t lista[STACKSIZE];

    void init(){
        top = -1;
    }

    void StackOverflow(){
        cout<<"StackOverflow!"<<endl;
        exit(-1);
    }

    void StackUnderflow(){
        cout<<"StackUnderflow!"<<endl;
        exit(-1);
    }

    void push(info_t x){
        if(top >= STACKSIZE - 1){
            StackOverflow();
        }
        top++;
        lista[top] = x;
    }

    info_t pop(){
        if(top < 0){
            StackUnderflow();
        }
        int pom = top;
        top--;
        return lista[pom];
    }

    info_t peek(){
        if(top < 0){
            StackUnderflow();
        }else{
            return lista[top];
        }
    }

    bool isEmpty(){
        return top<0;
    }

    bool isFull(){
        return(top =  STACKSIZE-1);
    }
};