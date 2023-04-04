#include<iostream>
#include<string>
using namespace std;

typedef int info_t;

struct Node{
    info_t info;
    Node *prev;
    Node *next;

};

struct DLL{

    Node *head;
    Node *tail;

    void init(){
        head=tail=NULL;
    }

    void kreiraj(info_t x){
        Node *p =  new Node;

        p->info=x;
        head=tail=p;
        p->prev=p->next=p;

    }

    void insert_first(info_t x){
        if(head == NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;
            p->info=x;

            p->next=head;
            p->prev=tail;

            head->prev=p;
            tail->next=p;

            head=p;
        }
    }

    void insert_last(info_t x){
        if(head==NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;
            p->info=x;

            tail->next=p;
            head->prev=p;

            p->prev=tail;
            p->next=head;
            
            tail=p;
        }
    }

    void delete_first(){
        if(head!=NULL){
            if(head->next==NULL){
                delete head;
                head=tail=NULL;
            }else{
                Node *p = new Node;
                p=head;

                tail->next=head->next;
                head->next->prev=tail;
                head=head->next;

                delete p;
            }
        }
    }

    void delete_last(){
        if(head!=NULL){
            if(head->next==NULL){
                delete head;
                head=tail=NULL;
            }else{
                Node *p = new Node;
                p=tail;

                tail->prev->next=head;
                head->prev=tail->prev;
                tail=tail->prev;

                delete p;
            }
        }
    }

    void delete_position(info_t x){
        if(head!=NULL){
            Node *p = head;

            do{
                p = p->next;
                x--;
            }while(x>0 && p!=head);

            p->prev->next=p->next;
            p->next->prev=p->prev;

            delete p;
        }
    }

    void print_list(){
        Node *p = new Node;
        p=head;

        do{
            cout<<p->info<<"\t";

            p = p->next;
        }while(p != head);

        cout<<endl;
    }

    void delete_list(){
        while(head!=NULL){
            delete_last();
        }
    }
};

void func(DLL &l1, DLL &l2){
    Node *p1 = l1.head;
    Node *p2 = l2.head;

    while(p1 != NULL && p2!= NULL){
        if(p1->info == p2->info){
            Node *pom = p2;
            pom->prev->next = pom->next;
            pom->next->prev = pom->prev;

            p2 = pom->prev;
            pom->prev = p1->prev;
            pom->next = p1;
            p1->prev = pom;
            pom->prev->next = pom;

            if(p1 == l1.head){
                l1.head = pom;
            }
        }
        p1 = p1->next;
        p2 = p2->next;
    }
}