//
// Created by Admin on 4/17/2017.
//
#include <stdio.h>

void print_2darray(int rows, int columns, int (*pInt)[columns]){

    printf("----------------------------------------------------\n");
    printf("       pInt->%p,         pInt+1->%p\n",pInt,pInt+1);
    printf("   &pInt[0]->%p,     &pInt[0]+1->%p\n",&pInt[0],&pInt[0]+1);
    printf("        ,,,,,,,,,,,,,,,,       &pInt[1]->%p\n",&pInt[1]);
    printf("    pInt[0]->%p,      pInt[0]+1->%p\n",pInt[0],pInt[0]+1);
    printf("&pInt[0][0]->%p,  &pInt[0][0]+1->%p\n",&pInt[0][0],&pInt[0][0]+1);
    printf("        ,,,,,,,,,,,,,,,,    &pInt[0][1]->%p\n",&pInt[0][1]);
    printf("----------------------------------------------------\n");

    printf("   pInt-->%p,     pInt+1-->%p\n",pInt,pInt+1);
    printf("  *pInt-->%p,    *pInt+1-->%p\n",*pInt,*pInt+1);
    int *temp, i;
    for (temp=*pInt,i=0; temp <(*pInt+columns*rows); temp++,i++){
        if (i%4==0){
            printf("\n");
        }
        printf("%d ",*temp);
    }

    /* Alternative way:
     *
     * int (*temp)[columns];
     * int i;
     * for (temp=pInt;temp <(pInt+rows);temp++){
     *     for (i=0;i<columns;i++){
     *         if (i % columns == 0){
     *             printf("\n");
     *         }
     *         printf("%d ",*(*temp+i));
     *     }
     * }
     *
     * */


}


void print_2darray_flattened(int rows, int columns, int *pInt){
    int i;
    for (i=0;i<rows*columns;i++){
        if (i % columns == 0 && i != 0){
            printf("\n");
        }
        printf("%d ",pInt[i]);

    }
}



void print_2darray_test(){
    int a[2][4] = {{1,2,3,4},
                   {5,6,7,8} };
    printf("      &a->%p,        &a+1->%p\n",&a,&a+1);
    printf("       a->%p,         a+1->%p\n",a,a+1);
    printf("   &a[0]->%p,     &a[0]+1->%p\n",&a[0],&a[0]+1);
    printf("        ,,,,,,,,,,,,,       &a[1]->%p\n",&a[1]);
    printf("    a[0]->%p,      a[0]+1->%p\n",a[0],a[0]+1);
    printf("&a[0][0]->%p,  &a[0][0]+1->%p\n",&a[0][0],&a[0][0]+1);
    printf("        ,,,,,,,,,,,,,    &a[0][1]->%p\n",&a[0][1]);



    /* Printing Result:
     *
     * ----------------------------------------------------
     *          &a->0xffffcbc0,           &a+1->0xffffcbe0
     *           a->0xffffcbc0,            a+1->0xffffcbd0
     *       &a[0]->0xffffcbc0,        &a[0]+1->0xffffcbd0
     *            ,,,,,,,,,,,,,          &a[1]->0xffffcbd0
     *        a[0]->0xffffcbc0,         a[0]+1->0xffffcbc4
     *    &a[0][0]->0xffffcbc0,     &a[0][0]+1->0xffffcbc4
     *            ,,,,,,,,,,,,,       &a[0][1]->0xffffcbc4
     * ----------------------------------------------------
     *        pInt->0xffffcbc0,         pInt+1->0xffffcbd0
     *    &pInt[0]->0xffffcbc0,     &pInt[0]+1->0xffffcbd0
     *         ,,,,,,,,,,,,,,,,       &pInt[1]->0xffffcbd0
     *     pInt[0]->0xffffcbc0,      pInt[0]+1->0xffffcbc4
     * &pInt[0][0]->0xffffcbc0,  &pInt[0][0]+1->0xffffcbc4
     *         ,,,,,,,,,,,,,,,,    &pInt[0][1]->0xffffcbc4
     * ----------------------------------------------------
     *       pInt-->0xffffcbc0,        pInt+1-->0xffffcbd0
     *       pInt-->0xffffcbc0,       *pInt+1-->0xffffcbc4
     *-----------------------------------------------------
     * Short Note:
     * 1. a == &a[0] always
     * 2. a[0] == &a[0][0] always,
     * 3. a[i] == &a[i][0] always, ==> a[i]+j== &a[i][j] ==>*(a[i]+j) == a[i][j](j < columns)
     * 4. pInt == a; pInt + 1 = a+1 = &a[0]+1 = &a[1]
     * 5. a[0]+k =&a[k/columns][k%columns], &a[i][j] = a[0]+i*j
     * 6. *(*(pInt + i)+j) == a[i][j] ==pInt[i][j]
     *
     * */

    //print_2darray_flattened(2,4,&a[0][0]);
    print_2darray(2, 4, a);
}




int main() {
    print_2darray_test();
}