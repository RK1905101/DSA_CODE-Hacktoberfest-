#include <stdio.h>
#include<stdlib.h>
struct node {
  int pri ;
  int info;
  struct node *link;
} *front =NULL;
void insert(int item,int pri)
{
  struct node *tmp, *p;
  tmp=(struct node *)malloc(sizeof(struct node));
  if(tmp==NULL)
  {
    printf("memory is unaviailable");
    return ;
  }
  tmp->info=item;
  tmp->pri=pri;
  if(isEmpty() || pri < front->pri)
  {
    tmp->link=front;
    front=tmp;
  }
  else
  {
  p=front;
  while(p->link!=NULL && p->link->pri<pri)
  p=p->link;
  tmp->link=p->link;
  p->link=tmp;
  }
}
int del()
{
  int iem;
  struct node *tmp;
  int item;
  if(isEmpty())
  {
    printf("queue is empty");
    return 0;
  }
  else{
  tmp=front;
  item=tmp->info;
  front=front->link;
  free(tmp);
}
return item;
}
int isEmpty()
{
  if(front==NULL)
  return 1;
  else return 0;
}
void display()
{
  struct node *tmp;
  tmp=front;
  if(isEmpty())
  printf("Queue is Empty");
  else 
  {
    printf("\nqueue is :\n ");
    printf("Priority  item\n");
    while(tmp!=NULL)
    {
      printf("%5d %8d\n",tmp->pri,tmp->info);
      tmp=tmp->link;
    }
  }

}
int main() {
  int choice,item,pri ;
  while(1)
  {
    printf("\n1.insert\n");
    printf("2.delete\n");
    printf("3.display\n");
    printf("4.EXIT");
    printf("\nEnter your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("Enter the item to be inserted and its priority:");
              scanf("%d %d",&item,&pri);
              insert(item,pri);
              break;
      case 2: item =del();
              if(item==0)
              return 0;
              else
              printf("The deleted element is %d",item);
              break;
      case 3: 
              display();
              break;
      case 4 : exit (1);
      default : printf("Wrong choice");
       
    }
    display();
  }
  return 0;
}