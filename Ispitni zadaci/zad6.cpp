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

bool proverka(Queue r, Queue r1, Queue r2){

    while(!r.isEmpty() && !r1.isEmpty() && !r2.isEmpty()){
        if((r1.dequeue()!=r.dequeue()) || (r2.dequeue()!=r.dequeue())){
            return false;
        }
    }

    if(r.isEmpty() && r1.isEmpty() && r2.isEmpty()){
        return true;
    }else{
        return false;
    }
}

int main(){
    
    Queue r, r1, r2;
    r.init();
    int n=0, e;
    char c;


    cout<<"Vnesuvaj elementi:"<<endl;
    while(true){
        cin>>e;
        r.enqueue(e);
        n++;
        cout<<"Vnesi tocka za kraj "<<endl;
        cin>>c;
        if(c=='.'){
            break;
        }
    }

    if(n%2==1){
        cout<<"Neparen broj na elementi!"<<endl;
        return 0;
    }

    r1.init();
    r2.init();

    Queue pom;
    pom.init();

    while(!r.isEmpty()){
        e = r.dequeue();
        r1.enqueue(e); 
        pom.enqueue(e);

        e = r.dequeue();
        r2.enqueue(e);
        pom.enqueue(e);
    }

    if(proverka(pom,r1,r2)==true){
        cout<<"Redovite se ekvivalentni!"<<endl;
    }else{
        cout<<"Redovite ne se ekvivalentni"<<endl;
    }




    return 0;
}