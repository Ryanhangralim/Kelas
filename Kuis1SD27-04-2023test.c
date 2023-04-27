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
    int bil;
    head = NULL;
    node = NULL;
    menu:
        system("cls");
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
                //tambah
                printf("Tambah bilangan: ");
                scanf("%d", &bil);
                node = (struct tnode*) malloc (sizeof(struct tnode));
                node -> data = bil;
                node -> next = head;
                head = node;
                goto menu;
            break;

            case 2:
            //lihat
            if(node==NULL)
            {
                printf("Data kosong!");
                getchar();
            }
            else{
                printf("Bilangan dalam linked list: ");
                while(node!= NULL)
                {
                    printf("%d ", node->data);
                    node = node->next;
                }
                getchar();
            }
            goto menu;
            break;

            case 3:
            //hapus
            while(head != NULL)
            {
                node = head;
                head=head->next;
                free(node);
                node = NULL;
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