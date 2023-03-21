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

void func(SLList &l){
    SLList pom;
    pom.init();
    Node *p = l.head;

    while(p!=NULL){
        pom.dodadiPrv(p->info);
        p=p->link;
    }

    l.brishiLista();
    p=pom.head;

    while(p!=NULL){
        l.dodadiPosleden(p->info);
        p=p->link;
    }
    pom.brishiLista();
}

void func(SLList &l){
    Node *prev, *next, *p;

    prev = l.head;
    p = l.head->link;
    prev->link=NULL;

    while(p!=NULL){
        next=p->link;
        p->link=prev;
        prev=p;
        p=next;
    }
    
    l.head=prev;

}