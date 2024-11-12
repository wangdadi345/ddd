#include<stdio.h>
int sushu(int i,int number[],int count ){//用来判断素数
    int a=0;
    int ret=1;
    for(a=0;a<=count;a++){
        if(i%number[a]==0){
            ret=0;
            break;
        }
        
    }
    return ret;}


int main(void)
{
    int number[100]={2};
    int count=0,c=1,x,b;//x为未知数，count用在数组
    int i=1,d=0;
    scanf("%d",&x);
    for(i=3;i<x;i++){
        if(sushu(i,number,count)){
            count++;
            number[count]=i;
            
        }}
        for(b=0;b<=count;){
            if(x%number[b++]==0){
                printf("no\n");
                break;
            }else{
                printf("yes\n");
                break;

            }}
            for(d=0;d<count;d++){
                c++;
                if(c%5==0){
                    printf("%d\n",number[d]);
                }else
            printf("%d\t",number[count]);}
            printf("%d",x);
        }
        