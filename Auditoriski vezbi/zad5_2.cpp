#include<iostream>
#include<string.h>

struct datum {
    int den,mesec,godina;
};

struct fbprijatel {
    char fbime[30];
    datum birthdate;
    char poraka[150];
};

struct profil {
    char fbime[30];
    char grad[30];
    datum birthdate;
    fbprijatel lista[5000];
    int brPrijateli;
};

void smeniIme(profil &f , char *nIme){
    strncpy(f.fbime,nIme,29);
    f.fbime[29]='\0';
}

void smeniGrad(profil &f , char *nGrad){
    strncpy(f.grad,nGrad,29);
    f.grad[29]='\0';
}

void smeniDatum(profil *f, datum d){
    f->birthdate=d;
}

bool dodadiPrijatel(profil &f, fbprijatel p){
    int i,found=0;
    if(f.brPrijateli<5000){
        for(i=0;i<f.brPrijateli;i++){
            if(strcmp(f.lista[i].fbime,p.fbime)==0){
                found=1;
                break;
            }
        }
        if(found==0){
            f.lista[f.brPrijateli]=p;
            f.brPrijateli++;
            return true;
        }
    }
    return false;
}

bool brishiPrijatel(profil &f, char *fbime){
    int i,poz;
    poz=-1;

    for(i=0;i<f.brPrijateli;i++){
        if(strcmp(f.lista[i].fbime,fbime)==0){
            poz=i;
            break;
        }
    }
    if(poz==-1){
        return false;
    }

    for(i=poz;i<f.brPrijateli-1;i++){
        f.lista[i]=f.lista[i+1];
    }
    f.brPrijateli--;
    return true;
}

void cestitajRodenden(profil &f, datum d){
    int i;
    for(i=0;i<f.brPrijateli;i++){
        if(f.lista[i].birthdate.den==d.den && f.lista[i].birthdate.mesec==d.mesec){
            strcpy(f.lista[i].poraka,"Srekjen rodenden!");
        }
    }
}

int main(){



    return 0;
}