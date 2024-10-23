#include<stdio.h>//确认成绩
int main()
{
    int grade;
    printf("请输入：");
    scanf("%d",&grade);
    switch(grade){   //分列式
        case 100:
        printf("good");
        case 60:
        printf("pass");
        break;
        default : 
        printf("scram");
      

    }  return 0;
}