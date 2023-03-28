// Да се напише функција која како аргумент добива веќе пополнета единечно поврзана листа
// чии јазли содржат цели броеви, а треба да формира две нови единечно поврзани листи. Во
// првата листа ќе се сместат јазлите кои носат информација за непарни броеви, додека во
// втората листа ќе се сместат јазлите кои носат информација за парните броеви. 

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
};

void func(SLList &l, SLList &l1, SLList &l2){
    l1.init();
    l2.init();

    Node *pom = l.head;
    while(pom!=NULL){
        (pom->info%2==0) ? l1.dodadiPosleden(pom->info) : l2.dodadiPosleden(pom->info);
        pom=pom->link;
    }

    l1.pechatiLista();
    l2.pechatiLista();
}

int main()
{

    SLList lista, parni, neparni;
    info_t x;
    int n;

    lista.init();

    cout<<"Vnesi broj na elementi"<<endl;
    cin >> n;

    cout<<"Vnesi prv elem"<<endl;
    cin>>x;
    lista.dodadiPrv(x);

    for(int i=1;i<n;i++){
        cout<<"Vnesi element"<<endl;
        cin>>x;

        i%2==0 ? lista.dodadiPrv(x) : lista.dodadiPosleden(x);
    }

    lista.pechatiLista();

    func(lista, parni, neparni);

    lista.brishiPrv();
    lista.brishiPosleden();

    lista.pechatiLista();
    lista.brishiLista();
}