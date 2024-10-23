#include<stdio.h>
int main (){
    int a,b=0;
    printf("请输入：");
    scanf("%d",&a);
    a/=10;
    ++b ;
    while(a>0){
        b++;
        a/=10;
    }
    printf("%d",b);
}
