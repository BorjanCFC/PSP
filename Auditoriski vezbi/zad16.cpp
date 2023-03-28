// Нека се дадени две единечно поврзани листи чии јазли се сортирани во растечки редослед.
// Да се напише функција која ќе ги спои двете листи во една листа, која треба да е сортирана во
// растечки редослед. Во резултантната листа одново се креираат јазли. 

#include<iostream>
using namespace std;

typedef int info_t;

struct Node{
    info_t info;
    Node *link;
};

struct SLList{
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

    void dodadiPrv(info_t x){
        if(head==NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;
            p->info=x;
            p->link=head;
            head=p;
        }
    }

    void dodadiPosleden(info_t x){
        if(head==NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;
            p->info=x;
            Node *k= head;
            while(k->link!=NULL){
                k=k->link;
            }
            k->link=p;
            p->link=NULL;
        }
    }

    void brishiPrv(){
        if(head!=NULL){
            if(head->link==NULL){
                Node *p = new Node;
                p=head;
                delete p;
                head=NULL;
            }
        }else{
            Node *p = new Node;
            p=head;
            head=p->link;
            delete p;
        }
    }

    void brishiPosleden(){
        if(head!=NULL){
            if(head->link==NULL){
                delete head;
                head==NULL;
            }else{
                Node *pom = head;
                while(pom->link->link != NULL){
                    pom=pom->link;
                    Node *k = pom->link;
                    pom->link=NULL;
                    delete k;
                }
            }
        }
    }

    void pechatiLista(){
        Node *pom = head;
        while(pom!= NULL){
            cout<<pom->info<<"\t";
            pom=pom->link;
        }
    }

    void brishiLista(){
        while(head!=NULL){
            brishiPosleden();
        }
    }

    Node *getlast(){
        Node *pom=head;
        while(pom->link!=NULL){
            pom=pom->link;
        }
        return pom;
    }
    
};

void func(SLList l1, SLList l2)
{

    SLList l3;
    l3.init();

    Node *pom1=l1.head, *pom2=l2.head;

    while(pom1!=NULL && pom2!=NULL){

        if(pom1->info>pom2->info){
            if (pom2->info!=l3.getlast()->info){
                l3.dodadiPrv(pom2->info);
            pom2=pom2->link;
            }
        }
        else{
            if(pom1->info != l3.getlast()->info){
                l3.dodadiPosleden(pom1->info);
            pom1=pom1->link;
            }
        }
    }

    Node *pom=pom1==NULL ? pom2 : pom1;

    while (pom != NULL){
        if (pom->info != l3.getlast()->info){
            l3.dodadiPosleden(pom->info);
         pom=pom->link;
        }
    }

    l3.pechatiLista();
}

int main()
{

    SLList lista;
    info_t x;
    int n;

    lista.init();

    cout<<"Vnesi broj na elementi"<<endl;
    cin>>n;

    cout<<"Vnesi prv elem"<<endl;
    cin>>x;
    lista.dodadiPrv(x);

    for(int i=1;i<n;i++){
        cout<<"Vnesi element"<<endl;
        cin>>x;

        i%2==0 ? lista.dodadiPrv(x) : lista.dodadiPosleden(x);
    }

    lista.pechatiLista();
    lista.brishiPrv();
    lista.brishiPosleden();

    lista.pechatiLista();
    lista.brishiLista();
}