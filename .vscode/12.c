#include<stdio.h>
int main()
{
    int a,b,c,max ;
    printf("A B C的大小：");//懒得改了
    scanf("%d %d %d",&a,&b,&c);
    if(a>=b&&a>=c)
    {
        printf("max 为%d",a);
    }
    else if (b>=a&&b>=c);
    {
        printf("max 为%d",b );
    }
    else (c>=a&&b<=c) {
        printf("max 为%d",c);
    }
    


}
