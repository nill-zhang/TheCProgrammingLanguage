//
// Created by Admin on 4/5/2017.
//
#include <stdio.h>

void main(){
    char c;
    int age;
    int a;
    char name[100];
    float f;
    c = '&';
    age = 256;
    for (int i=65;i<=75;i++){
        name[i-65] = i;

    }
    f = 1.324452;
    a = 98;
    printf("single character: %c\n",c);
    printf("single  character: %c\n",a);
    printf("single character: %d\n",c);
    printf("decimal(age): %d\n",age);
    printf("Octal(age): %o\n",age);
    printf("Hex(age): %x\n",age);
    printf("Float: %3.f\n",f);               /* ignore fraction part*/
    printf("Float: %3.2f\n",f);
    printf("Float: %0.2f%%\n",f*100);        /*keep 2 digits after decimal point */
    printf("Integer: %-8d\t%-8d\n",age,age); /*left alignment*/
    printf("Integer: %08d\t%08d\n",age,age); /*right alignment padded with 0s*/
    printf("Character Constant: %s\n",name);
}
