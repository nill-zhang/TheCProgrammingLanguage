//
// Created by Admin on 4/5/2017.
//
#include <stdio.h>

void main(){
    char c;
    int i;
    char name[];
    float f;
    c = ' ';
    i = 256;
    name = "sfzhang";
    f = 1.3244521;
    printf("single character: %c\n",c);
    printf("single character: %d\n",c);
    printf("decimal: %d\n",i);
    printf("Octal: %o\n",i);
    printf("Hex: %x\n",i);
    printf("Float: %3.f\n",f);
    printf("Integer: %-3d\t%-3d\n",i,i);
    printf("Character Constant: %s\n",name);
}
