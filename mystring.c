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

    unsigned lenp = strlen(p);
    char *new = malloc(num * lenp + 1);
    int i = 0;

    while (i < num) {
        char *tempNew = &new[(i++) * lenp];
        const char *tempP = p;
        while ((*tempNew++ = *tempP++) != '\n');
    }
        //strcpy(&new[(i++) * strlen(p)], p);
    return new;

}

void *my_strdup(const char*p){
    char *new = (char *)malloc(strlen(p)+1);
    //strcpy(new,p);
    char *temp=new;
    while((*temp++ = *p++) != '\0');
    return new;

}

unsigned my_strlen(const char *p){
    unsigned i=0;
    while(p[i++]!='\0')
        ;
    return i-1;


}

void *my_strcpy(char *p1, const char *p2){
    char *temp = p1;
    if (my_strlen(temp) >= my_strlen(p2)){
        while((*temp++ = *p2++) != '\0');
        return p1;
    }

    p1 = realloc(p1, strlen(p2)+1);
    if (p1 == _NULL){
        p1 = malloc(strlen(p2)+1);
    }

    if (p1 ==_NULL){
        printf(strerror(errno));
        exit(EXIT_FAILURE);
    }
    // when the loop exits, *p1 == '\0'
    while ((*temp++ = *p2++) != '\0')
        ;
    return p1;


}



void *my_strcat(char *p1, const char *p2) {
    // new pointer will points to the same address as p1
    char *new = (char *) realloc(p1, strlen(p1) + strlen(p2) + 1);
    if (new == _NULL) {
        perror("realloc:");
        new = (char *) malloc(strlen(p1) + strlen(p2) + 1);
    }
    if (new == _NULL) {
        perror("malloc:");
        exit(EXIT_FAILURE);
    }
    // why I use a temp pointer?
    // because I will shift pointer positions, if you use
    // new, it will point to its tail after being shifted many steps
    // before you return it, check
    // the following that print out of p1
    char *temp = new;
    while ((*temp++ = *p1++) != '\0');
    temp--;
    while ((*temp++ = *p2++) != '\0');
    //strcpy(new, p1);
    //strcpy(new + strlen(p1),p2);
    // don't bother to free p1, because new may be allocated right after p1 instead of starting
    // from a new block
    // free(p1)


    // p1 is just a copy of firstname
    // when you change p1, firstname will not be changed
    // new could point to the same address as firstname as long as the allocation don't
    // start at a new location, so when you print firstname outside, it may still point
    // to shao, not the newly concatenated shaofeng!
    // p1 = new;
    printf("p1: %s\n",p1);
    return new;

}

void test(void){
    char *firstname = (char *)malloc(5);
    strcpy(firstname, "shao");
    my_strcat(firstname,"feng");
    printf("first name: %p,%s\n",firstname,firstname);
    char lastname[3];
    my_strcpy(lastname, "zhang");
    my_strcat(firstname,lastname);
    printf("full name:%s,length:%d\n",firstname,my_strlen(firstname));
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
