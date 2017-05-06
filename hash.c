//
// Created by Admin on 5/4/2017.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

#define MULIPLIER 31
#define HASHTABLE_LENGTH 23000
typedef struct _Node{
    int count;
    char *word;
    struct _Node *next;
}Node;

Node* ht[HASHTABLE_LENGTH];

unsigned hash(char *);
void addWordsFromFile(char *);
void incWordCount(char *);
void normalize(char **);

unsigned hash(char *ch){
    unsigned h = 0;
    while(*ch != '\0'){
        h = h * MULIPLIER + *ch;
        ch++;
    }
    return h % HASHTABLE_LENGTH;
}


void incWordCount(char *w){
    unsigned idx;
    idx = hash(w);
    Node *p = ht[idx];
    while(p != NULL){
        if (strcmp(p->word, w) == 0){
            (p->count)++;
            return;
        }
        p = p->next;

    }
    Node* new =(Node *)malloc(sizeof(Node));
    assert(new != _NULL),"memory allocation failed!";
    new->word = malloc(strlen(w) + 1);
    assert(new->word != _NULL),"memory allocation failed!";
    strcpy(new->word, w);
    new->count = 1;
    if (ht[idx] == _NULL){
        new->next = NULL;
    }else{
        new->next = ht[idx]->next;
    }
    ht[idx] = new;


}
void addWordsFromFile(char *fpath){
    char buff[30];
    char *buf;
    buf = buff;
    FILE *f = fopen(fpath,"r");
    if (f == NULL){
        perror("An error has occurred");
    }
    while (fscanf(f, "%s", buf) != EOF) {
        normalize(&buf);
        if (strlen(buf) != 0) {
            incWordCount(buf);
        }
    }
    fclose(f);

}

void normalize(char **p) {
    int i, j;
    for (i = 0; i < strlen(*p) && !isalpha((*p)[i]); i++);
    for (j = strlen(*p)-1; (j >= i) && !isalpha((*p)[j]); j--);
    (*p)[j+1] = '\0';     /* the second loop terminates when j is the last alphabetic letter*/
    *p = &((*p)[i]);      /* *p points to the first alphabetic character in the string*/
}



void printHT(){
    int i;
    Node *p;
    printf("WORD\t\t\t\t\tCOUNT\n\n");
    for (i = 0; i < HASHTABLE_LENGTH; i++){
        for (p = ht[i]; p != NULL; p = p->next){
            printf("%-20s\t%d\n",p->word,p->count);
        }
    }
}

int main(){
    addWordsFromFile("C:\\Users\\Admin\\CLionProjects\\TheCProgrammingLanguage\\explain.txt");
    printHT();

}


