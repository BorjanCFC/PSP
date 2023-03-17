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
}

void stack::StackUnderflow(){
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

void func(stack &m){

    stack pom1, pom2;
    int suma=0, cifra;
    stack nov;

    pom1.Init();
    pom2.Init();
    nov.Init();

    while(!m.isEmpty()){
        pom1.Push(m.Pop());
        pom2.Push(pom1.Peek());
    }

    while(!pom2.isEmpty()){
        m.Push(pom2.Pop());
    }

    while(!pom1.isEmpty() && !m.isEmpty()){
        suma=pom1.Pop()+m.Pop();
        if(suma>9){
            cifra=9;
        }else{
            cifra=suma;
        }
        nov.Push(cifra);
    }

    while(!nov.isEmpty()){
        cout<<nov.Pop();
    }

}

int main()
{
    stack s;
    int n, element, c;
    s.Init();
    cout<<"Vnesete koj broj da se proveri:";
    cin>>n;

    while(n!=0){
        element=n%10;
        n/=10;
        s.Push(element);
    }

    func(s);

    return 0;
}