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
void freeMem(void *);


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


int main(void){

    freeMem_test("my name is sfzhang!!\n");
    unsigned int status;
    char *pc=_NULL;
    status = malloc_help((void *)&pc, 10);
    printf(status?"successful allocation\n":"failed allocation!\n");



}
