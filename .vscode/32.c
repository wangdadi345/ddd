#include<stdio.h>
int main(void){
    int a[7][7]={{1}};
    int n,i;
    for(n=0;n<7;n++){
        for(i=0;i<7;i++){
            if(i==n&&n!=0)a[n][i]=1;
            else if(i==0)a[n][i]=1;
            else    a[n][i]=a[n-1][i]+a[n-1][i-1];
            
        }
    }
    for(n=0;n<7;n++){
        for(i=0;i<=n;i++){
            if(i==n&&n!=0)printf("%d\n",a[n][i]);
            else if(n==0&&i==0)printf("\n%d\n",a[n][i]);
        else printf("%d ",a[n][i]);
        }}fgets
    return 0;
}
   