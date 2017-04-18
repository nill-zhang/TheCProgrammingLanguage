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
    Student *data;
    struct _node *next; // this line enables self-reference

}Node;


typedef struct _linkedlist{
    Node *head;
    Node *tail;
}LinkedList;


typedef int (*Compare)(Student*, Student*);
//typedef void(*Display)(LinkedList*);


void AddAsHead(LinkedList *list, Student *std){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = std;
    node->next = list->head;
    if(list->tail == _NULL){
        list->tail = node;
    }
    list->head = node;

};


void AddAsTail(LinkedList *list, Student *std){
    Node *node =(Node*)malloc(sizeof(Node));
    node->data = std;
    node->next = _NULL;
    if (list->head == _NULL){
        list->head = node;

    }

    if (list->tail != _NULL) {
        list->tail->next = node;
    }

    list->tail = node;




};

int CompareAge(Student *stu1, Student *stu2){

    return (stu1->age)-(stu2->age);

};

int CompareName(Student *stu1, Student *stu2){
    return strcmp(stu1->name,stu2->name);
};

Node *GetNode(LinkedList *list, Compare cpr, void *data){
    Node *tmp = list->head;
    while (tmp != _NULL){
//        switch (cpr){
//            case CompareAge:
//                CompareAge(tmp->data->age,data);
//                break;
//            case CompareName:
//                CompareName(tmp->data->name,data);
//                break;
//            default:
//                break;
//        }
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
        if (node == list->tail) {
            list->head = _NULL;
            list->tail = _NULL;
            return;
        } else {
            list->head = node->next;
            return;
        }
    }
    for (tmp = list->head; tmp != _NULL; tmp = tmp->next) {
        if (tmp->next == node) {
            break;
        }

    }

    if (tmp != _NULL) {
        if (node == list->tail) {
            tmp->next = _NULL;
            list->tail = tmp;
            return;
        } else {
            tmp->next = tmp->next->next;
            return;
        }
    }

    return;
};


void DisplayNodes(LinkedList *list){
     Node *tmp;
    for (tmp=list->head;tmp!=_NULL;tmp=tmp->next){
        printf("StudentName:%s\tStudentAge:%d\n",tmp->data->name,tmp->data->age);

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
    LinkedList *linkedlist = malloc(sizeof(LinkedList));
    InitializeList(linkedlist);
    AddAsHead(linkedlist,&sfzhang);
    AddAsTail(linkedlist,&lyzhang);
    AddAsTail(linkedlist,&xlyang);
    DisplayNodes(linkedlist);
    printf("--------------------------------\n");
    Node *target;
    Student *temp = malloc(sizeof(Student));
    strcpy(temp->name,"lyzhang");
    temp->age = 3;
    target = GetNode(linkedlist,CompareName,temp);
    DeleteNode(linkedlist,target);
    DisplayNodes(linkedlist);
}


int main(){
    LinkedList_Test();

};