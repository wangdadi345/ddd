#include<stdio.h>//平均输
int main ()
{
    int number,i=0;//number为个数a 为数的大小 i为实际个数
    double aver=0,sum=0;
    do{
        printf("请:");
        scanf("%d",&number);
        ++i;
        sum+=number;
    }while(number!=-1);
    aver=sum/i;
    printf("结果是：%lf ,%d",aver,i);//输入－1是结束
    return 0;
    
}