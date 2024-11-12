#include<stdio.h>
int main()
{
    int count[10];//定义数组
    int i,x;
    for(i=0;i<=9;i++){
        count[i ]=0;//数组初始化
    }do{
        printf("qing");
        scanf("%d",&x);
        if(x>=0&&x<=9){//记录次数
            count[x]++;
        }
    }while(x!=-1);
    for(i=0;i<=9;i++){
        printf("%d有%d次\n",i ,count[i]);
    }
    return 0;
}