#include<stdio.h>
int main(void){
   int i,j,n,number;//i,j为循环所用变量，number表示行n表列
   scanf("%d",&number);n=number;
   int a[number][n]={{1},{1,1},};
   //a[0][0]=1;a[1][0]=1;a[1][1]=1;
   for(i=2;i<=number-1;i++){
    for(j=0;j<=n-1;j++){
        if(j==i)a[i][j]=1;
        else{
        a[i][j]=a[i-1][j]+a[i-1][j-1];}
    }
   }
   for(i=0;i<number;i++){
   for(j=0;j<=i;j++){
    if(i==j){
   printf("%d\n",a[i][j]);}
   else printf("%d\t",a[i][j]);
   }
   }

   return 0;
}