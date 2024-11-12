#include<stdio.h>
int main()
{
    int number ,count=0,a ;//100以内
    scanf("%d",&number);
    do{
        printf("请输入:");
        scanf("%d",&a);
        if(a>=number){
            printf("你大了");
        }else if (a<=number){
            printf("小了");
        }
    }while(a!=number);
    printf("对了");
    return 0;
}
