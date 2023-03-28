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

void func(Queue& r){
    Queue pom;
    pom.init();
    info_t element,prev,current;

    while(!r.isEmpty()){
        element = r.dequeue();
        pom.enqueue(element);
    }

    prev=pom.dequeue();

    while(!pom.isEmpty()){

    current = pom.dequeue();
    if(prev+current>9){
        r.enqueue(prev);
    }else{
        r.enqueue(prev+current);
    }
    prev=current;

    }

}

int main() {
    Queue s;
    int count, element;
    s.init();
    cout<<"Vnesete kolku elementi da ima redot:";
    cin>>count;
    for(int i=0;i<count;i++){
        cin>>element;
        s.enqueue(element);
    }
    func(s);
    while(!s.isEmpty()){
        cout<<s.dequeue()<<"\t";
    }
    cout << endl;
}