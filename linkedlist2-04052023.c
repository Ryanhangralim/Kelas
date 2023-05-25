#include<stdio.h>
#include<stdlib.h>

struct tnode{
    int nilai;
    char nim[50];
    struct tnode *next;
};

int main()
{
    struct tnode *head, *node, *temp;
    head = node = NULL;
    int choice;
menu:
    printf("Menu:\n");
    printf("1. Tambah antrian\n");
    printf("2. Keluar\n");
    printf("Pilihan: ");
    scanf("%d", &choice);
    getchar();

    switch(choice)
    {
        case 1:
            node = (struct tnode*) malloc (sizeof(struct tnode));
            printf("Ketik NIM: ");
            gets(node->nim);
            printf("Ketik Nilai: ");
            scanf("%d", &node->nilai);
            node->next = head;
            head = node;
            goto menu;
        break;

        case 2:
            exit(0);
        break;
    }
    return 0;
}