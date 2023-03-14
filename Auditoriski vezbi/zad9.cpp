#include<iostream>
using namespace std;

typedef int info_t;

struct magacin{

    info_t lista[50];
    int top;
    void init();
    void push(info_t e);
    info_t pop();
    info_t peek();
    void stackoverflow();
    void stackunderflow();
    bool isempty();
};

void promeni(magacin &m){

    magacin h;
    h.init();
    int p,t;
    bool prv=true;

    while(!m.isempty()){
        t=m.pop();
        if(!prv && t%p==0){
            h.push(t/p);
        }
        p=t;
        prv=false;
        if(!m.isempty() && m.peek()==0){
            h.push(t/m.peek());
        }
    }

    while(!h.isempty()){
        m.push(h.pop());
    }
}
