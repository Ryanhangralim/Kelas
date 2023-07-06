#include<stdio.h>
#include<stdlib.h>

struct tnode{
    int bil;
    struct tnode *prev;
    struct tnode *next;
}; 

int main()
{
    struct tnode *head, *tail, *node, *temp;
    head = tail = node = temp = NULL;
    int pilihan;
    int counter = 0;

menu:
    printf("\nMenu:\n1.Tambah data\n2.Lihat data\n3.Hapus data\n4.Keluar\nPilihan: ");
    scanf("%d", &pilihan);
    getchar();

switch(pilihan)
{
    case 1:
    if(counter==0)
    {
        head = (struct tnode*) malloc (sizeof(struct tnode));
        printf("Data: ");
        scanf("%d", &head->bil);
        getchar();
        head->next = head;
        tail = head;
        counter++;
    }
    else{
        node = (struct tnode*) malloc (sizeof(struct tnode));
        printf("Data: ");
        scanf("%d", &node->bil);
        getchar();
        node->prev = tail;
        tail->next = node;
        node->next = head;
        tail = node;
        counter++;
        node = NULL;
    }
    goto menu;
    break;

    case 2:
    temp = head;
    while(temp->next!=head)
    {
        printf("%d ", temp->bil);
        temp = temp->next;
    }
    printf("%d", temp->bil);
    printf("\n");
    goto menu;
    break;

    case 3:
    printf("Data yang dihapus: %d",head->bil);
    temp = head;
    head = head->next;
    head->next->prev=head;
    tail->next=head;
    free(temp);
    counter--;
    goto menu;
    break;

    case 4:
        exit(0);
    break;

    default:
        printf("Pilihan salah, coba lagi");
    break;
}
    return 0;
}