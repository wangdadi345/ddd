#include<stdio.h>
int main()
{
    int x,c,i;//i是*总数  x为行数 c 为要求行数
    i=1;
    x=2;
    printf("请输入:");
    scanf("%d",&c);
    printf("*\n");
    while(x<=c){
     if(i-(x*x-2*x+1)==2*x-1){
        ++x;
        printf("\n");//换行
    }else if(i-(x*x-2*x+1)<2*x-1){
        i++;
        printf("*");//个数增加
    }
    }
    return 0;

}