 #include<stdio.h>
 int main ()
 {   
    int cm=0;
    printf("请输入");
    scanf("%d",&cm);
    int foot=cm/30.48;
    int inch=((cm/30.48-foot)*30);
    printf("%d ",foot);
    printf("%d",inch);
    return 0;

 }