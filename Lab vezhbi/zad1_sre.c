// За организација на една онлајн сесија, на факултетот му е потребна програма за распределба
// на студентите по Zoom сесии. За таа цел треба да се направаат две структури: структура за студент
// и структура за Zoom сесија. За секој студент се знае број на индекс и име на предметот што ќе го
// полага. За секоја Zoom сесија се знае ID, лозинка, број на студенти (максималниот број на студенти
// е 7) и студентите во училницата (низа од променливи од тип структура студент).

// Да се напише функција која како влезни аргументи ќе прима низа од променлива од тип
// студент, два цели броја кои се редни броеви на двајца студенти и променлива од тип Zoom сесија.
// Функцијата ја пополнува низата од тип студент во променливата Zoom сесија со студентите со
// редни броеви помеѓу првиот и вториот реден број (вклучувајќи ги и самите нив) кои биле дадени
// како влезни аргументи.

// Да се напише функција која ќе прима три променливи: низа од Zoom сесии, должина на
// низата и име на предмет. Функцијата треба да ги печати имињата на студентите што ќе го полагаат
// предметот независно во која Zoom сесија се распределени.

// Во главната програма да се изврши иницијализирање на една низа со 10 студентите и да се
// креираат две Zoom сесии. Потоа со употреба на напишаните функции, да се пополнат двете Zoom
// сесиии каде студентите ќе полагат ПСП и Математика 2 и да се испечатат имињата на студентите
// кои ќе полагаат ПСП.

#include<stdio.h>
#include<string.h>

typedef struct s1{
    char imePredmet[30];
    int brIndeks;
}student;

typedef struct s2{
    int id;
    char lozinka[30];
    int brStudenti;
    student studenti[7];
}zoomSesija;

void f(student studenti[], int prvIndeks, int vtorIndeks, zoomSesija *sesija) {
    int i;
    for(i=prvIndeks;i<=vtorIndeks;i++){
        sesija->studenti[sesija->brStudenti]=studenti[i];
        sesija->brStudenti++;
        if(sesija->brStudenti>=7){
            printf("Greshka!\n");
            break;
        }
    }
}

void pechati(zoomSesija sesija[], int brSesii, char predmet[]) {
    int i, j;
    for(i=0;i<brSesii;i++){
        for(j=0;j<sesija[i].brStudenti;j++) {
            if(strcmp(sesija[i].studenti[j].imePredmet, predmet) == 0) {
                printf("%d %s\n", sesija[i].studenti[j].brIndeks, sesija[i].studenti[j].imePredmet);
            }
        }
    }
}

int main() {
student studenti[10]={{"PSP",120},{"Matematika 2",47},{"PSP",178},{"Matematika 2",106},{"PSP",23},{"Matematika 2",56},{"PSP",34}, {"Matematika 2",143}, {"PSP",221}, {"Matematika 2",123}};
zoomSesija sesija1={1, "psp123", 0};
zoomSesija sesija2={2, "mat2abc", 0};

f(studenti, 0, 4, &sesija1); 
f(studenti, 5, 9, &sesija2); 

printf("Studenti koi polagaat PSP: \n");
pechati(&sesija1, 1, "PSP"); 

printf("Studenti koi polagaat Matematika2: \n");
pechati(&sesija2,1,"Matematika2");

return 0;
}