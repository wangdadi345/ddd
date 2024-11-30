#include<stdio.h>
int main(void){
    int a,b,c;
    int *p1=NULL,*p2=NULL,*p3=NULL ;
    scanf("%d %d %d",&a,&b,&c);
    //*p1=&a;*p2=b;*p3=c;
    p1=&a;
    if(a>=b)
    p2=&b;else p1=&b;p2=&a;
    if(c>*p1)printf("%d>%d>%d",c,*p1,*p2);
     else if(c<*p2)printf("%d>%d>%d",*p1,*p2,c);
     else printf("%d>%d>%d",*p1,c,*p2);
     return 0;
}