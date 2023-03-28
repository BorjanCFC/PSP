// Да се напише програма во која ќе се работи со редови. Еден ред се состои од повеќе елементи.
// Во елементите основен податочен тип е цел број. Во првиот ред се чуваат разместени елементи.
// Во вториот ред се чуваат позициите на елементите во кои треба да биде првиот ред. Во излезниот
// ред, елементите од првиот ред треба да се наредат според редоследот даден во вториот ред. Во
// програмата е дозволена употреба на дополнителни редови. Да се дефинира структурата на еден
// ред со основни елементи во кој има цели броеви. Да се дефинираат и функциите потребни за
// правилна работа на редот- додавање вредност, повлекување вредност, читање на првата вредност
// во редот. Употребата на низи или магацини не е дозволена.

#include <iostream>

using namespace std;

#define MAX 20
const int QUEUESIZE = 20;
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

int getElemByIndex(Queue red, int i){
    while (i){
        red.dequeue();
        i--;
    }
    return red.peek();
}

Queue funk(Queue r1, Queue r2){

    Queue r3;
    r3.init();

    int elem, i;

    while(!r2.isEmpty()){
        i=r2.dequeue();
        elem=getElemByIndex(r1, i);
        r3.enqueue(elem);
    }
return r3;

}
