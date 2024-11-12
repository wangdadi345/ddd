#include<stdio.h>
int main()
{
    int n;
    int f=1;//f为n的阶乘
    printf("请输入：");
    scanf("%d",&n);
    while(n>0){
        f=f*n; 
           n--;
    }
    printf("结果是%d",f);
    return 0;
}