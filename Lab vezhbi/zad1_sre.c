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
