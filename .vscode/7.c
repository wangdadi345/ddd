#include<stdio.h>

int main()
{
    double inch;
    double foot;
    printf("请输入身高的英尺和英寸，" 
    "如输入\"5 7\"表示5英尺7英寸:");
    scanf("%lf %lf",&foot, &inch);        
    printf("他的身高是%f米.\n",
    ((foot+inch / 12.0)*0.3048));

    return 0;

}