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

    Node *getlast(){
        Node *pom=head;
        while(pom->link!=NULL){
            pom=pom->link;
        }
        return pom;
    }
    
};

void func(SLList *l1, SLList *l2){
    SLList l3;
    l3.init();

    Node *p1 = l1->head;
    Node *p2 = l2->head;

    while(p1!=NULL && p2!=NULL){
        if(p1->info<p2->info){
            l3.dodadiPosleden(p1->info);
            p1=p1->link;
        }else{
            l3.dodadiPosleden(p2->info);
            p2=p2->link;
        }
    }

    // while(p1!=NULL){
    //     l3.dodadiPosleden(p1->info);
    //     p1=p1->link;
    // }

    // while(p2!=NULL){
    //     l3.dodadiPosleden(p2->info);
    //     p2=p2->link;
    // }

    Node *p3 = p1==NULL? p2:p1;
    while(p3!=NULL){
        l3.dodadiPosleden(p3->info);
        p3=p3->link;
    }

    // while(p1!=NULL && p2!=NULL){
    //     if(p1->info<p2->info){
    //         if(l3.getlast()->info!=p1->info){
    //             l3.dodadiPosleden(p1->link)
    //             p1=p1->linl;
    //         }else if(p1->info>p2->info){
    //             if(p2->info!=l3.getlast()->info){
    //                 l3.dodadiPosleden(p2->info)
    //                 p2=p2->link;
    //             }
    //         }else{
    //             if(p3->info!=p1->info){
    //                 l3.dodadiPosleden(p1->link);
    //                 p1=p1->link;
    //                 p2=p2->link;
    //             }
    //         }
    //     }
    //     Node *p4=p1==NULL ? p2:p1;
    //     while(p4!=NULL){
    //         if(p4->info != p3->info){
    //             l3.dodadiPosleden(p4->info);
    //         }
    //     }
    // }
}