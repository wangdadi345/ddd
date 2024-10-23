#include<stdio.h>
int main ()

    int number=rand()%100+1;//ruguozhijiezhong
    int a,count;
    printf("我想好了一个数1到100");
    do{
    printf("cai:");
    scanf("%d",&a);
    if(a>number){
        printf("猜大了");
        count++;
    }else if(a<number){
        count++;
        printf("猜小了");
    }while(a!=number);
    count++;//不同
    printf("猜对了，猜%d",count);

}
}