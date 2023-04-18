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

info_t func(DLL l){

    Node *pom = l.head;
    int iz = 0;
    int N;
    int z = 4;

    cout<<"Vnesete broj:";
    cin>>N;

    do{
        if(N>0){

        while(N>0){
            pom = pom->next;
            if(pom == l.head){
                z--;
            }
            N--;
        }

        iz += pom->info;
        N = pom->info;
        
        }else{

            int neg = -N;
            while(neg>0){
                pom = pom->prev;
                if(pom == l.tail){
                    z--;
                }
                neg--;
            }
            iz += pom->info;
            N = pom->info;

        }

    }while(z>0);

    return iz;
}

int main() {
    DLL L1;

    L1.init();
    L1.insert_first(-1);
    L1.insert_last(6);
    L1.insert_last(-4);
    L1.insert_last(-3);
    L1.insert_last(10);
    L1.insert_last(-4);
    L1.insert_last(5);

    int izlez = func(L1);
    cout<<"Sluchajno generiraniot broj e: "<<izlez<<endl;

    L1.print_list();
    L1.delete_list();

    return 0;
}
