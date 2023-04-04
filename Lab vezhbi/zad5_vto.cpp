#include<iostream>
using namespace std;

typedef int info_t;

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

        p->info = x;
        head = p;
        p->link = NULL;
    }

    void insert_first(info_t x){
        if(head == NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;

            p->info = x;
            p->link = head;
            head = p;
        }
    }

    void insert_last(info_t x){
        if(head == NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;
            Node *pom = head;
            p->info = x;
            while(pom->link != NULL){
                pom = pom->link;
            }
            pom->link = p;
            p->link = NULL;
        
        }
    }

    void delete_firsT(){
        if(head != NULL){
            if(head->link == NULL){
                delete head;
                head=NULL;
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
                delete head;
                head = NULL;
            }else{
                Node *pom = head;

                while(pom->link->link != NULL){
                    pom = pom->link;
                }
                Node *p = pom->link;
                pom->link = NULL;
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
        Node *pom = head;

        while(pom != NULL){
            cout<<pom->info<<"\t";
            pom = pom->link;
        }
        cout<<endl;

    }


};


void func(SLL &l) {

    Node *prev = l.head;
    Node *pom = l.head->link;

    while (pom != NULL) {
        prev->link = pom->link;
        pom->link = prev;

        if(prev == l.head){
            l.head = pom;
        }else{
            Node *prevPrev = l.head;

            while (prevPrev->link != prev) {
                prevPrev = prevPrev->link;
            }

            prevPrev->link = pom;
        }

        prev = prev->link;

        if(prev != NULL){
            pom = prev->link;
        }else{
            pom = NULL;
        }
    }
}

int main(){

SLL l;
l.init();

int N, x;

cout<<"Vnesi dolzhina na listata: ";
cin>>N;

int i, element;

for(i=0; i<N; i++){

    cout<<"Vnesete go elementot "<<i+1<<": ";
    cin>>element;
    l.insert_last(element);

}

cout<<"Listata pred izvrsuvanje na funkcijata: "<<endl;
l.print_list();

func(l);

cout<<endl<<"Listata po izvrsuvanje na funkcijata: "<<endl;
l.print_list();

return 0;
}