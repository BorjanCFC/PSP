#include<iostream>
#include<cmath>
using namespace std;

typedef int info_t;
const int STACKSIZE = 20;

struct stack{
    info_t lista[STACKSIZE];
    int top;
    void Init();
    void Push(info_t e);
    void StackOverflow();
    void StackUnderflow();
    info_t Pop();
    info_t Peek();
    bool isEmpty();
};

void stack::Init(){
    top = -1;
}

void stack::Push(info_t x){
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

info_t stack::Peek(){
    if(top<0)
        StackUnderflow();
    return lista[top];
}

info_t stack::Pop(){
    if(top<0)
        StackUnderflow();
    int temp=top;
    top--;
    return lista[temp];
}

bool stack::isEmpty(){
    return top<0;
}


void func(stack& s) {
stack pom;
stack pom1;
pom.Init();
pom1.Init();

int x;
int y;

while(!s.isEmpty()) { 
    x=s.Pop();
    if(s.isEmpty()==1){
        pom.Push(x);
    }else{
        y=s.Pop();
        pom.Push(y);
        pom.Push(x);
    }
}

while(!pom.isEmpty()) {
    pom1.Push(pom.Pop());
}

while(!pom1.isEmpty()) {
    s.Push(pom1.Pop());
}

}

int main(){
stack s;
int count, element;
s.Init();

cout << "Vnesete kolku elementi da ima magacinot: ";
cin >> count;

for (int i = 0; i < count; i++) {
    cin >> element;
    s.Push(element);
}

func(s);

while(!s.isEmpty()) {
    cout << s.Pop() << " ";
}

return 0;
}

