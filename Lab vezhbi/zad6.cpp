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


void modificiraj(DLL &l, DLL &l1, DLL &l2){

    l2.init();

    Node *pom = l.head;
    Node *pom1 = l1.head;

    do{
        Node *temp = pom;

        if(temp->info % 3 == 0){

            Node *deleteNode = new Node;
            deleteNode = temp;
            l2.insert_last(temp->info);

            if(temp == l.head){

                Node *brisi = new Node;
                brisi = temp;
                l.head = l.head->next;
                l.head->prev = l.tail;
                l.tail->next = l.head;
                delete brisi;
                pom = pom->next;

            }else if(temp == l.tail){

                Node *brisi = new Node;
                brisi = temp;
                l.tail = l.tail->prev;
                l.tail->next = l.head;
                l.head->prev = l.tail;
                delete brisi;

            }else{

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete deleteNode;

            }
        }
        pom = pom->next;

    }while(pom != l.head);

    do{
        Node *temp = pom1;
        Node *deleteNode = new Node;
        deleteNode = temp; 

        l2.insert_last(temp->info);
        if(temp == l1.head){

                Node *brisi = new Node;
                brisi = temp;
                l1.head = l1.head->next;
                l1.head->prev = l1.tail;
                l1.tail->next = l1.head;
                delete brisi;
                pom = pom->next;

            }else if(temp == l1.tail){

                Node *brisi = new Node;
                brisi = temp;
                l1.tail = l1.tail->prev;
                l1.tail->next = l1.head;
                l1.head->prev = l1.tail;
                delete brisi;

            }else{
   
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete deleteNode;

        }
        pom1 = pom1->next->next;
        
    }while(pom1 != l1.head);

}


int main() {
    DLL l; 
    DLL l1;

    l1.init();
    l.init();

    
    l.insert_last(18);
    l.insert_last(6);
    l.insert_last(7);
    l.insert_last(9);
    l.insert_last(3);
    l.insert_last(3);
    l.insert_last(7);
    l.insert_last(27);
    

    l1.insert_last(5);
    l1.insert_last(3);
    l1.insert_last(4);
    l1.insert_last(1);
    l1.insert_last(5);
    l1.insert_last(1);
    l1.insert_last(1);
    l1.insert_last(5);
    l1.insert_last(3);
    l1.insert_last(4);
    l1.insert_last(4);
    l1.insert_last(3);


    cout<<"Lista 1:"<<"\t";
    l.print_list(); 

    cout<<endl;

    cout<<"Lista 2:"<<"\t";
    l1.print_list();

    DLL l2; 
    modificiraj(l, l1, l2); 
    
    cout<<endl;

    cout<<"Listite po izvrsuvanje na funkcijta:"<<endl;
    cout<<endl; 

    cout<<"Lista 1:"<<"\t";
    l.print_list();

    cout<<endl;

    cout<<"Lista 2:"<<"\t";
    l1.print_list();

    cout<<endl;
    cout<<"Lista 3:"<<"\t";
    l2.print_list();



    cout<<endl;

    return 0;
}
