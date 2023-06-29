/**/
/* Binary Search Tree*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
}NODE;
//create BST
NODE *createbst(NODE *root,int data)
{
    if(root==NULL)
    {
        root=(NODE *) malloc(sizeof(NODE));
        root->right=root->left=NULL;
        root->data=data;
        return(root);
    }
    else{
        if(data<root->data)
        {
            root->left=createbst(root->left,data);
        }
        else
        if(data>root->data)
        {
            root->right=createbst(root->right,data);
        }
        else
        {
            printf("\n Duplicate Data is Not Allowed!!");
        }
        return(root);
    }
}

void inorder(NODE *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(NODE *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

void postorder(NODE *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        inorder(root->right);
        printf("%d ",root->data);
    }
}

NODE *search(NODE *root,int key)
{
    NODE *temp=root;
    while((temp!=NULL) && (temp->data!=key))
    {
        if(key<temp->data)
        {
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return(temp);
}
NODE *recsearch(NODE *root,int key)
{
    NODE *temp=root;
    if((root==NULL) || (root->data==key))
    {
        return(temp);
    }
    else
    if(key<temp->data)
    {
        recsearch(temp->left,key);
    }
    else{
        recsearch(temp->right,key);
    }
    
}
NODE *insertBST(NODE *root,int n)
{
    if(root==NULL)
    {
        root=(NODE *)malloc(sizeof(NODE));
        root->data=n;
        root->left=root->right=NULL;
        return(root);
    }
    else
    if(n<root->data)
    {
        root->left=insertBST(root->left,n);
    }
    else{
        root->right=insertBST(root->right,n);
    }
    return(root);
}

NODE *deleteBST(NODE *root,int n)
{
    NODE *temp,*succ;
    if(root==NULL)
    {
        printf("\nElement Not Found!!");
    }
    if(n<root->data)
    {
        root->left=deleteBST(root->left,n);
    }
    else
    if(n>root->data)
    {
        root->right=deleteBST(root->right,n);
    }
    else{
        if(root->left!=NULL && root->right!=NULL)
        {
            succ=root->right;
            while(succ->left)
                succ=succ->left;
            root->data=succ->data;
            root->right=deleteBST(root->right,succ->data);
        }
        else{
            temp=root;
            if(root->right!=NULL)
            {
                root=root->right;
            }
            else if(root->left!=NULL)
            {
                root=root->left;
            }
            else{
            root=NULL;
            }
            free(temp);
        }
    }
    return(root);
}

int countnode(NODE *root)
{
    static int count;
    if(root==NULL)
    {
        return(0);
    }
    else{
        return(1+countnode(root->left)+countnode(root->right));
    }
}
int countleaf(NODE *root)
{
    static int count;
    if(root==NULL)
    {
        return(0);
    }
    else{
        if((root->left==NULL) && (root->right==NULL))
        {
            count++;
        }
        else{
            countleaf(root->left);
            countleaf(root->right);
        }
        return(count);
    }
}
int countnonleaf(NODE *root)
{
    static int count;
    if(root==NULL)
    {
        return(0);
    }
    else{
        if((root->left!=NULL) || (root->right!=NULL))
        {
            count++;
            countnonleaf(root->right);
            countnonleaf(root->left);
        }    
    }
    return(count);
}

int BSTheight(NODE *root)
{
    int l_hei=0,r_hei=0,count=0;
    if(root==NULL)
    {
        return(-1);
    }
    else{
    l_hei=BSTheight(root->left);
    r_hei=BSTheight(root->right);
    }
    if(l_hei>r_hei)
    {
        l_hei++;
        return(l_hei);
    }
    else{
        r_hei++;
        return(r_hei);
    }
}

NODE *mirrorBST(NODE *root)
{
    NODE *temp;
    if(root!=NULL)
    {
        temp=root->left;
        root->left=mirrorBST(root->right);
        root->right=mirrorBST(temp);
    }
    return(root);
}
int smallele(NODE *root)
{
    NODE *temp=root;
    if(temp!=NULL)
    {
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return(temp->data);
    }
}
int bigele(NODE *root)
{
    NODE *temp=root;
    if(temp!=NULL)
    {
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return(temp->data);
    }
}
NODE *treecopy(NODE *root)
{
    NODE *newnode;
    if(root!=NULL)
    {
        newnode=(NODE *) malloc(sizeof(NODE));
        newnode->data=root->data;
        newnode->left=treecopy(root->left);
        newnode->right=treecopy(root->right);
        return(newnode);
    }
    else{
        return(NULL);
    }
}
int main()
{
    int i,key,choice,n,data,val,count,height;
    NODE *temp,*root=NULL;
    while(1)
    {
        printf("\n **..MAIN MENU..**\n");
        printf("\n 1...CREATE BST");
        printf("\n 2...INORDER BST");
        printf("\n 3...PREORDER BST");
        printf("\n 4...POSTORDER BST");
        printf("\n 5...SEARCH BST");
        printf("\n 6...INSERT IN BST");
        printf("\n 7...DELETE ELEMENT");
        printf("\n 8...COUNT TOTAL NODES");
        printf("\n 9...COUNT LEAF NODES");
        printf("\n 10..COUNT NONLEAF NODES");
        printf("\n 11..HEIGHT OF TREE");
        printf("\n 12..MIRROR BST");
        printf("\n 13..SMALLEST IN BST");
        printf("\n 14..GREATEST IN BST");
        printf("\n 15..COPY BST");
        printf("\n 0...EXIT BST");
        printf("\n ENTER YOUR CHOICE:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\n How many Elements"); 
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                printf("\n Enter %d element:",i);
                scanf("%d",&data);
                root=createbst(root,data);
            }
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            printf("\n Enter The Element to Search:");
            scanf("%d",&key);
            temp=recsearch(root,key);
            if(temp!=NULL)
            {
                printf("\n Element Found. %d",key);
            }
            else{
                printf("\n Element %d Not Found!!",key);
            }
            break;
        case 6:
            printf("\n Enter Element To be Insert:");
            scanf("%d",&n);
            insertBST(root,n);
            break;
        case 7:
            printf("\n Enter Element To be deleted:");
            scanf("%d",&n);
            deleteBST(root,n);
            break;
        case 8:
            count=countnode(root);
            if(count==0)
            {
                printf("\n No Nodes in Tree:");
            }
            else{
                printf("\n TOTAL Nodes= %d",count);
            }
            break;
        case 9:
            count=countleaf(root);
            if(count==NULL)
            {
                printf("\nThere is No any node!");
            }
            else{
                printf("\n LEAF Nodes = %d",count);
            }
            break;
        case 10:
            count=countnonleaf(root);
            if(count==NULL)
            {
                printf("\n Tree is Empty!!");
            }
           else{
                printf("\n NON-LEAF Nodes = %d",count);
            }
            break;
        case 11:
            height=BSTheight(root);
            if(height==-1)
            {
                printf("\Tree is Empty!!");
            }
            else{
                printf("\nHeight of Tree is %d",height);
            }
            break;
        case 12:
            temp=mirrorBST(root);
            inorder(temp);
            break;
        case 13:
            key=smallele(root);
            if(key==0)
            {
                printf("\nTree is Empty!!");
            }
            else{
            printf("\n The Smallest Element is %d",key);
            }
            break;
        case 14:
            key=bigele(root);
            if(key==0)
            {
                printf("\nTree is Empty!!");
            }
            else{
            printf("\n The BIGEST Element is %d",key);
            }
            break;
        case 15:
            treecopy(root);
            preorder(root);
            break;
        case 0:
            exit(0);
        default:
            printf("\n Enter valid choice");
        }
    }
