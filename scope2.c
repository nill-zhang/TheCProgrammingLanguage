//
// Created by sfzhang on 4/13/2017.
//
// scope1.c and scope2.c help me understand topics like external linkage, internal linkage
// and no linkage, storage classes(static memory, automatic memory, register)
// In c, scopes include file scope, prototype scope, block scope and function
// scope(which is associated with goto keyword)

#include <stdio.h>
#include <stdlib.h>
int l;
int n;
static int w;
extern int scope1_x;
float func2(int);
static float func1( int a, int b, int c ) {
    printf("func1' formal arguments a,b,c: %d,%d,%d\n",a,b,c);
    printf("inside func1, n is %d\n",n);
    n = 10;
    printf("inside func1, n is %d after assignment\n",n);


    printf("inside func1, l is %d\n",l);
    // printf("inside func1, m is %d\n",m);
    printf("inside func1, scope1_x is %d(0)\n",scope1_x);
    int e = 1;
    // you can not use a uninitialized parameter, the follow loc is wrong
    // printf("inside func1, d,e : %d,%d\n",d,e);
    printf("inside func1, e: %d\n",e);


    // block1
    {
        static int y1 = 2;
        printf("inside func1 block 1, y1 is %d\n",y1);

    }

    // block2
    {
        register int a = 7, d = 8, x = 9;
        printf("inside func1 block 2, a,d,x are %d,%d,%d\n",a,d,x);
        extern int scope1_y;
        printf("inside func1 block2, scope1_y is %d\n",scope1_y);
    }

    w++;
    printf("inside func1, w is %d,after self-addition\n",w);
    // float func2(int);
    func2(100);
    return 0.0;
}

int m;
//n = 4;
static int y2 = 99;

// int *pint0;
// pint0 = &m;

// static int *pint1;
// pint1 = malloc(sizeof(int));



float func2(int a) {
     //static int *pint2 = malloc(sizeof(int));
     static int *pint2;
     pint2 = malloc(sizeof(int));
     printf("func2 argument pint2 is %p, its content is %d\n",pint2,*pint2);
     printf("func2 argument a is %d\n", a);
     w++;
     printf("inside func1 block, w is %d after self-addition\n",w);
     printf("inside func2, m is %d\n",m);
     printf("inside func2, n is %d\n",n);
     m ++;
     printf("inside func2, after assignment m is %d\n",m);
     printf("inside func2, y2 is %d\n", y2);
     extern int y2;
     printf("inside func2, after extern statement y is %d\n", y2);
     static int z;
     printf("inside func2, z is %d\n",z);
     return 0.0;
}

int main(){
    func1(1,2,3);
    scope1_x++;
    func2(99);
}
/*
** Note a:
** If the variable is not initialized in any other declaration, it will have an initial value of zero.
** (l,n,w,m,scope1_y), scope1_x is implicitly initialized in scope1.c,so its initial value is not zero.
**
**
** Note b:
** The initial value of a function parameter is the argument that was passed when the function
** was called.
**
** Note c:
** The extern keyword(line 79) does not change the linkage of y2 that was declared in line 56
**
** Note d:
** you can use scope1_x anywhere in the file, but you can not do the same thing with scope1_y
** because it is declared with a block scope in func1, you can not use scope1_y outside that block,
** scope1_x is declared with a file scope.
**
** Note e:
** func1 can not call func2 without declaring the latter's prototype(either inside itself or
** or in the beginning of the file)
** but func2 can call func1 without its prototype, because func1 was already defined before
** func2, the same with variable m declared at line 54
**
** Note f:
** for global variable(internal or external): they are declared outside of a function and executable
** code, the assignment statement, must be inside of a function can not separate
** those variable's initialization. so line 55,58-59,61-62 is wrong.
** for local static variable, line 68-69 is the right way to initializing it instead of
** line 67 which requires const type as its initializer
**
*/