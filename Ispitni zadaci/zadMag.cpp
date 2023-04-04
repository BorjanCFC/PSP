#include<iostream>
using namespace std;

typedef int info_t;
const int STACKSIZE = 20;

struct stack{
    info_t top;
    info_t lista[STACKSIZE];

    void init(){
        top = -1;
    }

    void StackOverflow(){
        cout<<"StackOverflow!"<<endl;
        exit(-1);
    }

    void StackUnderflow(){
        cout<<"StackUnderflow!"<<endl;
        exit(-1);
    }

    void push(info_t x){
        if(top >= STACKSIZE - 1){
            StackOverflow();
        }
        top++;
        lista[top] = x;
    }

    info_t pop(){
        if(top < 0){
            StackUnderflow();
        }
        int pom = top;
        top--;
        return lista[pom];
    }

    info_t peek(){
        if(top < 0){
            StackUnderflow();
        }else{
            return lista[top];
        }
    }

    bool isEmpty(){
        return top<0;
    }

    bool isFull(){
        return(top ==  STACKSIZE-1);
    }
};

void func(stack &m){
    stack pom;
    pom.init();
    stack pom1;
    pom1.init();
    stack pom2;
    pom2.init();

    while(!m.isEmpty()){
        info_t element = m.pop();
        if(element == 0){
            pom.push(element);
            break;
        }else{
            pom.push(element);
        }
    }

    while(!m.isEmpty()){
        info_t element = m.pop();
        if(element == 0){
            m.push(element);
            break;
        }else{
        pom1.push(element);
        }
        
    }
    
    while(!pom1.isEmpty()){
        info_t element  = pom1.pop();
        pom2.push(element);
    }

    
    while(!pom2.isEmpty()){
        info_t element = pom2.pop();
        m.push(element);
    }

    while(!pom.isEmpty()){
        info_t element = pom.pop();
        m.push(element);
    }

    while(!m.isEmpty()){
        pom.push(m.pop());
    }

    while(!pom.isEmpty()){
        cout<<pom.pop()<<"\t";
    }

}



int main() {
    stack s;
    s.init();
    stack pom;
    pom.init();

    
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(0);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(0);
    s.push(1);
    s.push(3);

    stack s1 = s;

    while(!s1.isEmpty()){
        pom.push(s1.pop());
    }

    cout<<"Magacinot pred funkcijata:"<<endl;
    while(!pom.isEmpty()){
        cout<<pom.pop()<<"\t";
    }

    cout<<endl;
    
    cout<<"Magacinot posle funkcijata:"<<endl;
    func(s);

    return 0;
}