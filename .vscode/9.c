#include <stdio.h>
int main ()
{
    int hour1,minute1;
    int hour2,minute2;
    printf("请输入小时与分钟");
    scanf("%d %d %d %d",&hour1,&hour2,&minute1,&minute2);
    int im=minute2-minute1;
    int ih=hour2-hour1;
    if (im<0){
        im+=60;
        ih=--ih;
    }    
    printf("%d小时 %d分钟",ih,im);
}