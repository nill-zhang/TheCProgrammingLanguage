//
// Created by sfzhang on 4/15/2017.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


void *my_strrep(const char*,unsigned);
void *my_strdup(const char*);
unsigned my_strlen(const char*);
void *my_strcpy(char *, const char *);
void *my_strcat(char *, const char *);

void *my_strrep(const char* p, unsigned num) {
    char *new = malloc(num * strlen(p) + 1);
    int i = 0;
    while (i++ < num)
        strcpy(&new[i * strlen(p)], p);
    return new;

}

void *my_strdup(const char*p){
    char *new = (char *)malloc(strlen(p)+1);
    strcpy(new,p);
    return new;

}

unsigned my_strlen(const char *p){
    unsigned i=0;
    while(p[i++]!='\0')
        ;
    return i;


}

void *my_strcpy(char *p1, const char *p2){
    p1 = realloc(p1, strlen(p2)+1);
    if (p1 == _NULL){
        p1 = malloc(strlen(p2)+1);
    }

    if (p1 ==_NULL){
        printf(strerror(errno));
        exit(EXIT_FAILURE);
    }
    // when the loop exits, *p1 == '\0'
    while ((*p1++ = *p2++) != '\0')
        ;
    return p1;


}



void *my_strcat(char *p1, const char *p2){
    printf("enter my_strcat!");
    fflush(stdout);
    printf("p1:%s\tp2:%s\n",p1,p2);
    char *new = (char *)realloc(p1,strlen(p1)+strlen(p2)+1);
    if (new == _NULL) {
        perror("realloc:");
        new = (char *) malloc(strlen(p1) + strlen(p2) + 1);
    }
    if (new == _NULL){
        perror("malloc:");
        exit(EXIT_FAILURE);
    }
    strcpy(new,p1);
    strcpy(new+strlen(p1),p2);
    free(p1);
    printf("leave my_strcat!");
    fflush(stdout);
    return new;

}

void test(void){
    char *pname = "shao";
    my_strcat(pname,"feng");
    printf("first name : %s\n",pname);
    char lastname[3];
    my_strcpy(lastname, "zhang");
    my_strcat(pname,lastname);
    printf("full name:%s,length:%d\n",pname,my_strlen(pname));
    char *stars = NULL;
    stars = my_strrep("*",50);
    printf("%s\n",stars);
    stars = my_strdup("duplicate lines");
    printf("%s\n",stars);


}

int main(){
   test();
}
// different ways to initialize strings
//strcpy
// char str[] = "s ssss";
// char *p = "sfefefe";
//
// typedef
// int numbers[5];
// int *p = numbers;
// &ints is the address of what?
// ints,p is the address of array
// rewrite page87 getline
//int *arr[5];
//for (int i=0;i<5;i++){
//    arr[i] = (int*)malloc(sizeof(int));
//    *arr[i] = i;
//}
//
// *(arr+i) = (int*)malloc(sizeof(int));
// **(arr+i) = i;
//
//int (*pArray)[3] ={{2,3,55},{3,21,98}};
//pArray is a pointer to an array of intergers, &pArray[0][0] is a pointer to an integer
//pArray[1]=*(pArray+1)=&pArray[1][0]
//pArray + 1
//*(pArray[1]+2)=*(&pArray[1][2])=*(&pArray[0][0]+1*3+2)
