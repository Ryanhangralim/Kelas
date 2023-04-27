#include<stdio.h>
#include<stdlib.h>

struct tnode
{
    int data;
    struct tnode *next;
};

int main()
{

    struct tnode *head, *node;
    int pilihan;
    menu:
    printf("Menu: \n");
    printf("1.Tambah bilangan\n");
    printf("2.Data bilangan\n");
    printf("3.Hapus bilangan\n");
    printf("4.Keluar\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);
    getchar();

    switch(pilihan)
    {
        case 1:
        //tambah bilangan
            int bil;
            head = node = NULL;
            printf("Tambah bilangan: ");
            do{
                if (scanf("%d", &bil)!=1) break;
                node = (struct  tnode*) malloc (sizeof(struct tnode));
                node -> data = bil;
                node -> next = head;
                head = node;
            }
            while(1);
            
            goto menu;
        break;

        case 2:
        // Data bilangan
        while (node!=NULL)
        {
            printf("%d", node->data);
            node = node->next;
        }
        goto menu;
        break;

        case 3:
        //Hapus bilangan
        while(head != NULL)
        {
            node = head;
            head=head->next;
            free(node);
        }
        goto menu;
        break;

        case 4:
        //keluar
        exit(0);
        break;

    }
    return 0;
}