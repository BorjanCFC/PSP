#include<iostream>
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
        Node *p = new Node;

        p->info = x;

        p->next = NULL;
        p->prev = NULL;

        tail = head = p;

    }

    void insert_first(info_t x){
        if(head == NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;

            p->info = x;

            p->next = head;
            head->prev = p;
            p->prev = NULL;
            head = p;
        }
    }

    void insert_last(info_t x){
        if(head==NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;

            p->info = x;

            tail->next = p;
            p->prev = tail;
            p->next = NULL;
            tail = p;
        }
    }

    void delete_first(){
        if(head != NULL){
            if(head->next == NULL){
                delete head;
                head=tail=NULL;
            }else{
                Node *p = new Node;
                p = head;
                head = head->next;
                head->next->prev = NULL;
                delete p;
            }
        }
    }

    void delete_last(){

        if(head != NULL){
            if(head->next==NULL){
                delete head;
                head = tail = NULL;
            }else{
                Node *p = new Node;
                p = tail;
                tail->prev->next = NULL;
                tail = tail->prev;
                delete p;
            }
        }
    }

    void delete_list(){
        while(head != NULL){
            delete_last();
        }
    }

    void print_list(){
        Node *pom =  head;
        while(pom != NULL){
            cout<<pom->info<<"\t";
            pom = pom->next;
        }
        cout<<endl;
    }

};

