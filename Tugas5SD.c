#include<stdio.h>
#include<stdlib.h>

struct tnode{
    char noktp[16];
    char nama[100];
    int voucher;
    struct tnode *next;
};

int main()
{
    struct tnode *head, *tail, *node;
    head = tail = NULL;
    int pilihan;
    int counter = 0;

menu:
    printf("\nMenu:\n1. Tambah Antrian\n2. Proses Antrian\n3. Lihat Antrian\n4. Keluar Program\nPilihan: ");
    scanf("%d",&pilihan); getchar();
    switch(pilihan)
    {
        case 1: //tambah
            if(counter==0)
            {
                head = (struct tnode*) malloc (sizeof(struct tnode));
                printf("\nMasukkan data penduduk:\n");
                printf("Nomor KTP: ");
                gets(head->noktp);
                printf("Nama: ");
                gets(head->nama);
                printf("Nominal Voucher(Rp): ");
                scanf("%d", &head->voucher); getchar();
                head->next=tail;
                tail = head;
                counter++;
            }
            else{
                node = (struct tnode*) malloc (sizeof(struct tnode));
                printf("\nMasukkan data penduduk:\n");
                printf("Nomor KTP: ");
                gets(node->noktp);
                printf("Nama: ");
                gets(node->nama);
                printf("Nominal Voucher(Rp): ");
                scanf("%d", &node->voucher); getchar();
                tail->next=node;
                tail = node;
                node->next=NULL;
                node = NULL;
                counter++;
            }
            goto menu;
        break;

        case 2: //proses
        if(counter==0)
        {
            printf("Antrian kosong");
            getchar();
            goto menu;
        }
        else{
        printf("\nAntrian yang diproses:\n");
        printf("Nomor KTP: %s\n",head->noktp);
        printf("Nama : %s\n", head->nama);
        printf("Nominal Voucher: %d\n", head->voucher);
        node = head;
        head = head->next;
        free(node);
        counter--;
        }
        goto menu;
        break;

        case 3: //lihat
        if(counter==0)
        {
            printf("Antrian kosong");
            getchar();
            goto menu;
        }
        else{
            node = head;
            printf("\nNomor KTP\tNama\t\tNominal Voucher");
            while(node!=NULL)
            {
                printf("\n%s\t%s\t%d", node->noktp,node->nama,node->voucher);
                node = node->next;
            }
        }
        goto menu;
        break;

        case 4: //keluar
            exit(0);
        break;

        default:
            printf("Pilihan salah, silahkan coba lagi"); getchar(); 
            goto menu;
        break;
    }
    return 0;
}