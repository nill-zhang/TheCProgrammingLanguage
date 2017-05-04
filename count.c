//
// Created by sfzhang on 4/6/2017.
//
#include <stdio.h>

#define MAX_WORD_LENGTH 30

void count() {
    int ntab, nbackspace, nblank, nline, nword, ncharacter;
    ntab = nbackspace = nblank = nline = nword = ncharacter = 0;
    char c;
    char input[2000];
    int inword = 0;
    int i;
    for (i = 0; (c = getchar()) != EOF; i++) {
        input[i] = c;
        switch (c) {
            case '\t':
                ntab++;
                if (inword == 1) { /* if inword is 1, it means it was in an word, now it gets out of that word
                                         a word has past by*/

                    nword++;
                }
                inword = 0;
                break;


            case '\b':
                nbackspace++;
                if (inword == 1) {

                    nword++;
                }
                inword = 0;
                break;

            case '\n':
                nline++;
                if (inword == 1) {

                    nword++;
                }
                inword = 0;
                break;

            case ' ':
                nblank++;
                if (inword == 1) {

                    nword++;
                }
                inword = 0;
                break;

            default:
                ncharacter++;
                inword = 1;
        }
    }

    if (inword == 1) {
        nword++;
    }/*if I sent EOF while I am still in a word, I need to count this word in*/

    if (input[i - 1] != '\n') {
        nline++;
    }/*if the last character was not a newline, means I sent an EOF while I am on a newline, I need to count this line in*/
    printf("\nnTabs\tnBackSpaces\tnBlanks\tnCharacters\tnWords\tnLines\n");
    printf("%5d\t%11d\t%7d\t%11d\t%6d\t%6d\n", ntab, nbackspace, nblank, ncharacter, nword, nline);
    printf("Original Input: %s\n", input);

}
void getWordLengths(unsigned *plengths){
    int chr;
    int len =0;
    while ((chr = getchar())!= EOF){
        if (chr == '\n'||chr== '\t'|| chr ==' '){
            if (len != 0){
                plengths[len]++; /* increse the current word length counter*/
            }
            len =0;
            continue;
        }else if (len==0){
            len = 1;
        }else{
            len++;
        }
    }
}

unsigned maximum(unsigned *plengths, int s){
    int i;
    unsigned max = 0;
    for(i=0;i<s;i++){
        if (plengths[i] > max){ /* compare unsigned *plengths with signed max which is -1
                                 * -1 is all 1s in two's complement representation, the condition
                                 * will always be false*/
            max = plengths[i];
        }
    }
    return max;


}

void wordlength_frequency_histogram(char mark){
    unsigned lengths[MAX_WORD_LENGTH], max; /* lengths array saves word length frequencies according to their
                                             * corresponding indices, lengths[i] has the frequency of words with
                                             * length i */
    int i,j,k;
    for(i=0;i < MAX_WORD_LENGTH;i++){
        lengths[i] = 0;
    }

    getWordLengths(lengths);
    max = maximum(lengths,MAX_WORD_LENGTH);
    printf("\n\nfreq\n\n");
    for (i=0; i < max; i++){
        printf("%*d\t",4,max-i);           /*max-width is 4, right alignment*/
        for (j=0; j < MAX_WORD_LENGTH; j++){
            if (lengths[j] == 0){
                continue;
            }else if((lengths[j]+i) >= max){
                printf("%c ",mark);
            }else{
                printf("  ");
            }

            if ((j/10) > 0){
                printf(" ");       /* adjust alignment for double digit word length*/
            }
        }
        printf("\n");

    }
    printf("   0\t");

    for(k=0; k < MAX_WORD_LENGTH; k++){
        if(lengths[k] != 0){
            printf("%d ",k);
        }
    }

    printf("  word length\n");
}


int main(){

    //count();
    wordlength_frequency_histogram('-');


}

/* Result:
 *
 * freq
 *   12      -
 *   11      -
 *   10      -
 *    9      -
 *    8      -
 *    7      - -
 *    6      - -
 *    5      - -       -   -
 *    4    - - - -   - - - -
 *    3    - - - - - - - - -          -
 *    2    - - - - - - - - -          -
 *    1    - - - - - - - - - -  -  -  -  -  -  -
 *    0    1 2 3 4 5 6 7 8 9 10 11 12 13 15 17 21   word length
 */
