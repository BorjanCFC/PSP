//napiste funk za presmetuvanje na rastojanie megju dve tocki
// zadadeni so nivnite koordinati.Potoa napisete programa sto kje presmeta perimetar na triagolnik
//d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))
#include<stdio.h>
#include<math.h>
typedef struct s{
int x,y;
}Tocka;

int rastojanie(Tocka t1, Tocka t2){
return sqrt(pow(t2.x-t1.x,2)+pow(t2.y-t1.y,2));
}

int main(){
int a,b,c,L;
Tocka t1,t2,t3;
printf("Vnesi gi koor na triagolnikot:\n");
scanf("%d %d",&t1.x,&t1.y);
scanf("%d %d",&t2.x,&t2.y);
scanf("%d %d",&t3.x,&t3.y);

a=rastojanie(t1,t2);
b=rastojanie(t2,t3);
c=rastojanie(t3,t1);
L=a+b+c;
if((a+b)>c && (a+c)>b && (b+c)>a){
    
}
printf("Perimetarot e %d",L);

    return 0;
}