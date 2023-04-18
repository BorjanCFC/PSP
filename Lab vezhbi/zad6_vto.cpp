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

void func(DLL &l){

    int iz = 0;
    int N;

    Node *pom = l.head;

    while(true){

        cout<<"Vnesi broj:";
        cin>>N;

        if(N == 0){

            cout<<"\nVnesovte nevaliden broj. Kraj na igrata!"<<endl;
            break;

        }

        if(N>0){

            while(N>0){

                pom = pom->next;

                if(pom->next == NULL){

                    cout<<"\nKraj na igrata!"<<endl;
                    cout<<"Vashiot rezultat e: "<<iz<<endl;   
                    break;   

                }

                N--;
            }

            iz += pom->info;

            if(pom->next == NULL){

                break;

            }else{

                Node *temp = pom;

                if(pom == l.head){

                    l.head = l.head->next;
                    l.head->prev = NULL;
                    delete temp; 

                }else if(pom == l.tail){

                    l.tail = l.tail->prev;
                    l.tail->next = NULL;
                    delete temp;

                }else{

                    pom->next->prev = pom->prev;
                    pom->prev->next = pom->next;
                    pom = pom->next;
                    delete temp;

                }
            }
        }else{

            int neg = -N;

            while(neg>0){

                pom = pom->prev;

                if(pom == NULL){
 
                    cout<<"\nKraj na igrata!"<<endl;
                    cout<<"Vashiot rezultat e: "<<iz<<endl; 
 
                    break;       
                }
 
                neg--;
 
            }
 
            iz += pom->info;

            Node *temp = pom;
            
                if(pom == l.head){

                    l.head = l.head->next;
                    l.head->prev = NULL;
                    delete temp; 

                }else if(pom == l.tail){

                    l.tail = l.tail->prev;
                    l.tail->next = NULL;
                    delete temp;

                }else{
                    
                    pom->next->prev = pom->prev;
                    pom->prev->next = pom->next;
                    pom = pom->next;
                    delete temp;
                }
        }
    }
}

int main() {
    DLL L1;
    L1.init();
    L1.insert_first(2);
    L1.insert_before(L1.head,5);
    L1.insert_last(9);
    L1.insert_last(4);
    L1.insert_last(10);
    L1.insert_last(7);
    L1.insert_last(12);
    L1.insert_last(11);
    L1.insert_last(2);
    L1.insert_last(5);
    L1.insert_last(13);
    L1.insert_before(L1.tail,1);

    func(L1);

    L1.print_list();

    L1.delete_list();

    return 0;
}
