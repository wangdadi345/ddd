 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生结构体
typedef struct Student {
    int id;
    char name[50];
    int age;
} Student;

// 定义动态数组结构体
typedef struct DynamicArray {
    Student *students;  // 指向存储学生信息的数组
    int size;          // 当前学生数量
    int capacity;      // 数组最大容量
} DynamicArray;

// 初始化动态数组
DynamicArray* createDynamicArray(int initialCapacity) {
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (arr == NULL) {
        perror("内存分配失败");
        return NULL;
    }
    arr->capacity = initialCapacity;
    arr->students = (Student *)malloc(initialCapacity * sizeof(Student));
    if (arr->students == NULL) {
        perror("内存分配失败");
        free(arr);
        return NULL;
    }
    arr->size = 0;
    return arr;
}

// 动态扩容函数
void resizeArray(DynamicArray *arr) {
    if (arr == NULL) return;
    arr->capacity *= 2;
    Student *newStudents = (Student *)malloc(arr->capacity * sizeof(Student));
    if (newStudents == NULL) {
        perror("内存分配失败");
        return;
    }
    for (int i = 0; i < arr->size; i++) {
        newStudents[i] = arr->students[i];
    }
    free(arr->students);
    arr->students = newStudents;
}

// 添加学生信息函数
void addStudent(DynamicArray *arr) {
    if (arr == NULL) return;
    if (arr->size >= arr->capacity) {
        resizeArray(arr);
    }
    Student newStudent;
    printf("请输入学生ID：");
    scanf("%d", &newStudent.id);
    printf("请输入学生姓名：");
    scanf("%s", newStudent.name);
    printf("请输入学生年龄：");
    scanf("%d", &newStudent.age);
    arr->students[arr->size++] = newStudent;
}

// 显示所有学生信息函数
void displayStudents(DynamicArray *arr) {
    if (arr == NULL) return;
    for (int i = 0; i < arr->size; i++) {
        printf("ID: %d, 姓名: %s, 年龄: %d\n", arr->students[i].id, arr->students[i].name, arr->students[i].age);
    }
}

// 根据ID查找学生索引函数
int findStudentById(DynamicArray *arr, int id) {
    if (arr == NULL) return -1;
    for (int i = 0; i < arr->size; i++) {
        if (arr->students[i].id == id) {
            return i;
        }
    }
    return -1;
}

// 更新学生信息函数
void updateStudent(DynamicArray *arr) {
    if (arr == NULL) return;
    int id;
    printf("请输入要修改的学生ID：");
    scanf("%d", &id);
    int index = findStudentById(arr, id);
    if (index!= -1) {
        Student *student = &(arr->students[index]);
        printf("请输入新的姓名：");
        scanf("%s", student->name);
        printf("请输入新的年龄：");
        scanf("%d", &student->age);
    } else {
        printf("未找到对应ID的学生\n");
    }
}

// 删除学生信息函数
void deleteStudent(DynamicArray *arr) {
    if (arr == NULL) return;
    int id;
    printf("请输入要删除的学生ID：");
    scanf("%d", &id);
    int index = findStudentById(arr, id);
    if (index!= -1) {
        for (int i = index; i < arr->size - 1; i++) {
            arr->students[i] = arr->students[i + 1];
        }
        arr->size--;
    } else {
        printf("未找到对应ID的学生\n");
    }
}

// 将学生信息保存到文件
void saveToFile(DynamicArray *arr, const char *filename) {
    if (arr == NULL) return;
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("文件打开失败");
        return;
    }
    fwrite(&arr->size, sizeof(int), 1, fp);
    fwrite(arr->students, sizeof(Student), arr->size, fp);
    fclose(fp);
}

// 从文件中读取学生信息
DynamicArray* loadFromFile(const char *filename) {
    DynamicArray *arr = NULL;
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return createDynamicArray(5);  // 如果文件不存在，创建一个初始容量为5的动态数组
    }
    int size;
    fread(&size, sizeof(int), 1, fp);
    arr = createDynamicArray(size);
    if (arr == NULL) {
        fclose(fp);
        return NULL;
    }
    fread(arr->students, sizeof(Student), size, fp);
    arr->size = size;
    fclose(fp);
    return arr;
}

int main() {
    DynamicArray *studentsArray = loadFromFile("students.dat");
    int choice;
    do {
        printf("1. 添加学生信息\n");
        printf("2. 显示所有学生信息\n");
        printf("3. 根据ID查找学生\n");
        printf("4. 更新学生信息\n");
        printf("5. 删除学生信息\n");
        printf("6. 保存并退出\n");
        printf("请输入你的选择：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudent(studentsArray);
            break;
        case 2:
            displayStudents(studentsArray);
            break;
        case 3:
            {
                int id;
                printf("请输入要查找的学生ID：");
                scanf("%d", &id);
                int index = findStudentById(studentsArray, id);
                if (index!= -1) {
                    printf("找到学生，索引为 %d\n", index);
                } else {
                    printf("未找到对应ID的学生\n");
                }
            }
            break;
        case 4:
            updateStudent(studentsArray);
            break;
        case 5:
            deleteStudent(studentsArray);
            break;
        case 6:
            saveToFile(studentsArray, "students.dat");
            free(studentsArray->students);
            free(studentsArray);
            break;
        default:
            printf("无效的选择，请重新输入\n");
        }

    } while (choice!= 6);

    return 0;
}
