#include<iostream>
using namespace std;

typedef int info_t;

struct Node{
    info_t info;
    Node *link;
};

struct SLList{
    Node *head;

    void init(){
        head=NULL;
    }

    void kreiraj(info_t x){
        init();
        Node *p = new Node;
        p->info=x;
        head=p;
        p->link=NULL;
    }

    void dodadiPrv(info_t x){
        if(head==NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;
            p->info=x;
            p->link=head;
            head=p;
        }
    }

    void dodadiPosleden(info_t x){
        if(head==NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;
            p->info=x;
            Node *k= head;
            while(k->link!=NULL){
                k=k->link;
            }
            k->link=p;
            p->link=NULL;
        }
    }

    void brishiPrv(){
        if(head!=NULL){
            if(head->link==NULL){
                Node *p = new Node;
                p=head;
                delete p;
                head=NULL;
            }
        }else{
            Node *p = new Node;
            p=head;
            head=p->link;
            delete p;
        }
    }

    void brishiPosleden(){
        if(head!=NULL){
            if(head->link==NULL){
                delete head;
                head==NULL;
            }else{
                Node *pom = head;
                while(pom->link->link != NULL){
                    pom=pom->link;
                    Node *k = pom->link;
                    pom->link=NULL;
                    delete k;
                }
            }
        }
    }

    void pechatiLista(){
        Node *pom = head;
        while(pom!= NULL){
            cout<<pom->info<<"\t";
            pom=pom->link;
        }
    }

    void brishiLista(){
        while(head!=NULL){
            brishiPosleden();
        }
    }
};

int main(){

SLList lista;
info_t x;
int N;
int i;

lista.init();
cout<<"Vnesi dolzina na nizata:"<<endl;
cin>>N;
cout<<"Vnesi eden element:"<<endl;
cin>>x;

lista.kreiraj(x);

for(i=1;i<N;i++){
    cout<<"Vnesi element:"<<endl;
    cin>>x;
    i%2==0 ? lista.dodadiPrv(x) : lista.dodadiPosleden(x);
}

lista.pechatiLista();
lista.brishiPrv();
lista.brishiPosleden();
lista.pechatiLista();
lista.brishiLista();



    return 0;
}