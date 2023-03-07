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

void dectobin(int x){
    info_t c;
    magacin n;
    n.init();
    while(x){
        c=x%2;
        n.push(c);
        x/=2;

    }
    while(!n.isempty()){
        c==n.pop();
        cout<<c;
    }
}