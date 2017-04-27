//
// Created by sfzhang on 4/26/2017.
//
#include <stdio.h>

void PostIncInCondition(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    int b[] = {11,22,33,44,55,66,77,88,99};
    int *pa = a;
    int *pb = b;
    // postfix-increment is not a part of the loop body
    // after the comparison, pa and pb will do self-increment no matter
    // the results of the comparison
    // when the loop exits, *pa initially is 77, but it then do the self-increment
    // so *pa becomes 8, the same happens inside the loop
    // the *pa,*pb printed is the next elements in the the corresponding array
    while((*pa++ = *pb++) != 77){
        printf("pa-->%d,pb-->%d\n",*pa,*pb);
    }
    printf("outside loop pa-->%d, pb-->%d\n",*pa,*pb);
    int i=0;
    // now you should know what happens here,
    // it will always print the next element after the ith element
    // this is dangerous, because when i is 8, you access a[9] inside
    // the loop, its out of the range of the current array!
    while(i++ < 9) {
        printf("array a[%d]=%d\n",i,a[i]);
    }


}

void PostIncInBody(){
    int a[9], b[9],i;
    for(i=0;i<9;i++){
        a[i] = i+1;
        b[i] = (i+1)*11;
    }

    int *pa = a;
    int *pb = b;
    while((*pa = *pb) != 77){
        printf("pa-->%d,pb-->%d\n",*pa++,*pb++);
    }
    printf("outside loop pa-->%d, pb-->%d\n",*pa,*pb);
    int j=0;
    while(j < 9) {
        printf("array a[%d]=%d \n",j,a[j]);
        j++;
    }

}


int main(){
    PostIncInCondition();
    PostIncInBody();

}
