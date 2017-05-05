//
// Created by Admin on 5/4/2017.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ALNUM_NUMBER 128

int isAnagram_Dict(char *p1, char *p2);
int isAnagram_Sort(char *p1, char *p2);
int compareCharacter(const void*, const void*);

int compareCharacter(const void* p1, const void* p2) {
    char x, y;
    x = *(const char *) p1;
    y = *(const char *) p2;
    return x - y;
}

int isAnagram_Sort(char *p1, char *p2){
    qsort(p1, strlen(p1), 1, &compareCharacter);
    qsort(p2, strlen(p1), 1, &compareCharacter);
    return !strcmp(p1, p2);
}

int isAnagram_Dict(char *p1, char *p2){
    char dict1[ALNUM_NUMBER], dict2[ALNUM_NUMBER];
    int i = 0;
    for(;i < ALNUM_NUMBER; i++){
        dict1[i] = dict2[i] = 0;
    }
    while(*p1 != '\0'){
        dict1[(int)*p1++]++;      /* char to int*/
    }

    while(*p2 != '\0'){
        dict2[(int)*p2++]++;
    }

    for (i = 0; i < ALNUM_NUMBER; i++){
        if (dict1[i] != dict2[i]){
            break;
        }
    }

    return (i == ALNUM_NUMBER);  /* implies that loop did not terminate early*/
}


void isAnagram_test() {
    char name1[] = "shaofengzhang121";
    char name2[] = "zhangsh1ao12feng";
    int result;
    printf("%s and %s",name1,name2);
    result = isAnagram_Sort(name1, name2);
    if (result == 1) {
        printf("are anagrams of each other!\n");
    } else {
        printf("are not anagrams\n");
    }


    char name3[] = "12345678woshishui";
    char name4[] = "shuishi1234567wo8";
    printf("%s and %s",name3,name4);
    result = isAnagram_Dict(name3, name4);
    if (result == 1) {
        printf(" are anagrams of each other!\n");
    } else {
        printf(" are not anagrams\n");
    }


}

int main(){
    /* the idea behind this program is that anagrams have the same signature
     * whether you sort them or use dictionary to store their characters and occurrences, the result
     * stays the same for all those anagrams*/
    isAnagram_test();
}