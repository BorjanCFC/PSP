#include<iostream>
#include<string>
using namespace std;

#define MAX 50
const int QUEUESIZE = 20;
typedef int info_t;

struct Queue{

    int lista[MAX];
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

void func(Queue &r, int num1, int num2){
    Queue pom;
    pom.init();
    int temp;
    int x;

    if(num1>num2){
    temp=num1;
    num1=num2;
    num2=temp;
    }

while(!r.isEmpty()){
    x=r.dequeue();
    if(x<num1 || x>num2){
        pom.enqueue(x);
    }
}

while(!pom.isEmpty()){
    r.enqueue(pom.dequeue());
}
}


int main() {
Queue s;
int count, no1, no2, element;
s.init();

cout<<"Vnesete kolku elementi da ima redot:";
cin>>count;

for(int i=0;i<count;i++){
    cin>>element;
    s.enqueue(element);
}

cout<<"Vnesete vrednosti:";
cin>>no1>>no2;

func(s, no1, no2);

while(!s.isEmpty()){
    cout<<s.dequeue()<<endl;
}

return 0;
}