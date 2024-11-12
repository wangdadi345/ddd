#include<stdio.h>
int main()
{
    int x,y,z,e,a=1;     //x,y为变量z,e为对应约数
    printf("请输入:");
    scanf("%d",&x);
    printf("请输入:");
    scanf("%d",&y);
    for(z=x;z>0;z--){
      if(0==x%z){
            e=z;       //e为约
        }
        for(a=y;a>0;a--){
            if(0==y%a&&a==e )
                printf("公约数为%d",e );     //判公约
                break;
            }
            

        }

    }
