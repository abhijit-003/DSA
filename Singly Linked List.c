/*singaly linked list operation */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *next;
    int info;
}NODE;

/*create list*/
void create(NODE *head,int n)
{
    NODE *newnode,*temp;
    temp=head;
    int i;
    for(i=0;i<n;i++)
    {
        newnode=(NODE *) malloc(sizeof(NODE));
        
        printf("\n Enter %d Element:",i);
        scanf("%d",&newnode->info);
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;
    }
}

/*insert function*/
void insertpos(NODE *head,int num,int pos)
{
    NODE *temp,*newnode;
    int i;
    for(temp=head,i=0;(temp!=NULL) && (i<=pos-1);temp=temp->next,i++)
    {
        if(temp==NULL)
        {
            printf("\n Position out of Range:");
            return;
        }
        else if(i==pos-1)
        {
        newnode=(NODE *) malloc(sizeof(NODE));
        newnode->info=num;
        newnode->next=temp->next;
        temp->next=newnode;
        }
    }
}

void deletelast(NODE *head)

{

     NODE *temp,*temp1;

     for(temp=head;temp->next!=NULL;temp=temp->next)

    {
     temp1=temp;
    }

     temp1->next=NULL;
    free(temp);


}
int deletefirst(NODE *head)

{

 NODE *temp;

 temp=head->next;

 head->next=temp->next;

 free(temp);

 return;

}
void deletebynum(NODE *head,int num)
{
    NODE *temp,*temp1;
    for(temp=head;temp->next!=NULL;temp=temp->next)
    {
        if(temp->next->info==num)
        {
            temp1=temp->next;
            temp->next=temp1->next;
            free(temp1);
            return;
        }
     }
    printf("\n Element Out of range!!");
}

/*search element*/
int search(NODE *head,int num)
{
    NODE *temp;
    int i,n;
    for(temp=head->next,i=1;temp!=NULL;temp=temp->next,i++)
    {
        if(temp->info==num)
        {
            return i;
        }  
    } return -1;
}

/*display list*/
void displayrec(NODE *head)
{
    NODE *temp=head->next;
    if(temp!=NULL)
    {
        printf("\n %d",temp->info);
        displayrec(temp);
    }
}

/*main function*/
int main()
{
    int i,pos,n,choice,num;
    NODE *head;
    head=(NODE *) malloc(sizeof(NODE));
    do{
    printf("\n \t \t Main Menu");
    printf("\n select option : ");
    printf("\n 1...Create :");
    printf("\n 2...Display :");
    printf("\n 3...Insert :");
    printf("\n 4...Delete by No. :");
    printf("\n 5...Delete last :");
    printf("\n 6...Delete first:");
    printf("\n 7...Search:");
    printf("\n 11...exit :");
    printf("\n Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
            printf("\n How many elements:");
            scanf("%d",&n);
            create(head,n);
            displayrec(head);
            break;
    case 2:
            printf("\n Elements are"); 
            displayrec(head);
            break;
    case 3:
            printf("\n Enter Element:");
            scanf("%d",&n);
            printf("\n Enter Position:");
            scanf("%d",&pos);
            insertpos(head,n,pos);
            displayrec(head);
            break;
    case 4:
            printf("\n Enter Element To Delete");
            scanf("%d",&num);
            deletebynum(head,num);
            displayrec(head);
            break;
    case 5:
            deletelast(head);
            break;
    case 6: 
            deletefirst(head);
            break;
    case 7:
            printf("\n Enter Element to be Searched:");
            scanf("%d",&num);
            search(head,num);
            pos = search(head,num);
            if(pos==-1)
            {
                printf("\n Element Not Found!!");
            }
            else
            {
                printf("\n Element found at position %d",pos);
            }
            break;
     }      
    } while(choice!=11);
}

/*
output:
*
