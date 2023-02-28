#include<stdio.h>
#include<string.h>
typedef struct s{
    char ime[10];
    char prezime[15];
    int b1,b2;
}student;

int main(){
FILE *fp1, *fp2;
student lista[100];
int N,i,j;
student pom;
fp1=fopen("Podatoci.txt","r");
if(fp1==NULL){
    printf("Ne moze da se otvori!");
    return 0;
}
fp2=fopen("Polozhile.txt","w");
if(fp2==NULL){
    printf("Ne moze da se otvori!");
    return 0;
}
N=0;
while(fscanf(fp1,"%15s %10s %4d %4d ",lista[N].prezime,lista[N].ime,&lista[N].b1,&lista[N].b2)){
if(eof(fp1)){
    break;
}
N++;
}
for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
        if(lista[j].b1+lista[j].b2>lista[i].b1+lista[i].b2){
            pom=lista[i];
            lista[i]=lista[j];
            lista[j]=pom;
        }
    }
}
for(i=0;i<N;i++){
if(lista[i].b1>=30&&lista[i].b2>=30&&(lista[i].b1+lista[i].b2>=100)){
    fprintf(fp2,"%15s%10s%4d",lista[i].prezime,lista[i].ime,lista[i].b1+lista[i].b2);
}
}
fclose(fp1);
fclose(fp2);
    return 0;
}