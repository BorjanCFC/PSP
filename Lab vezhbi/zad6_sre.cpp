#include<iostream>
using namespace std;

typedef char info_t;

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

    void insert_before(Node *pom, info_t x){
        if(head == NULL){
            kreiraj(x);
        }else{ 
            Node *p = new Node;
            p->info = x;

        if(pom == head){
            p->next = pom;
            p->prev = NULL;
            pom->prev = p;
            head = p;
        }else{
        
        pom->prev->next = p;
        p->next = pom;
        p->prev = pom->prev;
        pom->prev = p;
        }

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

void func(DLL &l, DLL &l1, info_t c){

    l1.init();

    Node *pom = l.tail;
    Node *found = NULL;

    while(pom != NULL){
        if(pom->info == c){
            found = pom;
            break;
        }
        pom = pom->prev;
    }

    if(found == NULL){
        cout<<"Ne postoi jazol sto ima "<<c<<endl;
    }

    if(found == l.head){

        Node *temp = found;
        l1.head = NULL;
        l.head = l.head->next;
        l.head->prev = NULL;
        delete temp;

    }else if(found == l.tail){

        Node *temp = found;
        l1.head = l.head;
        found->prev->next = NULL;
        l1.tail = found->prev;
        delete temp;
        l.init();

    }else{

        Node *temp = found;
        l1.head = l.head;
        l1.tail = found->prev;
        found->prev->next = NULL;
        found->next->prev = NULL;
        l.head = found->next;
        delete temp;

    }

}

int main(){

    DLL L1, L2;
    L1.init();

    L1.insert_last('m');
    L1.insert_last('n');
    L1.insert_last('o');
    L1.insert_last('g');
    L1.insert_last('u');
    L1.insert_last(' ');
    L1.insert_last('s');
    L1.insert_last('a');
    L1.insert_last('k');
    L1.insert_last('a');
    L1.insert_last('m');
    L1.insert_last(' ');
    L1.insert_last('p');
    L1.insert_last('s');
    L1.insert_last('p');
    
    func(L1, L2, ' ');

    cout<<"Lista 1: ";
    L1.print_list();

    cout<<"Lista 2: ";
    L2.print_list();

    L1.delete_list();
    L2.delete_list();

    return 0;
}
