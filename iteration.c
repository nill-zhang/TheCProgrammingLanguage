//
// Created by Admin on 4/14/2017.
//
#include <stdio.h>
int fibonacci(int n);
int factorial(int n);


int fibonacci(int n){
    if (n <= 2){
        return 1;
    }else{
        int i,j,k,temp;
        i=j=1;
        for (k=0; k<n-2; k++){
            temp = j;
            j += i;
            i = temp;
        }
        return j;

    }
}


int factorial(int n){
    if (n == 1){
        return 1;
    }else{
        int result = 1;
        while (n>1){
            result *= n;
            n--;
        }
        return result;


    }

}

int main(){
    printf("fibonacci(10):%d\n", fibonacci(10));
    printf("factorial(4):%d\n",factorial(4));

}

/* Note:
 * In stead of using recursion, I used iteration to solve those two problems
 * Iteration is more efficient here(result = result * n; j = j + i)
 */