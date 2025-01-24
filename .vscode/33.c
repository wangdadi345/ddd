 #include<stdio.h>
#include<stdlib.h>
typedef struct cow{
  int year;
  int oldcow;
  int littlecow[0];//括号里代表年龄
}cow;
void birthcow(cow*p,int year1);
int main(){
  int year2;
  do{
  int n,i,a;
   cow*p;  
  printf("请输入第几年\n");
  scanf("%d",&a);
    p=(cow*)malloc(sizeof(cow)+a*4);
    if(p==NULL){
     perror("出错啦");
    }
  
 for(i=0;i<a;i++){
  p->littlecow[i]=0;
  
 }
  p->oldcow=1;
  p->year=a;
  year2=p->year;
  birthcow(p,0);
  n=1;
  for(i=0;i<a-1;i++){
    
    n+=p->littlecow[i];
  }
    
  printf("22222第%d年共有%d头牛\n",a,n);
   free(p);
}while(year2!=0);

}
//生小牛函数
void birthcow(cow*p,int year1){
if(year1>=3){
  p->oldcow+=p->littlecow[year1-3];
}
p->littlecow[year1]=p->oldcow;

year1++;

if(year1<=p->year)
birthcow(p,year1);

}