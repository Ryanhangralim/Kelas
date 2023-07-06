#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode{
    char nim[20];
    char nama[50];
    struct tnode *prev;
    struct tnode *next;
}; 

int main()
{
    struct tnode *head, *tail, *node, *temp, *temp2;
    head = tail = node = temp = NULL;
    int pilihan;
    int counter = 0;

menu:
    printf("\nMenu:\n1.Tambah data\n2.Hapus data\n3.Lihat data\n4.Keluar\nPilihan: ");
    scanf("%d", &pilihan);
    getchar();
    switch(pilihan)
    {
        case 1:
        if(counter==0)
        {
            head = (struct tnode*) malloc (sizeof(struct tnode));
            printf("NIM: ");
            gets(head->nim);
            printf("Nama: ");
            gets(head->nama);
            head->next = node;
            tail = head;
            counter++;
        }
        else{
            node = (struct tnode*) malloc (sizeof(struct tnode));
            printf("NIM: ");
            gets(node->nim);
            printf("Nama: ");
            gets(node->nama);
            node->prev = tail;
            tail->next = node;
            tail = node;
            tail->next=NULL;
            counter++;
            node = NULL;
        }
        goto menu;
        break;

        case 2:
        char nimHapus[20];
        printf("NIM yang ingin dihapus: ");
        gets(nimHapus);
        if(stricmp(head->nim,nimHapus)==0)
        {
            temp = head;
            head = head->next;
            free (temp);
            counter--;
            printf("Data telah dihapus");
        }
        else{
            temp = head;
            while(stricmp(temp->next->nim,nimHapus)!=0)
            {
                temp = temp->next;
            }
            temp2 = temp->next;
            temp->next=temp2->next;
            free(temp2);
            printf("Data telah dihapus");
        }

        goto menu;
        break;

        case 3:
        if(counter==0)
        {
            printf("Data kosong"); getchar;
        }
        else
        {
            temp = head;
            printf("NIM     Nama");
            while(temp!=NULL)
            {
                printf("\n%s %s", temp->nim, temp->nama);
                temp = temp->next;
            }
            printf("\n");
        }
        goto menu;
        break;

        case 4:
            exit(0);
        break;

        default:
            printf("Pilihan salah, coba lagi");
            goto menu;
        break;
    }
    return 0;
}