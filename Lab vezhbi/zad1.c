// Задача 1:
// На една компанија и е потребна програма за ланци на познати ресторани. За таа цел треба да се
// направат две структури: структура за ланец и структура за ресторан. За секој ланец се знае името,
// бројот на ресторани и низа од променливи од тип структура ресторан (во низата има максимум
// 10 променливи). За секој ресторан се знае името, локацијата и бројот на вработени.

// Да се напише функција која ќе прима променлива од тип ланец и број на вработени како
// аргументи, а ќе ги испечати името и локацијата на секој ресторан, во ланецот, кој има помал број
// на вработени од дадениот аргумент.

// Во главната програма да се овозможи внесување на информациите потребни за креирање на два
// ланци и внесување на рестораните во секој ланец. Со употреба на веќе напишаната функција, да
// се испечатат имињата и локациите рестораните кои имаат помалку од 3 вработени, без разлика на
// ланецот во кој се вклучени (функцијата да се повика за двата ланци). 
#include <stdio.h>

typedef struct s1{
    char ime[30];
    char lokacija[50];
    int brVraboteni;
}restoran;

typedef struct s2{
    char ime[30];
    int brRestorani;
    restoran restorani[10];
}lanec;

void f(lanec *c, int vraboteni){
    int i;
    for(i=0;i<c->brRestorani;i++){
        if(c->restorani[i].brVraboteni<vraboteni) {
            printf("Restoran: %s\n", c->restorani[i].ime);
            printf("Lokacija: %s\n", c->restorani[i].lokacija);
        }
        printf("\n");
    }
}

int main(){
    lanec lanec1, lanec2;
    int i;
    
    printf("Vnesi ime i broj na restorani za lanec 1:\n");
    scanf("%s %d",lanec1.ime,&lanec1.brRestorani);
    for(i=0;i<lanec1.brRestorani;i++){
        printf("Vnesi ime na restoranot,lokacija i broj na vraboteni\n");
        scanf("%s %s %d",lanec1.restorani[i].ime,lanec1.restorani[i].lokacija,&lanec1.restorani[i].brVraboteni);
    }
    
    printf("\n");
    
    printf("Vnesi ime i broj na restorani za lanec 2:\n");
    scanf("%s %d",lanec2.ime,&lanec2.brRestorani);
    for(i=0;i<lanec2.brRestorani;i++){
        printf("Vnesi ime na restoranot,lokacija i broj na vraboteni\n");
        scanf("%s %s %d",lanec2.restorani[i].ime,lanec2.restorani[i].lokacija,&lanec2.restorani[i].brVraboteni);
    }
    
    printf("\n");

    printf("Restorani so pomalku od 3 vraboteni vo lanec 1:\n");
    f(&lanec1,3);
    printf("Restorani so pomalku od 3 vraboteni vo lanec 2:\n");
    f(&lanec2,3);
    
    return 0;
}
