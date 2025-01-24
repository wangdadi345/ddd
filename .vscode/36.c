#include<stdio.h>
typedef struct{
    char id[20];
    char name[20];
    float scores[3];
}Students;
int main(){

    int i;

   Students students[3];
   FILE*file=fopen("C:\\code\\.vscode\\学生调查系统.txt.txt","w+");
   if(file==NULL)
	{
		printf("Open error!\n");
		exit(0);
	}


	printf("请输入文件C统.txt.txt路径请输入3个学生的信息：\n");

    for(i=0;i<3;i++){
        scanf("%s %s %.6f %.6f %.6f",students[i].id,students[i].name,&students[i].scores[0],&students[i].scores[1],&students[i].scores[2]);
        fprintf(file,"%s %s %f %f %f\n",students[i].id,students[i].name,students[i].scores[0],students[i].scores[1],students[i].scores[2]);
    }
    rewind(file);
printf("学号 姓名 三门课成绩\n");
for(i=0;i<3;i++){
    fscanf(file,"%s %s %f %f %f",students[i].id,students[i].name,&students[i].scores[0],&students[i].scores[1],&students[i].scores[2]);
    printf("学生%d的信息为\n学号：%s;姓名：%s;语文：%f;数学：%f;英语：%f\n",i+1,students[i].id,students[i].name,students[i].scores[0],students[i].scores[1],students[i].scores[2]);
}
fclose(file);
}


