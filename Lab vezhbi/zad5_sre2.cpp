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

    void print_list(){
        Node *pom = head;

        while(pom != NULL){
            cout<<pom->info<<"\t";
            pom = pom->link;
        }
        cout<<endl;
    }

    void delete_list(){

        while(head != NULL){
            delete_last();
        }
    }

    
};

void func(SLL &l1, SLL &l2, info_t p, info_t k){

    l2.init();

    Node *pom  = l1.head;
    while(pom != NULL){
        Node *temp = pom;
        if(temp->info >= p && temp->info <=k){

            Node *prev = l1.head;
            while(prev->link != temp){
                prev = prev->link;
            }
            prev->link = temp->link;

            if(temp == l1.head){
                l1.head == temp->link;
            }

            l2.insert_last(temp->info);
        }
        pom = pom->link;
    }
}

int main(){

SLL l;
l.init();
SLL l1;
l1.init();

int N, p, k;

cout<<"Vnesi dolzhina na listata: ";
cin>>N;

int i, element;

for(i=0; i<N; i++){

    cout<<"Vnesete go elementot "<<i+1<<": ";
    cin>>element;
    l.insert_last(element);

}

cout<<"Vnesete dva broja: ";
cin>>p>>k;

cout<<endl;
cout<<"Listata pred izvrsuvanje na funkcijata: "<<endl;
l.print_list();

func(l,l1,p,k);

cout<<endl<<"Listata po izvrsuvanje na funkcijata: "<<endl;
cout<<endl;

cout<<"Glavnata lista:"<<endl;
l.print_list();
cout<<endl;

cout<<"Listata so elementi vo opsegot:"<<endl;
l1.print_list();

return 0;
}
