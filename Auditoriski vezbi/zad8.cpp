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

int izbrisi(magacin &m, int x){
    magacin d;
    bool f;
    int p=0;
    int c=0;
    d.init();
    while(!m.isempty()){
        d.push(m.pop());
    }
    f=false;
    while(!d.isempty()){
        c++;
        if(f=false&&d.peek()==x){
            f=true;
            p=d.top+1;//p=c; ako trebase od dole da se najde pozicijata
            d.pop();
        }else{
            m.push(d.pop());
        }
    }
    return p;
}