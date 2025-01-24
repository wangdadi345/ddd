#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double identifymath(const char**expr);

int main(){
    char suanshu[1000];
    char math[1000];int i,n,j=-1;
    const char *expr;
     gets(suanshu);
    double result;
    expr=suanshu;
   do{
    result=identifymath(&expr);
    i=0;math[i]=result;
    i+=2;
   }while(result!=0);
   
   for(n=0;suanshu[n]!='/0';n++){
    if(suanshu[n]=='+'||suanshu[n]=='-'||suanshu[n]=='*'||suanshu[n]=='/'||suanshu[n]=='('||suanshu[n]==')')
    math[j+2]=suanshu[n];

   }
}
double identifymath(const char**expr)// 解析数字
 {
double result = 0;double i=0;
while (**expr >= '0' && **expr <= '9') {
result = result * 10 + (**expr - '0');
(*expr)++;
} 
if(**expr=='.'){(*expr)++;
while (**expr >= '0' && **expr <= '9'){
result = result * 10 + (**expr - '0');
(*expr)++;i++;
}
}result*=pow(10,-i);
if(**expr=='\0')
return 0;
return result;
}