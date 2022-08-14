#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char num[20];
    char name[30];
    int hr;
    int min;
    struct node *next;
}NODE;
NODE *insert(NODE *first)
{
  NODE *newnode,*temp;
  newnode=(NODE*)malloc(sizeof(NODE));
  newnode->next=NULL;
  printf("enter the train number\n");
  scanf("%s",newnode->num);
  printf("enter the name of train\n");
  scanf("%s",newnode->name);
  printf("enter the time at which train will be arirved at station\n");
  scanf("%d %d",&newnode->hr,&newnode->min);
  if(first==NULL)
     first=newnode;
  else
  {
      temp=first;
      while(temp->next!=NULL)
      {
          temp=temp->next;
      }
      temp->next=newnode;

  }
  return (first);
}
NODE *delay(NODE *first)
{
    int i=0;
    char train[20];
    NODE *temp;
    printf("enter the number which is being delayed\n");
    scanf("%s",train);
    temp=first;
    while(temp!=NULL)
    {

        if(strcmp(train,temp->num)==0)
        {
            printf("enter the new arrival time\n");
           scanf("%d%d",&temp->hr,&temp->min);
           break;
        }
        temp=temp->next;


    }
    return first;
}

void display(NODE *first)
{
   if(first==NULL)
    printf("no trains available");
    printf("|-----------");
  while(first!=NULL)
  {
      printf("-----------|\n");
      printf("|%s|",first->num);
      printf("|%s|",first->name);
      printf("|%d:%d|\n",first->hr,first->min);
      printf("|-----------");
      first=first->next;

  }
  printf("-----------|");
}
NODE *sort(NODE *first)
{
    NODE *temp,*prev,*check,*next;
    char num[20],name[30];
    int hr ,min;
    temp=first;
    while(temp!=NULL)
    {
        int count1,count2;
        count1=temp->hr*60+temp->min;
        check=first;
        if(temp->next==NULL)
            break;
        else
        {
          while(check!=NULL)
          {
             if(check->next==NULL)
                  {
                      break;

                  }

                next=check->next;
              count2=next->hr*60+next->min;
              if(count1>count2)
              {

                strcpy(num,check->num);
                strcpy(check->num,next->num);
                strcpy(next->num,num);
                 strcpy(name,check->name);
                  strcpy(check->name,next->name);
                strcpy(next->name,name);
                 hr=check->hr;
                  check->hr=next->hr;
                next->hr=hr;

                 min=check->min;
                  check->min=next->min;

                next->min=min;

                check=check->next;

              }
              else
               check=check->next;

          }

        }
        temp=temp->next;
    }

return first;
}


int main()
{
 NODE *first=NULL;
 int choice;
 while(1)
 {
     printf("\n1:Enter the details of train\n2:For delay\n3:Display \n4:exit\n");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1:printf("Enter the details of train\n");
                first=insert(first);
                first=sort(first);
                break;
         case 2:first=delay(first);
                first=sort(first);
                break;
         case 3:display(first);
                break;
         case 4:exit(1);


     }
 }
}