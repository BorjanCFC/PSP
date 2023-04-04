//studenti so povekje poeni od prosekot gi stavame vo nova lista

#include<iostream>
using namespace std;

struct student{
    string indeks;
    int poeni;
};

typedef student info_t;

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

        init();

        Node *p = new Node;

        p->info=x;
        head=p;
        p->link=NULL;
    }

    void insert_first(info_t x){

        if(head == NULL){
            kreiraj(x);

        }else{

            Node *p = new Node;

            p->info=x;
            p->link=head;
            head=p;
        }
    }

    void insert_last(info_t x){
        if(head == NULL){
            kreiraj(x);

        }else{

            Node *p =  new Node;
            Node *pom = head;

            p->info=x;

            while(pom->link != NULL){
                pom=pom->link;
            }

            pom->link=p;
            p->link=NULL;
        }
    }

    void delete_first(){
        if(head != NULL){

            if(head->link == NULL){
                Node *p = new Node;
                p = head;
                delete p;
                head = NULL;

            }else{

                Node *p = new Node;
                p = head;
                head = head->link;
                delete p;

            }
        }
    }

    void delete_last(){
        if(head != NULL){

            if(head->link == NULL){

                Node *p = new Node;
                p = head;   
                delete p;
                head = NULL;

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

        while(head != NULL){
            delete_last();
        }
    }

};

void func(SLL lista, SLL &r){
    r.init();

    float prosek=0.0;
    int n;

    Node *pom = lista.head;

    while(pom != NULL){
        n++;
        prosek+=pom->info.poeni;
        pom=pom->link;
    }

    prosek/=n;

    pom=lista.head;

    while(pom != NULL){
        if(pom->info.poeni>prosek){
            r.insert_last(pom->info);
        }
        pom=pom->link;
    }

}