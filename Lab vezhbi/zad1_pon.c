// За организација на работата на еден синџир со аптеки им треба програма за распределба на
// лекови по аптеки. За таа цел треба да се направаат две структури: структура за лек и структура за
// аптека. За секој лек се знае името на лекот и број на пакувања. За секоја аптека се знае име на
// аптеката, бројот на лекови и лековите во аптеката (низа од променливи од тип структура лек).

// Да се напише функција dostava која како влезни аргументи ќе прима низа од променливи
// од тип лек, должина на низата со лекови и покажувач кон променлива од тип аптека. Функцијата
// ја ажурира низата со лекови во аптеката со помош на влезната низа од лекови, така што доколку
// некој лек од влезната низа веќе постои во аптеката, се зголемува само неговата количина за
// количината која ја има во влезната низа кај соодветниот лек, доколку лекот го нема во аптеката,
// тој се додава на крај од низата со лекови во аптеката.

// Да се напише фукција popis која како влезен аргумент ќе прима променлива од тип аптека
// и ќе ги испечати сите податоци за дадена аптека.

// Да се напише главна програма во која ќе се иницијализираат две низи со лекови и една
// аптека. Потоа со функцијата dostava ќе се дополни аптеката со лековите од двете низи (со две
// повикувања на таа функција). На крај да се повика функцијата popis за соодветната аптека.

#include<stdio.h>
#include<string.h>

typedef struct s1{
    char ime[30];
    int brPakuvanja;
}lek;

typedef struct s2{
    char ime[30];
    int brLekovi;
    lek lekovi[20];
}apteka;

void dostava(lek niza[], int N, apteka *c){
    int i,j;
    int p=0;
    for(i=0;i<N;i++){
        for(j=0;j<c->brLekovi;j++){
            if(strcmp(niza[i].ime,c->lekovi[j].ime)==0){
                p=1;
                c->lekovi[j].brPakuvanja+=niza[i].brPakuvanja;
                break;
            }
        }
        if(!p){
            strcpy(c->lekovi[j].ime,niza[i].ime);
            c->lekovi[j].brPakuvanja=niza[i].brPakuvanja;
            c->brLekovi++;
        }
    }
}

void popis(apteka c){
    printf("Ime %s i broj na lekovi %d\n",c.ime,c.brLekovi);
    for(int i=0; i<c.brLekovi;i++){
        printf("\nIme na lekot %s i br na pakuvanja %d",c.lekovi[i].ime,c.lekovi[i].brPakuvanja);
    }
}
int main(){
    lek niza1[3]={{"Paracetamol",10},{"Aspirin",20},{"Dijazepam",5}};
    lek niza2[2]={{"Paracetamol",5},{"Analgin",15}};
    apteka apt={"Zegin",0};
    
    dostava(niza1,3,&apt);
    dostava(niza2,2,&apt);
    popis(apt);
    
    return 0;
}

