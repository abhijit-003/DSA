
// coalesced chaining

#include<stdio.h>
typedef struct 
{
    int key,chain;  //key=data value, chain=index of sanme value
}HT;
// initialization
int inithash(HT hf[10])
{
    int i;
    for(i=0;i<10;i++)
    {
        hf[i].key=hf[i].chain=-1;  //initilize all value to -1(key & chain)
    }
}
// hash function
int hf(int key,int i)
{
    return((key%10 + i) % 10);  //division hf
}
int display(HT ht[10])
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("\n %d[%d][%d]",i,ht[i].key,ht[i].chain);
    }
}
int insert(HT ht[10], int key)
{
    int i, index, oldindex;
    i=0;
    index=hf(key,i);
    if(ht[index].key==-1)
    {
        ht[index].key=key;
    }
    else{
        while(ht[index].chain!=-1)
        {
            index=ht[index].chain;
        }
        oldindex=index;
        for(i=0;i<10;i++)
        {
            index=hf(key,i);
            if(ht[index].key==-1)
            {
                ht[index].key=key;
                ht[oldindex].chain=index;
                return;
            }
        }
    
    }
}
//search key
int search(HT ht[10],int key)
{
    int i;
    for(i=0;i<10;i++)
    {
        if(ht[i].key==key)
        {
            return(key);
        }
    }
    return(-1);
}
int main()
{
    int index, found, choice,key, i;
    HT *ht[10];
    inithash(ht);
    do{
    printf("\n Select your choice");
    printf("\n 0..EXIT:");
    printf("\n 1..INSERT:");
    printf("\n 2..SHOW:");
    printf("\n 3..SEARCH:");
    printf("\n ENTER YOUR CHOICE: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("\n Enter the element to be insert: ");
            scanf("%d",&key);
            insert(ht,key);
            break;
        case 2:
            printf("\n Hash Table: ");
            display(ht);
            break;
        case 3:
            printf("\n Enter the element to be search: ");
            scanf("%d",&key);
            found=search(ht,key);
            if(found==-1)
            {
                printf("\n Key not found.");
            }
            else{
                printf("\n %d found.",found);
            }
            break;
        case 0:
            exit(0);
        default:
            printf("\n Enter valid choice!!");
            break;
    }
    }while(choice!=0);
}
