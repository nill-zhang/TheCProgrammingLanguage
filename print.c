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


void GetInput(char in[]){
    char c;
    int l=0;
    while((c = getchar())!= EOF){
        in[l] = c;
        l++;
    }/*get all the input characters*/
}


/* CharacterFrequecnyPrint prints histogram on based on each characeter's frequency in a text stream */
void CharacterFrequencyPrint(){
    char input[2000];
    int freq[128]; /* freq holds each one of the 128 ascii character's frequency count*/
    GetInput(input);
    for(int i=0;i<128;i++){
        freq[i] = 0;
    
    }/* this step is necessary, default values is random in all uninitalized array elements*/

    for(int i=0;input[i]!='\0';i++){
        freq[input[i]]++;
    
    }

    for(int j=0;j<128;j++){
        if (freq[j] != '\0'){
	      printf("%c:\t",j);
              for(int k=0;k<freq[j];k++)
	         printf("*");
	      printf("\n");
	}
    }
}







/* LonglinePrint prints lines with over 80 characters from a text stream*/
void LonglinePrint(){
    char input[2000];
    GetInput(input);
    int j,k;
    int start = 0;  /*start is the index of the first character of a newline*/
    printf("\033[31mLong lines:\033[0m\n");
    for(j=0;input[j]!='\0';j++){
        if (input[j] == '\n'){
            if ((j - start) >=80){
                for(k=start;k<=j;k++){ /* uses input[j] as line separator*/
                    printf("%c",input[k]);
                }
            }
            start = j+1;
        }

    }
    if ((j - start) >=80){
        for(k=start;k<j;k++){
            printf("%c",input[k]);
        }
    }/* Count in the line ends with EOF*/

    printf("\n");
}

/* WordPrint prints a text stream one word per line*/
void WordPrint(){

    int i;
    char input[1000];
    GetInput(input);
    char temp[500]; /*holding a word, this buffer is reused*/
    int inword =0;
    int j = -1; /* the first index of a word, or index of any whitespace character*/
    printf("\n\n\033[35mYou typed the following words:\033[0m\n");    
    for (i=0;input[i] != '\0';i++){

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
    //WordPrint();
    //LonglinePrint();
    CharacterFrequencyPrint();
}
