//
// Created by sfzhang on 4/13/2017.
//
// scope1.c and scope2.c help me understand topics like external linkage, internal linkage
// and no linkage, storage classes(static memory, automatic memory, register)
// In c, scopes include file scope, prototype scope, block scope and function
// scope(which is associated with goto keyword)

#include <stdio.h>
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
        static int y = 2;
        printf("inside func1 block 1, y is %d\n",y);

    }

    // block2
    {
        register int a = 7, d = 8, x = 9;
        printf("inside func1 block 2, a,d,x are %d,%d,%d\n",a,d,x);
        extern int scope1_y;
        printf("inside func1 block2, scope1_y is %d\n",scope1_y);
    }

    w = w + 1;
    printf("inside func1, w is %d,after self-addition\n",w);
    // float func2(int);
    func2(100);
    return 0.0;
}

int m;
//n = 4;
static int y = 99;

float func2(int a) {
     printf("func2 argument a is %d\n", a);
     w = w +1;
     printf("inside func1 block, w is %d\n",w);
     printf("inside func2, m is %d\n",m);
     printf("inside func2, n is %d\n",n);
     m = 1;
     printf("inside func2, after assignment m is %d\n",m);
     printf("inside func2, y is %d\n",y);
     extern int y;
     printf("inside func2, after extern statement y is %d\n",y);
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
Note a:
If the variable is not initialized in any other declaration, it will have an initial value of zero.
(l,n,w,m,scope1_y), scope1_x is implicitly initialized in scope1.c,so its initial value is not zero.


Note b:
The initial value of a function parameter is the argument that was passed when the function
was called.

Note c:
The extern keyword(line 65) does not change the linkage of y that was declared in line 54

Note d:
you can use scope1_x anywhere in the file, but you can not do the same thing with scope1_y
because it is declared with a block scope in func1, you can not use scope1_y outside that block,
scope1_x is declared with a file scope.

Note e:
func1 can not call func2 without declaring the latter's prototype(either inside itself or
or in the beginning of the file)
but func2 can call func1 without its prototype, because func1 was already defined before
func2, the same with variable m declared at line 51

*/