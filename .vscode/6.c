#include<stdio.h>
int main ()
{
    int a;
    int b;
    printf("请输入两个数:" );
    scanf("%d %d",&a,&b);   
    int c=a%100;
    int d=a/100;
    int e=b%60;
    int f=b/60;
    int g=(f+d)*100+(c+e);
    printf("结果是%d",g);
    return 0;
}




