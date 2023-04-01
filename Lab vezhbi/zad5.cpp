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
    }

    void delete_list(){

        while(head != NULL){
            delete_last();
        }
    }

    
};

void func(SLL &l, int x){

    Node *p = l.head;

    while(p != NULL){

        if(p->info == x){

            Node *nov = new Node;

            nov->info = p->info;
            nov->link = p->link;
            p->link = nov;
            p = nov->link;
        }else{
        p = p->link;
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

cout<<"Vnesete go elementot koj sakate da se udvoi: ";
cin>>x;

cout<<"Listata pred izvrsuvanje na funkcijata: "<<endl;
l.print_list();

func(l, x);

cout<<endl<<"Listata po izvrsuvanje na funkcijata: "<<endl;
l.print_list();

return 0;
}
