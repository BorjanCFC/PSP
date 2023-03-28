// Од тастатура се внесуваат N букви. Од внесените букви буквата ‘X’ се појавува точно два пати. Таа
// буква го означува почетокот и крајот на секвенцата од букви кои треба да се повторат уште еднаш.
// Ваша задача е на екран да ја прикажете конечната секвенца од сите внесени букви, така што делот кој
// треба да се повторува (од првото до второто појавување на буквата ‘X’) ќе го прикажете уште еднаш, но
// во обратен редослед од оној во кој се јавува во влезната секвенца.
// Забелешка: дозволено е користење само на редови и магацини, не смее да се користат низи.
// Пример: Влезна секвенца: A K M X V W Q X D P.
//  Излезна секвенца: A K M X V W Q X X Q W V X D P 

#include <iostream>
using namespace std;

#define MAX 20
const int QUEUESIZE = 20;
const int STACKSIZE = 20;
typedef int info_t;

struct Queue{

    info_t lista[MAX];
    int f, r;

    void init();
    bool isFull();
    bool isEmpty();
    void enqueue(info_t e);
    info_t dequeue();
    info_t peek();
    void QueueOverflow();
    void QueueUnderflow();

};

void Queue::init(){
    r=f=-1;
}

bool Queue::isFull(){
    return r == MAX-1;
}

bool Queue::isEmpty(){
    return f < 0;
}

void Queue::enqueue(info_t x){

    if(r >= QUEUESIZE-1)
        QueueOverflow();
    else{
        if(f == -1)
            f = 0;
        lista[++(r)] = x;
    }
    
}

info_t Queue::dequeue(){

    if(isEmpty())
        QueueUnderflow();
    info_t x = lista[f];
    if (f == r)
        r = f = -1;
    else
        f++;
    return x;

}

info_t Queue::peek(){

    if (f==-1)
        QueueUnderflow();
    return lista[f];

}

void Queue::QueueOverflow(){

    cout<<"ERROR:QueueOverflow"<<endl;
    exit(-1);

}

void Queue::QueueUnderflow(){

    cout<<"ERROR:QueueUnderflow"<<endl;
    exit(-1);

}

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

int main(){

    Queue red;
    red.init();
    char c;

    while(true){
        cin>>c;
        red.enqueue(c);
        if (c=='.')
            break;
    }

    Queue izlez;
    izlez.init();

    stack pom;
    pom.init();

    while(!red.isEmpty()){
        c=red.dequeue();
        if(c!='X'){
            izlez.enqueue(c);
        }
        else{
            izlez.enqueue(c);
            pom.push(c);
            do{
                c=red.dequeue();
                izlez.enqueue(c);
                pom.push(c);

            }while (c != 'X');
        }
    }

    while(!pom.isEmpty()){
        c=pom.pop();
        izlez.enqueue(c);
    }

    while(!izlez.isEmpty()){
        c=izlez.dequeue();
        cout<<c;}

    return 0;
}