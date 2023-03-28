// Да се напише функција која како аргумент добива декаден број и променлива од тип магацин.
// Функцијата треба да го испечати бинарниот број, но со користење само на магацинот. Да се напишат
// сите структури и функции кои се потребни за да се реализира работата на оваа функција. Во главната
// програма да се провери работата на функцијата. 

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

void dectobin(int x){
    
    info_t c;
    stack n;
    n.init();
    while(x){
        c=x%2;
        n.push(c);
        x/=2;

    }

    while(!n.isEmpty()){
        c==n.pop();
        cout<<c;
    }
}

int main()
{
int dek;
    cout<<"Vnesete dekaden broj: ";
    cin>>dek;
    dectobin(dek);
} 