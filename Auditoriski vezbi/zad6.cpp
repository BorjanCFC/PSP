// zadaca zagradi magacini
#include<iostream>
using namespace std;
typedef char info_t;

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
bool proverka(magacin m, char *s){
    info_t elem;
    while(*s){
        if(*s=='('||*s=='{'||*s=='['){
            // elem=*s
        }
        if(*s==')'&&m.peek()!='('){
            m.pop();
            
        }else if(*s==']'&&m.peek()!='['){
            m.pop();
        }else if(*s=='}'&&m.peek()!='{'){
            m.pop();
        }else(*s==')'||*s==']'||*s=='}'){
            cout<<"Greshka";
            return false;
        }
    }
    if(!m.isempty()){
        cout<<"Greshka";
        return false;
    }
    return true;
}