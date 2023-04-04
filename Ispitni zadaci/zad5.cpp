#include<iostream>
#include<string>
using namespace std;

typedef int info_t;
const int STACKSIZE = 20;

struct stack{

    info_t lista[STACKSIZE];
    info_t top;

    void init(){
        top=-1;
    }

    void StackOverflow(){
        cout<<"StackOverflow"<<endl;
        exit(-1);
    }

    void StackUnderflow(){
        cout<<"StackUnderflow"<<endl;
        exit(-1);
    }

    void push(info_t x){
        if(top >= STACKSIZE-1){
            StackOverflow();
        }else{
            top++;
            lista[top]=x;
        }
    }

    info_t pop(){
        if(top<0){
            StackUnderflow();
        }else{
            int pom=top;
            top--;
            return lista[pom];
        }
    }

    info_t peek(){
        if(top<0){
            StackUnderflow();
        }else{
            return lista[top];
        }
    }

    bool isEmpty(){
        return top<0;
    }

    bool isFull(){
        return (top == STACKSIZE-1);
    }

    bool func(stack m){
    
    stack p=m;
    stack pom;
    pom.init();

    while(!m.isEmpty()){
        pom.push(m.pop());
    }

    while(!p.isEmpty()){
        int k = pom.pop();
        int l = p.pop();

        if(k!=l){
            return false;
        }
        return true;
    }
  }
  
};
