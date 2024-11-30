//未删除的用户deleted数组对应引索都为0；删除的为他的引索值
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{//声明学生信息结构体
    int id;int year;char name[10];
}student;

typedef struct DynamicArry{//声明动态数组（系统）
//储存学生信息
    student*students;int size;  int capacity;  int *deleted;//用来记录删除用户
}DynamicArry;
DynamicArry*arry;
//创建系统
void dongzu(int length,DynamicArry*arry){
    // DynamicArry*arry;
    //  arry=(DynamicArry*)malloc(sizeof(DynamicArry));//动态数组  系统申请空间
    // if(arry==NULL){
    //     perror("分配错误");
    //     return NULL;
    // }
    arry->capacity=length;
    arry->size=0;
    arry->students=(student*)malloc(sizeof(student)*arry->capacity);//为储存信息的结构体申请空间
    if(arry->students == NULL){
        perror("空间不足");
       // free(arry);
        return ;
    }
    arry->deleted=(int* )calloc(arry->capacity,sizeof(int));//为储存了删除的用户信息的数组申请空间
    if(arry->deleted==NULL){
        perror("空间不足");
      //  free(arry);
        return ;}

    // return arry;
}

//扩大储存空间
void expand(DynamicArry*arry){//函数
    
    
    arry->capacity*=2;
    student*newstudents=(student*)malloc(arry->capacity*sizeof(student));
    if( newstudents==NULL ){
        perror("空间不足");
        return;}
        int i;for(i=0;i<arry->size;i++){
            newstudents[i]=arry->students[i];//将储存信息传递到新的结构体中
          
        }
    //students没用了不能让他空站着内存
    arry->students=newstudents;//替换
   // free(arry->students);
    return;
}

//输入学生信息************
void addStudent(DynamicArry*arry)//    需要返还地址么
{
    int n,i=0, Year,Id;char Name[10];
    
   // DynamicArry*arry;
    if(arry->capacity<=arry->size){
        expand(arry);
        
    }
    for(n=0;n<arry->capacity;n++){//当有删除用户时先用此用户的空间
    if(arry->deleted[n]!=0){
        printf("请输入姓名，id，年龄：");
    scanf("%s,%d,%d",Name,&Id,&Year);
    strcpy(arry->students[n].name,Name);
    arry->students[n].id=Id;
    arry->students[n].year=Year;
    arry->size+=1;
    arry->deleted[n]=0;
    break;
    
    FILE*file=fopen("\\code\\.vscode\\学生调查系统.txt","w");
    for(i=0;i<arry->size;i++){
    if(i==n)
    fprintf(file,"%d,%d,%s\n",arry->students[n].id,arry->students[n]. year,arry->students[n]. name);
    else
    fprintf(file,"%d,%d,%s\n",arry->students[i].id,arry->students[i]. year,arry->students[i]. name);
    }
    fclose(file);
    return ;}
    }
    printf("请输入姓名，id，年龄：");
    scanf("%s,%d,%d",Name,&Id,&Year);
    strcpy(arry->students[arry->size].name,Name);
    arry->students[arry->size].id=Id;
    arry->students[arry->size]. year=Year;
    arry->size+=1;
    FILE*file=fopen("\\code\\.vscode\\学生调查系统.txt","a");
    fprintf(file,"%d,%d,%s\n",arry->students[arry->size].id,arry->students[arry->size]. year,arry->students[arry->size].name);
    fclose(file);
    return ;}


//打印储存学生信息
void displayStudents(DynamicArry*arry){
         int i,inhual=-1;
        
     ;for(i=0;i<arry->size;i++){
    printf("%s,%d,%d",arry->students[i].id,arry->students[i].year,arry->students[i].name);}
    return ;
}

//查询学生信息（此处需tiqin）
int findStudentByld(int Id){
    int i,inhual=-1;
    DynamicArry*arry;
    for(i=0;i<arry->size;i++){
        if(Id==arry->students[i].id)
        inhual=i;
    }
    return inhual;
}
 
//更新学生信息,找不到返回-1
int updateStudent(int Id,DynamicArry*arry){
    int Year,n,i;
    
    char Name[10];
    for(n=0;n<arry->size;n++){
        if(Id==arry->students[n].id){
            printf("请输入名字与年龄");
            scanf("%s,%d",arry->students[n].name,arry->students[n].year);
            
           FILE*file=fopen("\\code\\.vscode\\学生调查系统.txt","w");//file
           for(i=0;i<arry->size;i++){
           if(i==n)fprintf(file,"%d,%d,%s\n",arry->students[n]. id,arry->students[n]. year,arry->students[n].name);
           fprintf(file,"%d,%d,%s\n",arry->students[i].id,arry->students[i]. year,arry->students[i]. name);
    }fclose(file); 
    return 1;
    }
            }
        
    return -1;
}

//删除学生信息，找不到返回-1************目前不可用deleted未录入文件中
int deleteStudents(int Id,DynamicArry*arry){
    int n,i;
    //i=findStudentByld(int Id);
    for(n=0;n<arry->size;n++){
        if(Id==arry->students[n].id){
            arry->students[n].id=0;
            arry->students[n].year=0;
           strcpy( arry->students[n].name,"");
            arry->size--;
            arry->deleted[n]=n;//记录删除的用户
            
            FILE*file=fopen("\\code\\.vscode\\学生调查系统.txt","w");//file
           for(i=0;i<arry->size;i++){
           if(i==n)
           fprintf(file,"%d,%d,%s\n",0,0,0);
           fprintf(file,"%d,%d,%s\n",arry->students[i].id,arry->students[i].year,arry->students[i].name);
            
        }fclose(file); 
        return 1;
    }
    }
    return -1;
}

//读取文件
void readfile(student*students,DynamicArry*arry){
    int i=-1,n=0;
    
    FILE*file=fopen("\\code\\.vscode\\学生调查系统.txt","r");
     while((fscanf(file,"%d,%d,%s",&(arry-> students[n].id),&(arry->students[n].year),(arry->students[n].name))!=-1));
     {   i++;
        n++;}
    arry->size=i;
     fclose(file);
     
}
int main(){
    int a,b=100,id;
     arry=(DynamicArry*)malloc(sizeof(DynamicArry));//动态数组  系统申请空间
    if(arry==NULL){
        perror("分配错误");
        return 0;
    }
    dongzu(b,arry);//创建系统
    // DynamicArry*arry;
    readfile(arry->students,arry);//读文件
    cycle:
    printf("你好请选择服务1:注册账号，2：更新信息，3：删除信息4：根据Id找人。\n");
    scanf("%d",&a);
    switch(a){
        case 1:
        addStudent(arry);
        break;
        case 2:
        printf("请输入id");
        scanf("%d",id);
        updateStudent(id,arry);
        break;
        case 3:
        printf("请输入id");
        scanf("%d",id);
        deleteStudents(id,arry);
        break;
        case 4:
        printf("请输入id");
        scanf("%d",id);
        findStudentByld(id);
        break;
    }
    if(a>=4){
    printf("输入错误请重新输入");
    goto cycle;

    }
    free(arry );free(arry->students);free(arry->deleted);
    printf("感谢你的应用");
}

