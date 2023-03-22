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

void func(stack &s1, stack &s2) {
    stack pom;
    pom.Init();
    int element;
    while(!s1.isEmpty()){
        element=s1.Pop();
        if(!s2.isEmpty() && element==s2.Peek()){
            s2.Pop();
            pom.Push(element);
        }
    }

    while(!pom.isEmpty()){
        element=pom.Pop();
        s1.Push(element);
    }
    
    while(!s2.isEmpty()){
        element=s2.Pop();
        s1.Push(element);
    }
}

int main() {
stack s1, s2;
int count, element;
 s1.Init();
 s2.Init();
 cout << "Vnesete kolku elementi da magacin 1:";
 cin >> count;
for (int i = 0; i < count; i++) {
 cin >> element;
 s1.Push(element);
 }

 cout << "Vnesete kolku elementi da magacin 2:";
 cin >> count;
for (int i = 0; i < count; i++) {
 cin >> element;
 s2.Push(element);
 }
 func(s1, s2);
 cout<<"\n";
while(!s1.isEmpty()){
 cout << s1.Pop() <<"\t";
}
cout<<"\n";
while(!s2.isEmpty())
 cout << s2.Pop() <<"\t";
}




