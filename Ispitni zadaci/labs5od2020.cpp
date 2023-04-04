// Да се имплементира функција која како аргументи добива единечно поврзана листа и
// природен број, а чија задача е да го избрише од листата елементот со реден број кој следи по
// дадениот природен број (да се смета дека почетниот елемент во листата е со реден број 0).
// Доколку редниот број на елементот што треба да се избрише е поголем од бројот на јазли во
// листата тогаш функцијата НЕ треба да изврши никаква промена врз истата.
// Како дел од програмата да се напишат структури за имплементација на јазол и листа
// заедно со функциите за поддршка на листата: функции за иницијализација, додавање и
// бришење на елемент на почеток од листата, додавање и бришење на елемент на крај од листата,
// бришење на цела листа и печатење на елементите од листата. Како дел од програмата да се
// напише main функција во која ќе се дефинира и иницијализира листата, и ќе се пополни со
// елементи кои се внесуваат преку тастатура. Исто така во main функцијата треба од тастатура да
// се внесе вредноста на редниот број на јазолот после кој ќе се изврши бришењето. Во main
// функцијата потоа да се повика функцијата за печатење на листата, по што ќе се повика бараната
// функција (која треба да се имплементира) и на крај ќе се испечати листата после
// модификацијата. Програмата да се напише во C++.
// Пример:
// list = |12|->|7|->|5|->|13|->|6|->|9|->|2|->NULL
// broj = 1
// Решение:
// list = |12|->|7|->|13|->|6|->|9|->|2|->NULL

#include<iostream>
#include<string>
using namespace std;

typedef int info_t;

struct Node{
    info_t info;
    Node *link;
};

struct SLL{
    Node *head;

    void init(){
        head=NULL;
    }

    void kreiraj(info_t x){
        Node *p = new Node;

        p->info=x;
        p->link=NULL;
        head=p;

    }

    void insert_first(info_t x){
        if(head==NULL){
            kreiraj(x);
        }else{
            Node *p =  new Node;
            p->info=x;

            p->link=head;
            head=p;
        }
    }

    void insert_last(info_t x){
        if(head==NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;
            Node *pom = head;

            p->info = x;

            while(pom->link != NULL){
                pom=pom->link;
            }
            pom->link=p;
            p->link=NULL;
        }
    }

    void delete_first(){
        if(head!=NULL){
            if(head->link==NULL){
                delete head;
                head=NULL;
            }else{
                Node *p = new Node;
                p=head;
                head=head->link;
                delete p;
            }
        }
    }

    void delete_last(){
        if(head!=NULL){
            if(head->link==NULL){
                delete head;
                head=NULL;
            }else{
                Node *p = new Node;
                p = head;

                while(p->link->link != NULL){
                    p=p->link;
                }

                Node *pom = p->link;
                
                p->link=NULL;
                delete pom;
                }     
            }
        }

    void delete_list(){
        while(head!=NULL){
            delete_last();
        }
    }

    void print_list(){
        Node *p =head;
        while(p!=NULL){
            cout<<p->info<<"\t";
            p=p->link;
        }
    }
    
};

void func(SLL &l, int index){

    Node *p=l.head;
    int counter=0;

    if(l.head == NULL){
        cout<<"Greshka!"<<endl;
    }

    while(p!=NULL && counter<index){
        p=p->link;
        counter++;
    }

    Node *pom = p->link;
    p->link = pom->link;
    delete pom;
    
}

int main(){

SLL L1;
L1.init();

int N, broj, infoJ;

cout<<"Vnesete kolku jazli ima listata"<<endl;
cin>>N;

cout<<"Vnesuvajte gi info polinjata na jazlite od listata"<<endl;
for(int i=0;i<N;i++) {
cin>>infoJ;
L1.insert_last(infoJ);
}

cout<<"Vnesete reden broj na jazolot posle koj ke se brise jazol od listata"<<endl;
cin>>broj;

func(L1, broj);

cout<<"Listata po modifikacijata e:"<<endl;
L1.print_list();
L1.delete_list();


return 0;
}