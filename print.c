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
    char input[1000]; /*holding the input text stream*/
    int l=0;
    while((c = getchar())!= EOF){
        input[l] = c;
        l++;
    }/*get all the input characters*/

    int i;
    char temp[500]; /*holding a word, this buffer is reused*/
    int inword =0;
    int j = -1; /* the first index of a word, or index of any whitespace character*/
    printf("\n\n\033[35mYou typed the following words:\033[0m\n");    
    for (i=0;i<l;i++){

        if ((input[i]!='\t') && (input[i]!=' ') && (input[i]!='\n')){
	    temp[i-j-1]=input[i];
            inword = 1;

        }else{

            if (inword == 1){ /*if the current character is the first white-spcae character right to a word*/

                inword = 0;
                temp[i-j-1] = '\0'; /*set the end flag of the buffer*/
	
		for (int k=0;temp[k]!='\0';k++){
                    printf("%c",temp[k]);

                }
                printf("\n");
            }
            j = i;
        }

    }

    if (inword == 1){
        for(int k=0;k<i-j-1;k++){
            printf("%c",temp[k]);
	}
   
    }/* the if here is to make sure the last word being printed if the text stream is exit from a word not from a particular white space character*/
    printf("\n");
}
void main(){
    WordPrint();

}
