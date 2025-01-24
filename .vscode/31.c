 #include<stdio.h>
int main(){
    int a=1,b=0;//a是空瓶书b是喝了几瓶cd
    cycle:
    printf("请输入有几个空瓶:\n");
    scanf("%d",&a);
    while(a>0){
        if(a<2) break;
        else if(a==2)
        {
            b++;
            a=0;
            break;
        }
        a-=3;b++;a++;}
        printf("最多喝%d瓶\n",b);
        b=0;
   if(a!=0)
    goto cycle;
        
    
 


}