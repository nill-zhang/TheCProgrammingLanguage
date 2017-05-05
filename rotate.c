//
// Created by Admin on 5/4/2017.
//
#include <stdio.h>
#include <string.h>


void rotate(char *p, int shift, int len);
void reverse(char *p, int s);

void rotate(char *p, int shift, int len) {
    if (shift < 0) {                   /* left rotate by shift spots*/
        reverse(p, -shift);
        reverse(p - shift, len + shift);
        reverse(p, len);

    } else {
        reverse(p, len - shift);       /* right ratate by shift spots*/
        reverse(p + len - shift, shift);
        reverse(p, len);

    }
}
void reverse(char *p, int s){
    int i, temp;
    for(i = 0; i <= ((s-1)/2); i++){  /* don't miss out the equal sign*/
        temp = p[i];
        p[i] = p[s-1-i];
        p[s-1-i] = temp;
    }
}

void rotate_test(){
    char name[] ="sfzhang is a good guy";
    rotate(name, -3, strlen(name));
    printf("rotate left by 3 spots: %s\n",name);
    rotate(name, 3, strlen(name));
    printf("rotate right by 3 spots: %s\n",name);
}


int main(){

    rotate_test();
}