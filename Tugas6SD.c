#include<stdio.h>
#include<stdlib.h>

struct tnode{
    int bil;
    struct tnode *next;
};

int main()
{
    int numCount[100]={};
    struct tnode *head, *node, *temp, *temp2;
    head=node=temp=NULL;
    int pilihan;
    int counter = 0;

menu:
    printf("\nMenu:\n1. Tambah bilangan\n2. Data bilangan\n3. Hapus bilangan\n4. Keluar\nPilihan: ");
    scanf("%d", &pilihan); getchar();
    switch(pilihan)
    {
        case 1: //tambah
            node=(struct tnode*) malloc (sizeof(struct tnode));
            printf("Bilangan: "); scanf("%d", &node->bil); getchar();
            node->next=head;
            head=node;
            counter++;
            numCount[node->bil]++;
            goto menu;
        break;

        case 2: //data
        if(counter==0)
        {
            printf("Data kosong"); getchar();
        }
        else{
            temp = head;
            while(temp!=NULL)
            {
                printf("%d ",temp->bil);
                temp = temp->next;
            }
            for(int i = 0; i<10; i++)
            {
                if(numCount[i]!=0)
                {
                    printf("\n%d --> %d",i,numCount[i]);
                }
            }
        }
        goto menu;
        break;

        case 3:
        if(counter==0)
        {
            printf("Data kosong"); getchar();
        }
        else{
            int hapus;
            printf("Data yang akan dihapus: ");
            scanf("%d",&hapus); getchar();

            temp = head;
            while(numCount[hapus]>0)
            {
                if(temp->bil==hapus)
                {
                    temp2=temp;
                    head = head->next;
                    numCount[temp2->bil]--;
                    free(temp2);
                    temp=head;
                    counter--;
                }
                else if(temp->bil!=hapus)
                {
                    while(temp->next->bil!=hapus)
                    {
                        temp = temp->next;
                    }
                    temp2 = temp->next;
                    temp->next=temp2->next;
                    numCount[temp2->bil]--;
                    free(temp2);
                    counter--;
                }
            }
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