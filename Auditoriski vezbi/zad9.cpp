#include<iostream>
using namespace std;

typedef int info_t;
const int STACKSIZE = 20;

struct stack{
    info_t lista[STACKSIZE];
    int top;
    void init();
    void push(info_t e);
    void StackOverflow();
    void StackUnderflow();
    info_t pop();
    info_t peek();
    bool isEmpty();
};

void stack::init(){
    top = -1;
}

void stack::push(info_t x){
    if(top>=STACKSIZE-1)
        StackOverflow();
    top++;
    lista[top]=x;
}

void stack::StackOverflow() {
    cout << "Stack Overflow!" << endl;
}

void stack::StackUnderflow(){
    cout << "Stack Underflow!" << endl;
}

info_t stack::peek(){
    if(top<0)
        StackUnderflow();
    return lista[top];
}

info_t stack::pop(){
    if(top<0)
        StackUnderflow();
    int temp=top;
    top--;
    return lista[temp];
}

bool stack::isEmpty(){
    return top<0;
}

void promeni(stack &m){

    stack h;
    h.init();
    int p,t;
    bool prv=true;

    while(!m.isEmpty()){
        t=m.pop();
        if(!prv && t%p==0){
            h.push(t/p);
        }
        p=t;
        prv=false;
        if(!m.isEmpty() && m.peek()==0){
            h.push(t/m.peek());
        }
    }

    while(!h.isEmpty()){
        m.push(h.pop());
    }
}
