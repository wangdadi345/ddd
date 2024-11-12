#include<stdio.h>

int main()
{
    int x,count,i=1,d=1,t;//x,t 为知量 count 为位数 d为所求 i为辅助 
    printf("请输入:");
    scanf("%d",&x);
    t=x;
    while(t>=10){
        t/=10;
        i*=10;
    }
    do{
        d=x/i;
        x%=i;
        i/=10;
        if(i>=10){
        printf("%d ",d );
        };//前几位有空格
         //else{
        //printf("%d",d);//最后一位无
        //}
    }while(i>0);
    return 0;
}