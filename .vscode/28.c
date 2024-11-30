#include<stdio.h>
#include<stdlib.h>
int main(void){
    int *p;
    int count=0;
    while((p=malloc(100*1024*1024))){
        count++;
    }
    printf("内存为%dMB\t",count);

}