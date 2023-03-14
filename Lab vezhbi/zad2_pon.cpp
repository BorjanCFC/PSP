// За една статистичка анализа потребна е програма за управување со аптеки. За таа цел да се направат
// две структури: структура за аптека и структура за вработен. За секоја аптека се знае името, бројот
// на вработени и низа од променливи од тип структура вработен (во низата има максимум 8
// променливи). За секој вработен се знае името (стринг), работната позиција (фармацефт, техничар
// и помошен персонал – да се реализира со enum) и платата.

// Во секоја од структурите да се декларираат (како дел од структурите) и дефинираат функции за иницијализација на променливи
// и за печатење: init() и pechati(). За структурата аптека да се преоптовари функцијата за печатење,
// така што кога фунцијата на влез ќе добие податок од тип enum, тогаш да се испечатат само
// информациите за вработените со соодветна позиција која одговара на внесената вредност од тип
// enum. Дополнително, да се дефинира функција najZahtevnaApteka() која како аргумент добива
// низа од променливи од тип аптека, должина на низата и ги печати податоците за аптеката за која се
// исплаќаат најмногу пари за плати.

// Во главната програма да се овозможи внесување на информациите потребни за креирање на низа
// од три аптеки и внесување на вработени во секоја аптека. Иницијализацијата на променливите да
// се прави со функцијата init(). За првата аптека да се испечатат сите податоци, а за втората аптека
// да се испечатат податоците на сите фармацефти. На крај да се испечатат податоците за аптеката
// каде се исплаќаат најмногу сретства за плати.

#include<iostream>
using namespace std;

enum pozicija {farmaceft,tehnicar,pomPersonal};

struct vraboten{
    string ime;
    pozicija poz;
    int plata;

    void init(string i, pozicija p, int pl){
        ime=i;
        poz=p;
        plata=pl;
    }

    void pechati(){
    cout<<ime<<" ";
    switch(poz){
        case farmaceft:
            cout<<"farmaceft";
            break;
        case tehnicar:
            cout<<"tehnicar";
            break;
        case pomPersonal:
            cout<<"pomoshen personal";
            break;
    }
    cout<<" i zema plata "<<plata<<endl;
    cout<<endl;
}
};

struct apteka{
    string ime;
    int brVraboteni;
    vraboten vraboteni[8];
    
    void init(string i, int brV, vraboten vrab[]){
        ime=i;
        brVraboteni=brV;

        for(int i=0; i<brVraboteni;i++){
            vraboteni[i]=vrab[i];
        }
    }

    void pechati(pozicija poz){
        int i;
        for(i=0;i<brVraboteni;i++){
            if(vraboteni[i].poz==poz){
                vraboteni[i].pechati();
            }
        }
    }

    void najZahtevnaApteka(apteka apteki[], int N){
        int max,poz,vkupno,i,j;
        max=poz=vkupno=0;

        for(i=0;i<N;i++){
            for(j=0;j<apteki[i].brVraboteni;j++){
                vkupno+=apteki[i].vraboteni[j].plata;
            }
            if(vkupno>max){
                max=vkupno;
                poz=i;  
            }
        }
        if(poz){
            cout<<"Najplatena apteka: "<<apteki[poz].ime<<" so vkupna isplata na vrabotenite "<<max<<endl;
        }
    }
};

int main(){
    apteka apteki[3];
    vraboten vrab[8];

    vrab[0].init("Ana",farmaceft,20000);
    vrab[1].init("Petar",tehnicar,15000);
    vrab[2].init("Ivana",pomPersonal,10000);

    apteki[0].init("Zegin",3,vrab);

    cout<<"Podatoci za apteka 1:"<<endl;
    cout<<endl;
    apteki[0].pechati(farmaceft);
    apteki[0].pechati(tehnicar);
    apteki[0].pechati(pomPersonal);

    vrab[0].init("Maja",farmaceft,25000);
    vrab[1].init("Marko",farmaceft,22000);
    vrab[2].init("Jana",tehnicar,18000);
    vrab[3].init("Igor",tehnicar,17000);

    apteki[1].init("Eurofarm",4,vrab);

    cout<<"Podatoci za apteka 2:"<<endl;
    cout<<endl;
    apteki[1].pechati(farmaceft);
    apteki[1].pechati(tehnicar);
    apteki[1].pechati(pomPersonal);

    vrab[0].init("Elena",farmaceft,23000);
    vrab[1].init("Stefan",tehnicar,18000);
    vrab[2].init("Kristina",pomPersonal,12000);
    vrab[3].init("Viktorija",pomPersonal,11000);

    apteki[2].init("Betty",4,vrab);

    cout<<"Podatoci za apteka 3:"<<endl;
    cout<<endl;
    apteki[2].pechati(farmaceft);
    apteki[2].pechati(tehnicar);
    apteki[2].pechati(pomPersonal);

    apteki[0].najZahtevnaApteka(apteki,3);

    return 0;
}