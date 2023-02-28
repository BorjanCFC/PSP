// da se napise programa bo koja kje se definira struktura za presmetuvanje kompleksni broevi
// potoa da se napisat funkciii za sobiranje, odzemanje i mnozenje na dva kompleksni broja
// sobiranje z1+z2=(Re1+Re2)+(im1+im2)
#include<stdio.h>
typedef struct s{
    int re, im;
}kompl;

kompl soberi(kompl a, kompl b){
    kompl r;
    r.re=a.re+b.re;
    r.im=a.im+b.im;
    return r;
}
kompl odzemi(kompl a, kompl b){
    kompl r;
    r.re=a.re-b.re;
    r.im=a.im-b.im;
    return r;
}
kompl mnozii(kompl a, kompl b){
    kompl r;
    r.re=(a.re*b.re) -(a.im*b.im); 
    r.im=(a.re*b.im) + (a.im*b.re);
    return r;
}
int main(){
kompl a,b,c;
printf("Vnesi gi kompleksnite broevi:");
scanf("%d%d",&a.re,&a.im);
scanf("%d%d",&b.re,&b.im);
c= soberi(a,b);
printf("Zbirot e %d+%d i/n",c.re,c.im);
c=odzemi(a,b);
printf("Razlikata e %d+%d i/n",c.re,c.im);
c=mnozii(a,b);
printf("Proizvodot e %d+%d i/n",c.re,c.im);

    return 0;
}