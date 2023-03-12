// За организација на дополнителна ден сесија, на факултетот му е потребна програма за распределба
// на студентите по просторија. За таа цел треба да се направаат две структури: структура за студентот
// и структура за просторијата. За секој студент се знае името и презимето на студентот, број на индекс
// и името на предметот што ќе го полага. За секоја просторија се знае име на просторијата (стринг),
// бројот на работни места кои ќе се користат (максималниот број на работни места е 10, а бројот на
// активни места одговара на бројот на студенти) и студентите во училницата (низа од променливи од
// тип структура студент). 

// Во секоја од структурите да се декларираат (како дел од структурите) и
// дефинираат функции за иницијализација на променливи и за печатење: init() и pechati(). За
// структурата просторија да се преоптовари функцијата за печатење, така што кога ќе и се
// проследува цел број x, тогаш да се испечатат само информациите за првите x студенти од низата
// со студенти. Дополнително, да се дефинира функција najOptovarenaProstorija() која како
// аргументи добива низа од простории и број на простории и ги печати податоците за просторијата
// со најмногу студенти.

// Да се напише главна програма во која ќе се иницијализираат 10 студенти и низа од две простории
// (првата со 4, а втората со 6 студенти). Иницијализацијата на променливите да се реализира преку
// функциите init(). Потоа за секоја од просториите да се повика функцијата за печатење (при
// повикувањето за првата просторија, да се повика без аргументи, а за втората со аргумент 3).
// Дополнително, да се повика najOptovarenaProstorija() кога на влез ја добива низата од простории. 

#include<iostream>
#include<string.h>
using namespace std;

struct student{

    string ime;
    string prezime;
    int brIndeks[2];
    string predmet;

    void init(string i, string p, int br, int god, string pr){
        ime=i;
        prezime=p;
        brIndeks[0]=br;
        brIndeks[1]=god;
        predmet=pr;
    }

    void pechati(){
        cout<<ime<<" "<<prezime<<" Indeks:"<<brIndeks[0]<<"/"<<brIndeks[1]<<" Predmet:"<<predmet<<endl;
    }

};

struct prostorija{

    string imeProstorija;
    int maxMesta;
    int freeMesta;
    student studenti[10];

    void init(string ime, int max){
        imeProstorija=ime;
        maxMesta=max;
        freeMesta=0;
    }

   void pechati(int x){
    int i;
        for(i=0;i<x;i++){
            cout<<"Student"<<i+1<<endl;
            studenti[i].pechati();
            cout<<endl;
        }
    }

    void najOptovarenaProstorija(prostorija *prostorii, int N){
        int max=0;
        int i;
        int poz=0;
        for(i=0;i<N;i++){
            if(prostorii[i].freeMesta<max){
                continue;
            }
            max=prostorii[i].maxMesta-prostorii[i].freeMesta;
            poz=i;
        }
    cout<<"Najoptovarenata prostorija e "<<prostorii[poz].imeProstorija<<" so "<<max<<" studneti"<<endl;
    cout<<"Studentite se: "<<endl;
    cout<<endl;
    prostorii[poz].pechati(max);
    }

};

int main(){

    student students[10];
    students[0].init("Trajko","Trajkovski",1,2022,"Matematika1");
    students[1].init("Petar","Petrovksi",22,2022,"Matematika2");
    students[2].init("Zoran","Zoranovski",37,2022,"PSP");
    students[3].init("Ilija","Ilievski",213,2022,"PIA");
    students[4].init("David","Davidovski",123,2022,"OE");
    students[5].init("Ana","Anevska",152,2022,"OEK");
    students[6].init("Kate","Katevska",125,2022,"Fizika1");
    students[7].init("Bobi","Bobevski",132,2022,"Fizika2");
    students[8].init("Roki","Rokevski",182,2022,"Matematika3");
    students[9].init("Mile","Milevski",104,2022,"Eletronika");

    prostorija Prostorii[2];
    Prostorii[0].init("PSP",4);
    Prostorii[1].init("Matematika1",3);

    Prostorii[0].studenti[0]=students[0];
    Prostorii[0].studenti[1]=students[1];
    Prostorii[0].studenti[2]=students[2];
    Prostorii[0].studenti[3]=students[3];

    Prostorii[1].studenti[0]=students[4];
    Prostorii[1].studenti[1]=students[5];
    Prostorii[1].studenti[2]=students[6];
    Prostorii[1].studenti[3]=students[7];
    Prostorii[1].studenti[4]=students[8];
    Prostorii[1].studenti[5]=students[9];

    cout<<"Prostorija 1"<<endl;
    cout<<endl;
    Prostorii[0].pechati(4);
    cout<<endl;

    cout<<"Prostorija 2"<<endl;
    Prostorii[1].pechati(3);
    cout<<endl;


    prostorija prostorii[2]={Prostorii[0],Prostorii[1]};
    Prostorii[0].najOptovarenaProstorija(prostorii,2);


    return 0;
}