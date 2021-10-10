#include <stdio.h>
#include <stdlib.h> 
#define MAX 8
int queue[MAX];
int rear = - 1;
int front = - 1;
void enqueue(){
    if (front == (rear+1)%MAX)
    printf("\nQueue Overflow! \n");
    else
    {
        if (front == - 1)
            front = 0;
        rear=(rear+1)%MAX;
        printf("\nEnter the element : ");
        scanf("%d", &queue[rear]);
    }
}
void dequeue(){
    if (front == - 1)
        printf("\nQueue Underflow! \n");
    else{
        printf("\nDeleted from queue is : %d\n", queue[front]);
        if (front == rear)
            front=rear=-1;
        else
            front=(front+1)%MAX;
    }
}
void display(){   
    int i;
    if (front == - 1)
        printf("\nQueue is empty! \n");
    else{
        printf("\nQueue is : \n");
        for (i = front; i != rear; i=(i+1)%MAX)
            printf("%d ", queue[i]);
        printf("%d ", queue[rear]);    
    }
}
void main(){
    int ch;
    printf("\t\tCIRCULAR QUEUE MENU\n\t-------------------------\n");
    while (1){
        printf("\n1.Insert element\n2.Delete element\n3.Display elements\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch (ch){
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
            case 4:exit(1);
            default:
            printf("\nWrong choice \n");
        }
    }
}