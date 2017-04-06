//
// Created by sfzhang on 4/6/2017.
//
#include <stdio.h>


void count(){
    int ntab,nbackspace,nblank,nline,nword,ncharacter;
    ntab=nbackspace=nblank=nline=nword=ncharacter=0;
    char c;
    char input[2000];
    int inword = 0;
    for (int i=0; (c = getchar()) != EOF; i++){
        input[i] = c;
        switch (c)
            {
                case '\t':
                    ntab++;
                    if (inword == 1){ /* if inword is 1, it means it was in an word, now it gets out of that word
                                         a word has past by*/

                        nword++;
                    }
                    inword = 0;
                    break;


                case '\b':
                    nbackspace++;
                    if (inword == 1){

                        nword++;
                    }
                    inword = 0;
                    break;

                case '\n':
                    nline++;
                    if (inword == 1){

                        nword++;
                    }
                    inword = 0;
                    break;

                case ' ':
                    nblank++;
                    if (inword == 1){

                        nword++;
                    }
                    inword = 0;
                    break;

                default:
                    ncharacter++;
                    inword = 1;
            }
    }
    printf("nTabs\tnBackSpaces\tnBlanks\tnCharacters\tnWords\tnLines\n");
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",ntab,nbackspace,nblank,ncharacter,nword,nline);
    printf("Original Input: %s\n",input);
}

void main() {
    count();
}