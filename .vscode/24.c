#include<stdio.h>
void cycle(int i,int n ){  //第i行共2n-1行
        int count=1;
    for(count=1;count<=2*n-1;count++){
        if(count<=n-i){
            printf(" ");
        }else if(count>n-i&&count<n+i){
            printf("*");
        }else if(count<=2*n-1&&count>=n+i){
            printf(" ");
        }
        
    }printf("\n");
}                   //确定一行


int main()
{
    int h,n,i=1;//h为菱形高度n为三角高度
    printf("h=");
    scanf("%d",&h);
    n=(h+1)/2;
    for(i=1;i<=n;i++){  //打印2n-1行
    cycle(i,n);
    }
    for(i=n-1;i>=1;i--){
        cycle(i,n);
    }
   return 0;


}