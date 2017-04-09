//
// Created by sfzhang on 4/9/2017.
//

#define STACKSIZE 200

char stackArray[STACKSIZE];
char *StackPointer=stackArray; /*Points to the next available stack Position*/

void Push(char s);
char Pop(void);
//int isEmpty(void);

void Push(char s) {

    if (StackPointer - stackArray >= STACKSIZE) {

        printf("Stack is full!");

    } else {

        *StackPointer++ = s;

    }
}




char Pop(void){
    if (isEmpty()){

        printf("Stack is empty");

    }
    else {

        return *--StackPointer;

    }
}


int isEmpty(void){

    return (StackPointer==stackArray) ? 1 : 0;
}


void Len(){

    return StackPointer - stackArray;

}


int Peek(){

    return (isEmpty())? -1:(*(StackPointer-1));

}



