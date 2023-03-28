// Од тастатура се читаат непознат број податоци за студенти. Податоците се внесуваат така што во
// секој ред се дава:
// - име,
// - презиме,
// - број на индекс (формат xxx/yy), и
// - четири броја (поени од секоја задача)
// со произволен број празни места или табулатори меѓу нив. Да се напише програма која ќе
// испечати список на студенти, каде во секој ред ќе има: презиме, име, број на индекс, вкупен број
// на поени од четирите задачи, сортиран според вкупниот број на поени. Имињата и презимињата
// да се напишат со голема почетна буква. 

#include<stdio.h>

typedef struct s{
    char ime[30];
    char prezime[30];
    int indeks[2];
    int poeni;
}student;

int main(){

student lista[100];
student pom;

int N,i,p1,p2,p3,p4,j;

printf("Vnesi kolku studenti ima:");
scanf("%d",&N);

for(i=0;i<N;i++){
    printf("Vnesi podatoci za studentot so rbr %d\n ",i+1);
    scanf("%s %s %d %d %d %d %d %d",lista[i].ime,lista[i].prezime,&lista[i].indeks[0],&lista[i].indeks[1],&p1,&p2,&p3,&p4);
    lista[i].poeni = p1+p2+p3+p4;
}

for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
        if(lista[j].poeni>lista[i].poeni){
            pom=lista[i];
            lista[i]=lista[j];
            lista[j]=pom;
        }
    }
}

for(i=0;i<N;i++){
    printf("%s, %s, %d/%d %d\n",lista[i].prezime,lista[i].ime,lista[i].indeks[0],lista[i].indeks[1],lista[i].poeni);
}


    return 0;
}