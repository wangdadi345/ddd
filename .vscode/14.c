#include<stdio.h>
int main()
{
    int a,b;
    printf("请输入:");//9999>=a>=1000为错误表示， 9999>=a判断结果为0&1 故a=1&0
    scanf("%d",&a);
if(9999>=a&&a>=1000){
    printf("b=4");
}
else if (999>=a&&a>=100){
    printf("b=3");
}
else if (99>=a&&a>=10){
    printf("b=2");
}
else if (9>=a&&a>=0){
    printf("b=1");
}

return 0;
}