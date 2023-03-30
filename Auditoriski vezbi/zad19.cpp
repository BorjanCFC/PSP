// Да се имплементира двојно поврзана листа за која првиот јазол во лево ќе покажува на NULL и
// последниот јазол во десно ќе покажува на NULL. Да се креираат и функциите за поддршка на
// листата и во главната функција истите да се тестираат. 

#include <iostream>
using namespace std;

typedef int info_t;

struct Node{
    info_t info;
    Node *prev;
    Node *next;
};

struct List{
    
    Node *head;
    Node *tail;

    void init(){
        head=tail=NULL;
    }

    void kreiraj(info_t x){
        Node *p = new Node;
        p->info = x;
        head = tail = p;
        p->next = p->prev = p;
    }

    void insert_first(info_t x){
        if(head==NULL){
            kreiraj(x);
        }
        else{
            Node *p = new Node;

            p->info = x;
            p->next = head;
            p->prev = tail;

            head->prev = p;
            tail->next = p;

            head = p;
        }
    }

    void insert_last(info_t x){
        if(head==NULL){
            kreiraj(x);
        }
        else{
            Node *p = new Node;
            p->info = x;

            p->prev = tail;
            p->next = head;

            head->prev = p;
            tail->next = p;

            tail = p;
        }
    }

    void delete_first(){
        if(head != NULL){

            if(head->next == NULL){
                delete head;
                head = tail = NULL;
            }
            else{
                Node *p = new Node;

                p = head;
                head->next->prev = tail;
                tail->next = head->next;
                head = p->next;

                delete p;
            }
        }
    }

    void delete_last(){
        if (head != NULL){

            if(head->next == NULL){

                delete head;
                head = tail = NULL;
            }
            else{
                Node *p = new Node;

                p = tail;
                tail->prev->next=head;
                head->prev = tail->prev;
                tail = tail->prev;

                delete p;
            }
        }
    }

    void delete_poz(int x){

        if (head != NULL){
            Node *p = head;

            do{
                p = p->next;
                x--;
            }while (x > 0 && p != head);

            p->prev->next = p->next;
            p->next->prev = p->prev;

            delete p;
        }
    }

    void print_list(){
        Node *pom=new Node;
        pom=head;
        do{
        cout<<pom->info<<"\t";
            pom=pom->next;
        } while(pom != head);

        cout<<endl;
    }

    void deleteList(){
        while (head != NULL)
        delete_last();
    }

};

int main()
{
    List l1;
    l1.init();
    l1.insert_last(7);
    l1.print_list();
    l1.insert_first(2);
    l1.insert_last(5);
    l1.print_list();
    l1.delete_first();
    l1.print_list();
    l1.delete_last();
    l1.print_list();
    l1.deleteList();
} 

