// Да се напише програма која имитира поедноставена facebook апликација. Програмата
// чува податоци за вашиот профил: facebook име, град, датум на раѓање, низаа од пријатели,
// број на пријатели. Датумот на раѓање е од облик: ден, месец, година. За секој пријател
// познати се следниве информации: facebook име, датум на раѓање и порака за ѕид.
// Да се напишат функции со кои може да ги промените основните податоци за вашиот
// профил: facebook име, град и датум на раѓање.
// Да се напише функција со која прифаќате пријател и го додавате во низата од
// пријатели, но само доколку бројот на пријатели не го надминува максимално дозволениот
// број (5000 пријатели) и соодветно го менувате вашиот број на пријатели.
// Да се напише функција со која бришете пријател (според facebook име) од низата на
// пријатели и соодветно го менувате вашиот број на пријатели.
// Да се напише функција со која им честитате роденден (менувајќи го членот – порака за
// ѕид) на сите пријатели кои се родени на датумот кој се проследува како аргумент на
// функцијата.
// Да се напише главна програма која ги тестира горенаведените функции

#include<stdio.h>

typedef struct s1 {
    int den,mesec,godina;
}datum;

typedef struct s2 {
    char fbime[30];
    datum birthdate;
    char poraka[150];
}fbprijatel;

typedef struct s3 {
    char fbime[30];
    char grad[30];
    datum birthdate;
    fbprijatel lista[5000];
    int brPrijateli;
}profil;

void smeniIme(profil *f , char *nIme){
    strncpy(f->fbime,nIme,29);
    f->fbime[29]='\0';
}

void smeniGrad(profil *f , char *nGrad){
    strncpy(f->grad,nGrad,29);
    f->grad[29]='\0';
}

void smeniDatum(profil *f, datum d){
    f->birthdate=d;
}

int dodadiPrijatel(profil *f, fbprijatel p){
    int i,found=0;
    if(f->brPrijateli<5000){
        for(i=0;i<f->brPrijateli;i++){
            if(strcmp(f->lista[i].fbime,p.fbime)==0){
                found=1;
                break;
            }
        }
        if(found==0){
            f->lista[f->brPrijateli]=p;
            f->brPrijateli++;
            return 1;
        }
    }
    return 0;
}

int brishiPrijatel(profil *f, char *fbime){
    int i,poz;
    poz=-1;

    for(i=0;i<f->brPrijateli;i++){
        if(strcmp(f->lista[i].fbime,fbime)==0){
            poz=i;
            break;
        }
    }
    if(poz==-1){
        return 0;
    }

    for(i=poz;i<f->brPrijateli-1;i++){
        f->lista[i]=f->lista[i+1];
    }
    f->brPrijateli--;
    return 1;
}

void cestitajRodenden(profil *f, datum d){
    int i;
    for(i=0;i<f->brPrijateli;i++){
        if(f->lista[i].birthdate.den==d.den && f->lista[i].birthdate.mesec==d.mesec){
            strcpy(f->lista[i].poraka,"Srekjen rodenden!");
        }
    }
}

int main(){
profil f;
printf("Vnesi gi podatocite za profilot:");
scanf("%s %s %d %d %d",f.fbime,f.grad,f.birthdate.den,f.birthdate.mesec,f.birthdate.godina);
printf("Vnesi br na prijateli");
scanf("%d",f.brPrijateli);
int i;
for(i=0;i<f.brPrijateli;i++){
    scanf("%s %d %d %d",f.lista[i].fbime,&f.lista[i].birthdate.den,&f.lista[i].birthdate.mesec,&f.lista[i].birthdate.godina);
    strcpy(f.lista[i].poraka,"");
}
smeniIme(&f,"Novo ime");
fbprijatel nov;
scanf("%s %d %d %d",f.lista[i].fbime,&f.lista[i].birthdate.den,&f.lista[i].birthdate.mesec,&f.lista[i].birthdate.godina);
    strcpy(f.lista[i].poraka,"");

    return 0;
}