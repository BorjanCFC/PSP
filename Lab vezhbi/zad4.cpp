#include<iostream>
#include<string>
using namespace std;

#define MAX 50
const int QUEUESIZE = 20;

struct covek{

    string ime;
    string embg;
    bool rezultat;
    bool testiranjeSer;
    bool testiranjePCR;

    void pechati()
    {
        cout<<ime<<" "<<"so maticen broj "<<embg;

        if(rezultat){
            cout<<" zema rezultati"<<endl;
        }
        else if(testiranjeSer){
            cout<<" pravi seroloshki test"<<endl;
        }
        else if (testiranjePCR){
            cout<<" pravi PCR test"<<endl;
        }
    }

};

typedef covek info_t;

struct Queue{

    covek lista[MAX];
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

void raspredeli_usluzi(Queue &lugje, Queue &rez, Queue &testSer, Queue &testPCR){
    covek k;

    while(!lugje.isEmpty()){

        k=lugje.dequeue();

        if(k.rezultat){
            rez.enqueue(k);
        }

        else if(k.testiranjeSer){
            testSer.enqueue(k);
        }

        else if(k.testiranjePCR){
            testPCR.enqueue(k);
        }
        
    }

    while(!rez.isEmpty()){

        k=rez.dequeue();
        k.pechati();
        k.rezultat=false;

        if(k.testiranjeSer){
            testSer.enqueue(k);

        }else if(k.testiranjePCR){
            testPCR.enqueue(k);
        }

    }

    while(!testSer.isEmpty()){

        k=testSer.dequeue();
        k.pechati();
        k.testiranjeSer=false;

        if(k.testiranjePCR){
            testPCR.enqueue(k);
        }

    }

     while(!testPCR.isEmpty()){

        k=testPCR.dequeue();
        k.pechati();
        k.testiranjePCR=false;

        break;

    }

}

int main()
{
    Queue lugje, za_testiranjeSer, za_testiranjePCR, za_rezultati;
    covek pomoshen;

    char c;
    int i=1;
    
    lugje.init();
    za_rezultati.init();
    za_testiranjeSer.init();
    za_testiranjePCR.init();
    
    while(1){

        cout<<"Vnesete podatoci za covek "<<i<<endl;
        cin>>pomoshen.ime>>pomoshen.embg>>pomoshen.rezultat>>pomoshen.testiranjeSer>>pomoshen.testiranjePCR;

        lugje.enqueue(pomoshen);
        cout<<endl;

        cout<<"Vnesete . za kraj na vnesuvanjeto"<<endl;
        cin>>c;

        if(c == '.')
            break;
        i++;

    }
    
    raspredeli_usluzi(lugje, za_rezultati, za_testiranjeSer, za_testiranjePCR);
    
    cout<<endl;


    return 0;
}