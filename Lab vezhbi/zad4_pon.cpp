#include<iostream>
#include<string>
using namespace std;

#define MAX 50
const int QUEUESIZE = 20;

struct student{
    string ime;
    int brIndeks;
    int poeni;

    void pechati(){
        cout<<ime<<" "<<brIndeks<<" "<<poeni<<endl;
    }
};

typedef student info_t;

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

void raspredeli(Queue &studenti, Queue &polozheni, Queue &nepolozheni){
        while(!studenti.isEmpty()){
        student s=studenti.dequeue();
        if(s.poeni>=50){
            polozheni.enqueue(s);
        }else{
            nepolozheni.enqueue(s);
        }
        } 

        cout<<"Polozheni studenti: "<<endl;
        while(!polozheni.isEmpty()){
            polozheni.dequeue().pechati();
        }

        cout<<"Nepolozheni studenti: "<<endl;
        while(!nepolozheni.isEmpty()){
            nepolozheni.dequeue().pechati();
        } 
}

int main() {
Queue studenti, polozheni, nepolozheni;
student pomoshen;
char cont;
int i = 1;

studenti.init();
polozheni.init();
nepolozheni.init();

while(1) {
    cout<<"Vnesete podatoci za student "<<i<<endl;
    cin>>pomoshen.ime>>pomoshen.brIndeks>>pomoshen.poeni;
    studenti.enqueue(pomoshen);
    cout<<endl;
    cout<<"Vnesete . za kraj na vnesuvanjeto"<<endl;
    cin>>cont;
    if(cont == '.'){
        break;
    }
    i++;
}

raspredeli(studenti, polozheni, nepolozheni);
cout<<endl;

return 0;
}