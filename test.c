#include<stdio.h>
#include<stdlib.h>

    struct tnode{
        int data;
        struct tnode *next;
    };

int main()
{
    struct tnode *head, *node;
    int bil;
    head = node = NULL;
    printf("KEtik bilangan: ");
    do{
        if (scanf("%d", &bil) !=1) break;
        node = (struct tnode*) malloc (sizeof(struct tnode));
        node->data = bil;
        node->next = head;
        head = node;
    }
    while(1);

    node = head;
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    while (head != NULL)
    {
        node = head;
        head=head->next;
        free(node);
    }
    return 0;
}