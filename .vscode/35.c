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
void dongzu(int length){
    
    arry->capacity=length;
    arry->size=0;
   
    
}

//扩大储存空间
   void expand(){//函数
    
    
      arry->capacity*=2;
     student*newstudents=(student*)malloc(arry->capacity*sizeof(student));
     if( newstudents==NULL ){
         perror("空间不足");
         return;}
         int i;for(i=0;i<arry->size;i++){
             newstudents[i]=arry->students[i];//将储存信息传递到新的结构体中
          
         }   free(arry->students);
     //students没用了不能让他空站着内存
     arry->students=newstudents;//替换
       return;
 }

//输入学生信息************
void addStudent()//    需要返还地址么
{
    int n, Year,Id;char Name[10];
    
    
     if(arry->capacity<=arry->size)
         expand();
    for(n=0;n<arry->capacity;n++){//当有删除用户时先用此用户的空间
    if(arry->deleted[n]!=0){
        printf("请输入姓名，id，年龄：");
    scanf("%s %d %d",Name,&Id,&Year);
    strcpy(arry->students[n].name,Name);
    arry->students[n].id=Id;
    arry->students[n].year=Year;
    arry->size+=1;
    arry->deleted[n]=0;
    return ;
    }
    }
    printf("请输入姓名，id，年龄：");
    scanf("%s %d %d",Name,&Id,&Year);
    strcpy(arry->students[arry->size].name,Name);
    arry->students[arry->size].id=Id;
    arry->students[arry->size]. year=Year;
    arry->size+=1;
  
    return ;}


//打印储存学生信息
void displayStudents(){
         int i;
        
     for(i=0;i<arry->size;i++){
    printf("%s,%d,%d",arry->students[i].id,arry->students[i].year,arry->students[i].name);}
    return ;
}

//根据id找学生信息
int findStudentByld(int Id){
    int i,inhual=-1;
    
    for(i=0;i<arry->size;i++){
        if(Id==arry->students[i].id)
        inhual=i;
    }
    return inhual;
}
 
//更新学生信息
int updateStudent(int Id){
    int Year,n,i;
    
    char Name[10];
    for(n=0;n<arry->size;n++){
        if(Id==arry->students[n].id){
            printf("请输入名字与年龄");
            scanf("%s %d",arry->students[n].name,&(arry->students[n].year));
    
    return 1;
    }
            }
        
    return -1;
}

//删除学生信息，找不到返回-1************目前不可用deleted未录入文件中
int deleteStudents(int Id){
    int n,i;
    //i=findStudentByld(int Id);
    for(n=0;n<arry->size;n++){
        if(Id==arry->students[n].id){
            arry->students[n].id=0;
            arry->students[n].year=0;
           strcpy( arry->students[n].name,"");
            arry->size--;
            arry->deleted[n]=n;//记录删除的用户
            
       
        return 1;
    }
    }
    return -1;
}

//读取文件
void readfile(){

    int n=0;
    
    FILE*file=fopen("\\code\\.vscode\\.txt.txt","r");
   //  while((fscanf(file,"%d %d %9s",(arry-> students[n].id),(arry->students[n].year),(arry->students[n].name))==3))
     while((fscanf(file, "%d %d %9s", &(arry->students[n].id),&(arry->students[n].year),(arry->students[n].name)) == 3)&&n<=arry->capacity) {
    n++;
}
    //  {
    //     n++;}

    arry->size=n;
     fclose(file);
     }
//保存信息
void SaveFile(){
    int n,i;
    
    FILE*file1=fopen("\\code\\.vscode\\学生调查系统.txt.txt","w");
    for(n=0;n<arry->size;n++){
        fprintf(file1,"%d %d %9s",(arry-> students[n].id),(arry->students[n].year),(arry->students[n].name));
    }
    fclose(file1);
    

}     

int main(){
     readfile();//读文件
    int a,b=1,id;
    arry=(DynamicArry*)malloc(sizeof(DynamicArry));//动态数组  系统申请空间
          if(arry==NULL){
            
          perror("分配错误");
          return 0;
    }
    arry->students=(student*)malloc(sizeof(student)*(arry->size+1));//为储存信息的结构体申请空间
    if(arry->students == NULL){
        
        printf("%s2111\n",strerror(errno));
        return 0;
    }
     arry->deleted=(int* )calloc(arry->size,sizeof(int));//为储存了删除的用户信息的数组申请空间
    if(arry->deleted==NULL){
        perror("空间不足2");
        return 0;
    }
    dongzu(b);//创建系统
    
   
    cycle:
    printf("你好请选择服务1:注册账号，2：更新信息，3：删除信息4：根据Id找人，5：保存操作。\n");
    scanf("%d",&a);
    switch(a){
        case 1:
        addStudent();
        break;
        case 2:
        printf("请输入id");
        scanf("%d",id);
        updateStudent(id);
        break;
        case 3:
        printf("请输入id");
        scanf("%d",id);
        deleteStudents(id);
        break;
        case 4:
        printf("请输入id");
        scanf("%d",id);
        findStudentByld(id);
        break;
        case 5:
        SaveFile();
        break;}
    if(a<5&&a>0)goto cycle;
   else if(a==5) printf("感谢你的应用");
    else if(a>5||a<=0){printf("输入错误请重新输入");
    goto cycle;}

    
     free(arry->students);
     free(arry->deleted);
    free(arry);
    arry=NULL;
    return 0;
   
}

