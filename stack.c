//
// Created by sfzhang on 4/9/2017.
//

#define STACKSIZE 200

char stackArray[STACKSIZE];
char *StackPointer = stackArray; /*Points to the next available stack Position*/

void Push(char s);
char Pop(void);
//int isEmpty(void);

/*Push add a new element to the stack*/
void Push(char s) {

    if (StackPointer - stackArray >= STACKSIZE) {

        printf("Stack is full!");

    } else {

        *StackPointer++ = s;

    }
}



/*Pop removes the top element from the stack*/
char Pop(void){
    if (isEmpty()){

        printf("Stack is empty");

    }
    else {

        return *--StackPointer;

    }
}

/*isEmpty checks the stacks emptiness*/
int isEmpty(void){

    return (StackPointer==stackArray) ? 1 : 0;
}

/*Len gives the length of the stack*/
void Len(){

    return StackPointer - stackArray;

}

/*Peek returns the top element in the stack*/
int Peek(){

    return (isEmpty())? -1:(*(StackPointer-1));

}



