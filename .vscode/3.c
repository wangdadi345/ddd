#include<stdio.h>

int main ()
{
    int a =10;
    int b =2;
    int x=0;
    int result=0;    
    printf("请输入 x: ");
    scanf("%d",&x);
    result=b*x+a;
    printf("计算结果结果是%d。\n",result);
    return 0;

}