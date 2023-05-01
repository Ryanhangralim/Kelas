#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode{
    int nim;
    struct tnode *next; 
};

int main()
{
    struct tnode *head, *node, *temp1, *temp2;
    int bil;
    head = node = NULL;
    node = (struct tnode*) malloc(sizeof(struct tnode));
    bil = 220153;
    node->nim = bil;
    node->next = head;
    head=node;

    node = (struct tnode*) malloc(sizeof(struct tnode));
    bil = 210153;
    node->nim = bil;
    node->next = head;
    head=node;

    node = (struct tnode*) malloc(sizeof(struct tnode));
    bil = 260153;
    node->nim = bil;
    node->next = head;
    head=node;

    node = (struct tnode*) malloc(sizeof(struct tnode));
    bil = 561030;
    node->nim = bil;
    node->next = head;
    head=node;

    node = (struct tnode*) malloc(sizeof(struct tnode));
    bil = 170153;
    node->nim = bil;
    node->next = head;
    head=node;

    while(node!=NULL)
    {
        printf("%d ", node->nim);
        node = node->next;
    }

    node = head;

    temp1 = head;
    while(temp1->next->nim != 170153)
    {
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = NULL;

    printf("\n");

    while(node!=NULL)
    {
        printf("%d ", node->nim);
        node = node->next;
    }

    return 0;
}