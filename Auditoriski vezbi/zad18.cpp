// Да се реализира единечно–поврзана кружна листа. Да се реализираат функциите за
// поддршка на листата и да се тестира листата во главната функција.
// Единечно–поврзана кружна листа претставува единечно поврзана листа кај која последниот
// јазол покажува кон првиот јазол. 

#include <iostream>

using namespace std;

typedef int info_t;

struct Node
{
    info_t info;
    Node *link;
};

struct list{
    Node *head;
    Node *tail;

    void init(){ 
        head=tail=NULL; 
    }

    void kreiraj(info_t x){

        Node *p=new Node;

        p->info=x;
        head=tail=p;
        p->link=p;
    }

    void insert_first(info_t x){

        if(head==NULL){
            kreiraj(x);
        }
        else{
            Node *p=new Node;

            p->info=x;
            tail->link=p;
            p->link=head;
            head=p;
        }
    }

    void insert_last(info_t x)
    {

        if(head==NULL){
            kreiraj(x);
        }
        else{
            Node *p=new Node;

            p->info=x;
            tail->link=p;
            p->link=head;
            tail=p;
        }
    }

    void delete_first(){
    
    if(head != NULL){

        if(head->link==NULL) {
            delete head;
            head=tail=NULL;
        }else{
            tail->link = head->link;
            delete head;
            head = tail->link;
        }
    }
    }

    void delete_last(){

        if(head!=NULL){

            if(head->link==NULL){
                delete tail;
                tail=head=NULL;
            }else{
                Node *pom=new Node;
                pom=head;

                while(pom->link!=tail){
                    pom=pom->link;
                }
                pom->link=head;
                delete tail;
                tail=pom;
            }
        }
    }

    void delete_list(){
        while (head != NULL){
            delete_last();
        }
    }

    void print_list(){
        Node *pom=new Node;
        pom=head;
        do{
        cout<<pom->info<<"\t";
            pom=pom->link;
        } while(pom != head);

        cout<<endl;
    }

    
};

int main(){

    list l1;

    l1.init();
    l1.insert_last(4);
    l1.print_list();
    l1.insert_first(2);
    l1.insert_last(5);
    l1.print_list();
    l1.delete_first();
    l1.print_list();
    l1.delete_last();
    l1.print_list();
    l1.delete_list();
 
} 
