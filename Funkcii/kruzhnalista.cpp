#include<iostream>
#include<string>
using namespace std;

typedef int info_t;

struct Node{
    info_t info;
    Node *link;
};

struct KruzhnaLista{

    Node *head;
    Node *tail;

    void init(){
        head=tail=NULL;
    }

    void kreiraj(info_t x){
        Node *p = new Node;

        p->info=x;
        head=tail=p;
        p->link=p;
    }

    void insert_first(info_t x){
        if(head==NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;
            p->info=x;
            p->link=head;
            head=p;
            tail->link=p;
        }
    }

    void insert_last(info_t x){
        if(head==NULL){
            kreiraj(x);
        }
        Node *p = new Node;
        p->info=x;

        tail->link=p;
        p->link=head;
        tail=p;
    }

    void delete_first(){
        if(head!=NULL){
            if(head->link==NULL){
                delete head;
                head=tail=NULL;
            }else{
                tail->link=head->link;
                delete head;
                head=tail->link;
                
            }
        }
    }
    
    void delete_last(){
        if(head!=NULL){
            if(head->link==NULL){
                delete head;
                head=tail=NULL;
            }else{
                Node *p=new Node;
                p=head;

                while(p->link != tail){
                    p=p->link;
                }

                p->link=tail->link;
                delete tail;
                tail=p;
            }
        }
    }

    void delete_list(){
        while(head!=NULL){
            delete_last();
        }
    }

    void print_list(){
        Node *p = new Node;
        p=head;

        do{
            cout<<p->info<<"\t";
            p=p->link;
        }while(p != head);

        cout<<endl;
    }

};



