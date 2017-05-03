//
// Created by sfzhang 5/1/2017.
//
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>


#define flag unsigned int
#define DEBUG

flag malloc_help(void **, size_t);
void malloc_helper_test(void);
void freeMem(void *);
void freeMem_test(const char *);
void realloc_test(void);
flag realloc_helper(void **, size_t);


/*
 * I want to get the allocated memory address, pv is just
 * a copy of the real argument, so I set it to a double pointer
 * and save the allocated pointer(*p) as the contents of pv
 * thus, the contents(pc) of the real argument(&pc) is set.
 */
 flag malloc_help(void **pv, size_t s){
    char **p = (char **)pv;         // type conversion
    assert(pv != _NULL && s != 0);  // evaluate arguments
    *p = (char *)malloc(s);
    #ifdef  DEBUG
    if (*p != _NULL){
        memset(*p, 0xCC, s);        // initialize allocated memory block
    }
    #endif
    return (*p != _NULL);
}

flag realloc_helper(void **pv, size_t s){
    char **pch = (char **)pv;      // cast to our type
    char *pNew;
    pNew = realloc(*pch, s);
    if (pNew != _NULL){
        printf("pNew not null\n");
        *pch = pNew;               // if realloc succeed, redirect the old pointer
        memset(pNew, 0xcc, s);
    }

    return (pNew != _NULL);

}


void freeMem(void *pv){

    assert(pv != _NULL);
    free(pv);

}

void freeMem_test(const char *pcc){
    char *pc = malloc(strlen(pcc)+1);
    strcpy(pc, pcc);
    char *pc1 = pc;             // let pc1 points to where pc points
    //freeMem(pc);
    while (*pc1++ != '\0') {
        printf("%c", *(pc1-1)); // memory is reclaimed by the system
    }
}

void realloc_test(void){

    // Note: the following commented pointer can not be passed to realloc,
    // they will cause undefined behavior
    // realloc only takes pointers returned by dynamic mem functions such as
    // realloc, malloc, calloc,etc.
    // char *pwho1 = "I am sfzhang";
    // char name[] = {'I',' ','a','m',' ','s','f','z','h','a','n','g',','};
    // char *pwho1 = name;
    char name[]= "I am sfzhang,";
    char *pwho1 = malloc(strlen(name)+1);
    char *pwho2 = malloc(strlen(name)+1);
    if (pwho1 != _NULL){
        strcpy(pwho1, name);
    }

    if (pwho2 != _NULL){
        strcpy(pwho2, name);
    }

    char *pwhere = "I live in Toronto!";
    char *pWhole;
    char *pPart;
    printf("old pwho1 address:%p, contents:%s\n",pwho1,pwho1);
    printf("old pwho2 address:%p, contents:%s\n",pwho2,pwho2);
    pPart = realloc(pwho1,3);
    pWhole = realloc(pwho2, strlen(pwhere)+strlen(pwho2)+1);
    printf("new pwho1 address:%p, contents:%s  pPart(len:):%p, %s\n",pwho1,pwho1,pPart,pPart);
    printf("new pwho2 address:%p, contents:%s  pWhole:%p, %s\n",pwho2,pwho2,pWhole,pWhole);

}


void realloc_helper_test(void){
    char *pfirstname = "shaofeng";
    char *plastname = "zhang";
    unsigned int status;
    status = realloc_helper((void **)&pfirstname,strlen(pfirstname)+strlen(plastname)+1);
    printf(status?"reallocation succeeded!":"reallocation failed!");
    printf("now firstname %s\n",pfirstname);
    strcpy(pfirstname,"shaofeng zhang");
}


void malloc_helper_test(void){
    unsigned int status;
    char *pc=_NULL;
    status = malloc_help((void *)&pc, 10);
    printf(status?"successful allocation\n":"failed allocation!\n");

}

int main(void){

    // freeMem_test("my name is sfzhang!!\n");
    // malloc_helper_test();
    // realloc_helper_test();
    realloc_test();


}
