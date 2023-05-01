#include<stdio.h>
#include<stdlib.h>

struct tnode{
    char nama[50];
    char nim[25];
    int logika;
    int aritmatika;
    int pemrograman;
    struct tnode *next;
};

int main()
{
    struct tnode *head, *node, *temp, *temp2;
    int jml;
    int counter = 0;
    int choice;
    head = node = NULL;
    printf("Jumlah mahasiswa: ");
    scanf("%d", &jml);
    getchar();

    menu:
        printf("Menu:\n");
        printf("1.Tambah data\n2.Menghapus data\n3.Rata-rata nilai\n4.Keluar\nPilihan: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
            //tambah data
            if(counter==jml)
            {
                printf("List penuh\n");
                goto menu;
            }
            else
            {
                for(int i = 0; i < jml; i++)
                {
                    node = (struct tnode*) malloc (sizeof(struct tnode));
                    printf("\nData mahasiswa %d\n", i+1);
                    printf("NIM: ");
                    gets(node->nim);
                    printf("Nama: ");
                    gets(node->nama);
                    printf("Nilai Logika: ");
                    scanf("%d", &node->logika);
                    getchar();
                    printf("Nilai Aritmatika: ");
                    scanf("%d", &node->aritmatika);
                    getchar();
                    printf("Nilai Pemrograman: ");
                    scanf("%d", &node->pemrograman);
                    getchar();
                    node->next = head;
                    head = node;
                    counter++;
                }
            goto menu;
            }
            break;

            case 2:
            if(node==NULL)
            {
                printf("List kosong\n");
                goto menu;
            }
            else
            {
                //print data mahasiswa
                int i = 1;
                while(node!=NULL)
                {
                    printf("Data mahasiswa %d\n", i);
                    printf("NIM: %s\n", node->nim);
                    printf("Nama: %s\n", node->nama);
                    printf("Nilai Logika: %d\n", node->logika);
                    printf("Nilai Aritmatika: %d\n", node->aritmatika);
                    printf("Nilai Pemrograman: %d\n\n", node->pemrograman);
                    node = node->next;
                    i++;
                }
                node = head;
                temp = head;
                char nimmhs[25];
                printf("NIM mahasiswa yang ingin dihapus: ");
                gets(nimmhs);
                
                //menghapus data
                if(temp->nim==nimmhs)
                {
                    node = node->next;
                    head = node;
                    temp->next = NULL;
                    counter--;
                }
                else if(temp->nim != nimmhs)
                {
                    while(temp->next->nim!=nimmhs)
                    {
                        temp = temp->next;
                    }
                    temp2 = temp->next;
                    temp->next = temp2->next;
                    temp2->next = NULL;
                    counter--;
                }
                goto menu;
            }
            break;

            case 3:
            //rata rata
            int total1, total2, total3, data;
            total1 = total2 = total3 = data = 0;
            while(node!=NULL)
            {
                total1 = total1 + node->logika;
                total2 = total2 + node->aritmatika;
                total3 = total3 + node->pemrograman;
                data++;
                node = node->next;
            }
            node = head;

            printf("Rata-rata nilai:\n");
            printf("Logika :%d\n", total1/data);
            printf("Aritmatika: %d\n", total2/data);
            printf("Pemrograman: %d\n", total3/data);
            goto menu;
            break;

            case 4:
            //keluar
                exit(0);
            break;
        }
    return 0;
}