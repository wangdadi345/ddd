#include<stdio.h>

int main()
{
    int a;
    int b;
    int c;
    float bmi=0.00;
    printf("请输入身高和体重");
    scanf("%d %d",&a,&b);
    c = (float)a*(float)a/10000;
    bmi = (float)b/(float)c*1000/1000;
    printf("你的BMI是: %.2f\n",bmi);
    return 0;

}