//
// Created by sfzhang 4/5/2017.
//
#include <stdio.h>
void FmtPrint(){
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

/* WordPrint prints a text stream one word per line*/
void WordPrint(){
    char c;
    char in[1000];
    int l=0;
    while((c = getchar())!= EOF){
        in[i] = c;
        l++;
    }/*get all the input characters*/

    int i;
    char temp[500]; /*holding a word*/
    int inword =0;
    int j = 1; /* the first index of a word, or index of any whitespace character*/
    for (i=0;input[i]!='\0';i++){

        if (input[i]!='\t'||input[i]!=' '||input[i]!='\n'){
            temp[i-j-1]=input[i];
            inword = 1;
        }else{
            if (inword == 1){

                inword = 0;
                temp[i-j-1] = '\0';
                for (int k=0;temp[k]!='\0';k++){
                    printf("%c",temp[k]);

                }
                printf("\n");
            }
            j = i;
        }

    }

}
void main(){
    WordPrint();

}
