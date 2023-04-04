// 1.Да се напише функција која како аргумент добива магацин (овој магацин треба да се модифицира во функцијата). 
// Во функцијата треба да се проверат сите броеви кои се елементи од магацинот и секој број да се спореди со неговите соседни броеви. 
// Притоа треба да се утврди дали соседните броеви може да бидат делители на разгледуваниот број. 
// Ако може, тогаш во излезниот магацин се запишува количникот (ако и двата соседни броеви може да бидат делители,
// тогаш се запишуваат двата количници). Во функцијата може да се користат помошни магацини (потребен е минимум еден помошен магацин), 
// но користење на низи не е дозволено. 
// Дополнително во програмата да се дефинира структурата магацин заедно со сите
// функции кои се потребни за функционирање на магацинот: за иницијализација, за проверка дали магацинот е полн и дали е празен, 
// за внесување елементи, за изнесување на елементи, за гледање на елементот кој е најгоре во магацинот и за печатење на елементите без 
// вадење на истите од магацинот. 

#include<iostream>
#include<string>
using namespace std;

typedef int info_t;
const int STACKSIZE = 20;

struct stack{

    info_t lista[STACKSIZE];
    info_t top;

    void init(){
        top=-1;
    }

    void StackOverflow(){
        cout<<"StackOverflow"<<endl;
        exit(-1);
    }

    void StackUnderflow(){
        cout<<"StackUnderflow"<<endl;
        exit(-1);
    }

    void push(info_t x){
        if(top >= STACKSIZE-1){
            StackOverflow();
        }else{
            top++;
            lista[top]=x;
        }
    }

    info_t pop(){
        if(top<0){
            StackUnderflow();
        }else{
            int pom=top;
            top--;
            return lista[pom];
        }
    }

    info_t peek(){
        if(top<0){
            StackUnderflow();
        }else{
            return lista[top];
        }
    }

    bool isEmpty(){
        return top<0;
    }

    bool isFull(){
        return (top == STACKSIZE-1);
    }

};

void func(stack &m){
    stack pom;
    
    pom.init();

    int prev, current, next;

    prev = m.pop();
    current = m.pop();

    while(!m.isEmpty()){
        next = m.pop();

        if(current%prev == 0){
            pom.push(current/prev);
        } 
        
        if(current%next == 0){
            pom.push(current/next);
        }
        prev = current;
        current = next;
    }

    while(!pom.isEmpty()){
        cout<<pom.pop()<<"\t";
    }

}

int main() {
	stack m1;

	m1.init();

	m1.push(2);
	m1.push(10);
	m1.push(5);
	m1.push(2);
	m1.push(1);

	func(m1);

	while(!m1.isEmpty()){
		cout<<m1.pop()<<endl;
	}

	return 0;
}
