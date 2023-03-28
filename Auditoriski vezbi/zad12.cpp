// Да се напише функција која како аргументи добива два реда и треба да излез да врати нов
// ред кој ги комбинира влезните редови. Функцијата е наменета да ги распредели студентите кои
// истовремено полагаат втор колоквиум по ПСП и БиП во еден ред (влезните редови се
// наменети за секој од предметите ПСП и БиП). За секој студент се знае презиме, број на индекс
// (без година), испит кој го полага и број на освоени поени на прв колоквиум. Притоа во
// излезниот ред треба прво да ги постават студентите кои освоиле над 40 поени на првиот
// колоквиум по ПСП, па студентите кои освоиле над 50 поени на првиот колоквиум по БИП, по
// што треба да се постават останатите студенти по ПСП (кои имаат под 40 поени) и на крај
// останатите студенти по БиП (кои имаат под 50 поени). Доколку некој студент има под 30
// поени да не се запишува во излезниот ред. Во функцијата може да се користат помошни
// редови, но користење на низи не е дозволено. По завршувањето на функцијата двата влезни
// реда треба да бидат празни. Дополнително во програмата да се дефинира структурата ред
// заедно со сите функции кои се потребни за функционирање на редот: за иницијализација, за
// проверка дали редот е полн и дали е празен, за внесување елементи, за изнесување на
// елементи, за гледање на елементот кој е напред во редот и за печатење на елементите без
// вадење на истите од редот. 

#include <iostream>
using namespace std;

struct student{
    string prezime,predmet;
    int indeks,poeni;
};


typedef student info_t;
#define MAX 50
const int QUEUESIZE = 20;


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
Queue podredi(Queue &PSP, Queue &BIP){
    student p;
    Queue izlez, pomPSP, pomBIP;

    izlez.init();
    pomPSP.init();
    pomBIP.init();

    while(!PSP.isEmpty()){
        p=PSP.dequeue();
        if(p.poeni>40){
            izlez.enqueue(p);
        }else{
            pomPSP.enqueue(p);
        }
    }

    while(!BIP.isEmpty()){
        p=BIP.dequeue();
        if(p.poeni>50){
            izlez.enqueue(p);
        }else{
            pomBIP.enqueue(p);
        }
    }

    while(!pomPSP.isEmpty()){
        p=pomPSP.dequeue();
        if(p.poeni>30){
            izlez.enqueue(p);
        }
    }

    while(!pomBIP.isEmpty()){
        p=pomBIP.dequeue();
        if(p.poeni>30){
            izlez.enqueue(p);
        }
    }
    return izlez;
}

int main() {
    Queue r1, r2, r;
    r1.init();
    r2.init();
    r1.enqueue({"Vanevski", "PSP", 76, 20});
    r1.enqueue({"Bogoeska", "PSP", 146, 39});
    r1.enqueue({"Stamatovski", "PSP", 14, 80});
    r1.enqueue({"Naumoska", "PSP", 134, 90});
    r2.enqueue({"Skrceski", "BiP", 150, 80});
    r2.enqueue({"Spaseski", "BiP", 236, 40});
    r2.enqueue({"Koloski", "BiP", 12, 60});
    r = podredi(r1, r2);
    return 0;
}