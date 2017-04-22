//
// Created by sfzhang on 4/18/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student{
     char *name;
     unsigned char age;
}Student;


typedef struct _node{
    void *data;         /*makes the data more general*/
    struct _node *next; /*this line enables self-reference*/

}Node;


typedef struct _linkedlist{
    Node *head;
    Node *tail;
}LinkedList;


typedef int (*Compare)(void*, void*);

void AddAsHead(LinkedList *list, void *data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = list->head;
    if(list->tail == _NULL){
        list->tail = node;
    }
    list->head = node;

};


void AddAsTail(LinkedList *list, void *data){
    Node *node =(Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = _NULL;
    if (list->head == _NULL){
        list->head = node;

    }else{
        list->tail->next = node; /*this is equivalent to the following three lines because
                                   if list->head != Null, list->tail will not be Null*/
    }

//    if (list->tail != _NULL) {
//        list->tail->next = node;
//    }

    list->tail = node;

};

int CompareName_SameAsFunctionPointer(void *data1, void *data2){

    return strcmp((Student*)data1->name,(Student*)data2->name);

};

int CompareName(Student *stu1, Student *stu2){
    return strcmp(stu1->name,stu2->name);
};

Node *GetNode(LinkedList *list, Compare cpr, void *data){
    Node *tmp = list->head;
    while (tmp != _NULL){
        if (cpr(tmp->data, data) == 0){
            return tmp;
        }
        tmp = tmp->next;
    }
    return _NULL;
};


void DeleteNode(LinkedList *list, Node *node) {
    if (node == _NULL) {
        return;
    }
     Node *tmp;

    if (node == list->head) {
        if (node == list->tail) { /* a single element list*/
            list->head = list->tail = _NULL;
            free(node);
            return;
        } else {
            list->head = list->head->next;
            free(node);
            return;
        }
    }
    for (tmp = list->head; tmp != _NULL; tmp = tmp->next) {
        if (tmp->next == node) { /*find the target node's previous node*/
            break;
        }

    }

    if (tmp != _NULL) { /*tmp->next == node*/
        if (tmp->next == list->tail) {
            tmp->next = _NULL;
            list->tail = tmp;
            free(node);
            return;
        } else {
            tmp->next = tmp->next->next;
            free(node);
            return;
        }
    }
};


void DisplayNodes(LinkedList *list){
    Node *tmp;
    for (tmp=list->head; tmp!=_NULL; tmp=tmp->next){
        printf("SName:%s SAge:%d",((Student*)(tmp->data))->name,((Student*)(tmp->data))->age);
        if (tmp != list->tail){
            printf("------>");
        }

    }

};

void InitializeList(LinkedList *list){
    list->head = _NULL;
    list->tail = _NULL;
}

void LinkedList_Test(void){

    Student sfzhang = {"sfzhang",34};
    Student xlyang = {"xlyang",28};
    Student lyzhang = {"lyzhang",13};
//    LinkedList *linkedlist = malloc(sizeof(LinkedList));
//    InitializeList(linkedlist);
    LinkedList linkedlist;
    InitializeList(&linkedlist);
    AddAsHead(&linkedlist,&sfzhang);
    AddAsTail(&linkedlist,&lyzhang);
    AddAsTail(&linkedlist,&xlyang);
    DisplayNodes(&linkedlist);
    printf("\n--------------\n");
    Node *target;
    Student *temp = malloc(sizeof(Student));
    strcpy(temp->name,"lyzhang");
    temp->age = 3;
    target = GetNode(&linkedlist,CompareName_SameAsFunctionPointer,temp);
    //target = GetNode(&linkedlist,(Compare)CompareName,temp);
    DeleteNode(&linkedlist,target);
    DisplayNodes(&linkedlist);
}


int main(){
    LinkedList_Test();

};

/*
  Note:
  1. uninitialized Pointer can not be used, but variable can see line 144-145,line 146-147
  2. if your implementation does not have the same prototype with the function pointer
     you have to convert it as I did in line 158, line 157,158 has the same effect.
 */