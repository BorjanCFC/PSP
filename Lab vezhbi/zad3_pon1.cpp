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

void func(int br1, int br2, stack &m) {
    stack pom;
    stack pom1;
    pom1.Init();
    pom.Init();
    int element;

    while(!m.isEmpty()){
        pom1.Push(m.Pop());
    }

    while(!pom1.isEmpty()){
        element=pom1.Pop();
        if(element >=br1 && element <=br2){
            pom.Push(element);
        }
    }

    while(!pom.isEmpty()){
        element=pom.Pop();
        m.Push(element);
    }
}

int main(){
    stack s;
    int count, no1, no2, element;

    s.Init();

    cout<<"Vnesete kolku elementi da ima magacinot:";
    cin>>count;

    for(int i=0;i<count;i++){
        cin>>element;
        s.Push(element);
    }

    cout<<"Vnesete vrednosti:";
    cin>>no1>>no2;

    func(no1,no2,s);

    while(!s.isEmpty())
        cout<<s.Pop()<<endl;

    return 0;
}
