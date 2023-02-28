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