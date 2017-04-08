//
// Created by sfzhang on 4/7/2017.
//
#include <stdio.h>
#include <string.h>
void ArrayDefault(){

    char  characters[15];
    int  numbers[15];
    float fractions[15];

    characters[3] = '3';
    numbers[3] = 3;
    fractions[3] = 3.333;
    int i;
    for (i=0;i<15;i++){
        printf("characters[%d]:%-20c\t",i,characters[i]);
        printf("numbers[%d]:   %-11d\t",i,numbers[i]);
        printf("fractions[%d]: %-4.4f\n",i,fractions[i]);
    }
}

void main(void) {
    /*uninitialized elements contain garbage values */
    ArrayDefault();
}
