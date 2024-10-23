#include <stdio.h>
int main()
{
    int price,piaomian,money;
    printf("请输入price和piaomian");
    scanf("%d %d",&price,&piaomian);
    money=piaomian-price;

    if(piaomian>=price){
        printf("找你%d",money);
    }else{
        printf("你的钱不够");
    }



}