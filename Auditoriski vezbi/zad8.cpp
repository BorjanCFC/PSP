//  Да се напише функција која како аргументи добива магацин со веќе внесени елементи и еден
// цел број. Во магацинот да се најде последното појавување на елементот кој има вредност
// еднаква со вториот аргумент. Ако постои елемент со таква вредност, истиот да се отстрани од
// магацинот и да се врати позицијата на која е најден (броејки од горе надолу). Доколку не се
// најде елемент со таква вредност, функцијата да врати вредност нула. Да се напише главна
// програма во која ќе се внесат вредностите на еден магацин и број за пребарување и ќе се
// повика функцијата.
// Забелешка: Како дополнителна структура може да се користи само еден магацин. Да се
// користат операциите за додавање и отстранување на елементи од магацин. 

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

int izbrisi(stack &m, int x){
    stack d;
    bool f;
    int p=0;
    int c=0;
    d.init();
    while(!m.isEmpty()){
        d.push(m.pop());
    }
    f=false;
    while(!d.isEmpty()){
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

int main() {
    stack m1;
    int broj = 10;
    m1.init();
    m1.push(9);
    m1.push(10);
    m1.push(10);
    m1.push(7);
    m1.push(10);
    m1.push(2);
    m1.push(10);

    int p = izbrisi(m1,broj);
    if (p == 0) {
        cout << "Elementot ne e pronajden" << endl;
    } else {
        cout << "Elementot e na pozicija " << p << endl;
    }

    while (!m1.isEmpty()) {
        cout << m1.pop() << endl;
    }

    return 0;
}

