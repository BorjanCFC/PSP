// Треба да се состави игра во која победник е оној кој собрал повеќе поени помеѓу двајца играчи. 
// Поените за секое поле се запишани во двојно поврзана листа од која секој јазол содржи цел број (поени). 
// Во главната функција (main) дадено е пополнување на двојно поврзаната листа со цели броеви. 
// Исто така во главната функција е дадено и внесувањето на двајцата играчи. 
// За секој играч се знае име, презиме и поени (на почеток секој играч има по 0 поени). 
// Да се креира структурата играч. После внесените информации за играчите и патеката (листата), се повикува функција за 
// реализација на играта, која треба да се напише. 
// Играта се рализира во функција igra(), која како аргументи ги добива двајцата играчи и пополнетата двојно поврзана листа (патеката). 
// Прво игра едниот играч се’ додека не ја заврши играта, а потоа игра вториот играч, исто така се’ додека не ја заврши играта. 
// После играта кога и двајцата играчи имаат собрано одредени поени, односно после реализацијата на функцијата igra(), во главната 
// функција дадено е дека се печатат името, презимето и поените на победникот. Доколку и двајцата играчи имаат ист број на 
// поени, се печатат истите информации и за двајцата играчи.
// Играта се одвива на тој начин што секој играч при секоја партија внесува од тастатура број и насока. 
// На пример, ако внесе 3 и r се движи три чекори на десно во листата и застанува на третиот јазол после тековниот, 
// потоа во следната партија ако внесе 2 и l се движи два чекори на лево во листата и застанува на два јазли пред новиот тековен итн. 
// Играта завршува за тој играч, ако играчот внесе повеќе чекори отколку што има јазли во насоката што ја навел (на пример, ако се наоѓа 
// на претпоследен јазол, а внесе 5 и r). Притоа, на секое поле (јазол) на кој ќе застане играчот, содржи цел број што во играта 
// претставуваат поени и се собираат за време на целата игра, се додека не заврши. Кога играчот ќе започнува со играта стои на првиот 
// јазол и тие поени не влегуваат во вкупниот број на поени. Потоа, на ист начин започнува да игра и вториот играч.
// Како дел од програмата да се напишат структури за имплементација на јазол и листа и функциите за поддршка на листата: 
// функција за иницијализација, функции додавање и бришење на елемент на почеток од листата, додавање и бришење на елемент на крај од 
// листата, бришење на цела листа и печатење на елементите од листата.

//  Пример:
// lista: |6| ↔ |5| ↔ |2| ↔ |10| ↔ |3| ↔ |0| ↔ |7|
// Igrac1: Paul Kalk
// прво внесување: 2r;               поени = 0 + 2 = 2
// второ внесување: 3r;             поени = 2 + 0 = 2
// трето внесување: 4l;             поени = 2 + 5 = 7
// четврто внесување: 7r;         game over! поени = 7
 
// Igrac2: Jamie Jones
// прво внесување: 5r;               поени = 0 + 0 = 0
// второ внесување: 1r;             поени = 0 + 7 = 7
// трето внесување: 4l;             поени = 7 + 2 = 9
// четврто внесување: 3r;         поени = 9 + 0 = 9
// петто внесување: 3r;             game over! Поени = 9


// Pobednik e Jamie Jones so 9 poeni!


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

    void delete_list(){

        while(head != NULL){
            delete_last();
        }
    }

};

struct igrac{

    string ime, prezime;
    SLL cekori;
    int poeni;

};

void igra(igrac &i1, igrac &i2, SLL pateka){

    Node *i = i1.cekori.head;
    Node *p = pateka.head;

    while(p!=NULL && i!=NULL){
        int c = i->info;

        while(c>0 && p!=NULL){
            p = p->link;
            c--;
        }

        if(p!=NULL){
            i1.poeni+=p->info;
        }
        i=i->link;
    }

    i=i2.cekori.head;
    p=pateka.head;

    while(p!=NULL && i!=NULL){
        int c = i->info;

        while(c>0 && p!=NULL){
            p = p->link;
            c--;
        }

        if(p!=NULL){
            i2.poeni+=p->info;
        }
        i=i->link;
    }

}

int main(){

    igrac i1, i2;
    SLL pateka;

    pateka.init();

    cout<<"Vnesi boj na polinja: ";
    int n;
    cin>>n;

    while(n>0){
        int el;
        cin>>el;
        pateka.insert_last(el);
        n--;
    }

    cout<<"Ime i prezime igrac 1: ";
    cin>>i1.ime>>i1.prezime;

    cout<<"Vnesi broj na potezi:";
    cin>>n;

    i1.cekori.init();

    while(n>0){
        int el; 
        cin>>el;
        i1.cekori.insert_last(el);
    }

    cout<<"Ime i prezime igrac 1: ";
    cin>>i2.ime>>i2.prezime;

    cout<<"Vnesi broj na potezi:";
    cin>>n;

    i1.cekori.init();

    while(n>0){
        int el; 
        cin>>el;
        i2.cekori.insert_last(el);
    }

    igra(i1,i2,pateka);

    if(i1.poeni>i2.poeni){
        cout<<i1.ime<<" "<<i1.prezime<<" so"<<i1.poeni;
    }else if(i1.poeni<i2.poeni){
        cout<<i2.ime<<" "<<i2.prezime<<" so"<<i2.poeni;
    }else{
        cout<<i1.ime<<" "<<i1.prezime<<" so"<<i1.poeni;
        cout<<i2.ime<<" "<<i2.prezime<<" so"<<i2.poeni;
    }

    return 0;
}

