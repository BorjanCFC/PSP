#include<iostream>
#include<string>
using namespace std;

int mozniPremini[10] = {2, 5, 7, 4, 8, 2, 6, 9, 3, 1};

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

void func(KruzhnaLista &l, int x){

    Node *pom = l.head;

    int i = 0;

    Node *prev = l.head;
    while(x>0){
        int z = mozniPremini[i];

        do{
            prev = pom;
            pom=pom->link;
            z--;
            if(pom == l.head){
                x--;
            }

        }while(z>0);

        Node *p = new Node;

        p->info = pom->info;
        prev->link=p;
        p->link=pom;

        if(pom==l.head){
            l.head = p;
            l.tail->link = p;
        }
        i++;
    }
}