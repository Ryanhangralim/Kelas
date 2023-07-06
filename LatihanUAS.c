#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct tnode{
    int bil;
    struct tnode *left;
    struct tnode *right;
};

struct tnode* create()
{
    int x;
    struct tnode *newnode;
    newnode = (struct tnode*) malloc (sizeof(struct tnode));
    printf("Ketik bilangan (Ketik -1 jika tidak ada node): ");
    scanf("%d",&x); getchar();

    if(x==-1)
    {
        return 0;
    }
    newnode->bil=x;
    printf("Left child of %d\n",x);
    newnode->left=create();
    printf("Right child of %d\n",x);
    newnode->right=create();
    return newnode;
}

struct tnode* createOrder()
{   
    struct tnode *newnode, *root, *temp;
    newnode = root = NULL;
    newnode = (struct tnode*) malloc (sizeof(struct tnode));
    int jumlah;
    printf("\nJumlah bilangan: ");
    scanf("%d",&jumlah); getchar();
    int bilangan[jumlah];
    int tempBil;
    bool found;

    for(int i = 0; i<jumlah; i++)
    {
        printf("Ketik bilangan %d: ", i+1);
        scanf("%d", &tempBil); getchar();
        if(i == 0)
        {
            newnode->bil=tempBil;
            newnode->left=NULL;
            newnode->right=NULL;
            root = newnode;
        }
        else{
            bool found = false;
            temp = root;
            while(found==false){
                if(tempBil<temp->bil){
                    if(temp->left!=NULL)
                    {
                        temp = temp->left;
                    }
                    else if(temp->left==NULL)
                    {
                        newnode = NULL;
                        newnode = (struct tnode*) malloc (sizeof(struct tnode));     
                        newnode->bil=tempBil;
                        newnode->left=NULL;
                        newnode->right=NULL;
                        temp->left=newnode;
                        found = true;                 
                    }
                }
                else if(tempBil>temp->bil)
                {
                    if(temp->right!=NULL)
                    {
                        temp = temp->right;
                    }
                    else if(temp->right==NULL)
                    {
                        newnode = NULL;
                        newnode = (struct tnode*) malloc (sizeof(struct tnode));     
                        newnode->left=NULL;
                        newnode->right=NULL;
                        newnode->bil=tempBil;
                        temp->right=newnode;
                        found = true;                 
                    }
                }
                else if(tempBil==temp->bil)
                {
                    found = true;
                }
            }
        }

    }
    return root;
}

void preorder(struct tnode* root){
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->bil);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct tnode* root){
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->bil);
    inorder(root->right);
}

void postorder(struct tnode* root){
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->bil);
}

int main()
{
    int pil;
    struct tnode *root;
    root = NULL;

menu:
    printf("\nMenu\n1.Create\n2.Preorder\n3.Inorder\n4.Postorder\nPilihan: ");
    scanf("%d", &pil); getchar();

    switch(pil)
    {
        case 1:
            root = create();
            goto menu;
        break;

        case 2:
            printf("Preoder is: ");
            preorder(root);
            goto menu;
        break;

        case 3:
            printf("Inorder is: ");
            inorder(root);
            goto menu;
        break;

        case 4:
            printf("Postorder is: ");
            postorder(root);
            goto menu;
        break;

        case 5:
            exit(0);
        break;

        case 6:
            root = createOrder();
        goto menu;
    }
}