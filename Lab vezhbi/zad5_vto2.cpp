#include<iostream>
using namespace std;

typedef int info_t;

struct Node{
    info_t info;
    Node *link;
};

struct list{
    
    Node * head;
    Node *tail;

    void init(){
        head = tail = NULL;
    }

    void kreiraj(info_t x){

        Node *p = new Node;

        p->info = x;
        head = tail = p;
        p->link = p;

    }

    void insert_first(info_t x){

        if(head == NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;
            p->info = x;

            p->link = head;
            head = p;
            tail->link = p;

        }
    }

    void insert_last(info_t x){

        if(head == NULL){
            kreiraj(x);
        }else{
            Node *p = new Node;
            p->info = x;
            tail->link = p;
            p->link = head;
            tail = p;
        }
    }

    void delete_first(){
        if(head != NULL){
            if(head->link == NULL){
                delete head;
                head = tail = NULL;
            }else{
                Node *pom = new Node;
                pom = head;

                tail->link = head->link;
                head = head->link;
                delete pom;
            }
        }
    }

    void delete_last(){
        if(head != NULL){
            if(head->link == NULL){
                delete head;
                head = tail = NULL;
            }else{
                Node *pom = new Node;
                pom = tail;
                Node *p = head;

                while(p->link != tail){
                    p = p->link;
                }
                p->link = head;
                delete pom;
                tail = p;

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
        do{
        cout<<pom->info<<"\t";
            pom=pom->link;
        } while(pom != head);

        cout<<endl;
    }

};

void func(list &l1, list &l2){

    Node *p1 = l1.head;
    Node *p2 = l2.head;

    do{
        if(p1->info == p2->info){

            Node *temp = l2.head;
            while(temp->link != p2){
                temp = temp->link;
            }
            temp->link = p2->link;
            
            Node *pom = l1.head;
            while(pom->link != p1){
                pom = pom->link;
            }
            pom->link = p2;
            p2->link = p1;

            p2 = temp;

            if(p1 == l1.head){
                l1.head = pom;
            }
            
        }
        p1 = p1->link;
        p2 = p2->link;
        
    }while(p1 != l1.head  && p2 != l2.head);

}

int main(){
 list L1, L2;
 L1.init();
 L2.init();
 L1.insert_last(10);
 L1.insert_last(2);
 L1.insert_last(5);
 L1.insert_last(7);
 L1.insert_last(13);
 L2.insert_last(5);
 L2.insert_last(2);
 L2.insert_last(7);
 L2.insert_last(7);
 func(L1, L2);
 L1.print_list();
 L2.print_list();

 return 0;
}


