//Array adalah tipe data yang dapat menyimpan banyak data yang sejesnis sedangkan struct adalah tipe data yang dapat menyimpan banyak data dengan jenis data yang beragam
#include<stdio.h>
#include<stdlib.h>

struct data
{
    char NIM[25];
    char nama[50];
    int ipk;
};


int main()
{
    struct data mhs[4];
    int choice;
menu:
    printf("Menu:\n");
    printf("1. Tambah data\n2. Lihat data\n3. Keluar\n Pilihan: ");
    scanf("%d", &choice);
    getchar();

    switch(choice)
    {
        case 1:
            for(int i = 0; i<4; i++)
            {
                printf("Ketik data mahasiswa %d:\n", i+1);
                printf("NIM: ");
                gets(mhs[i].NIM);
                printf("Nama: ");
                gets(mhs[i].nama);
                printf("IPK: ");
                scanf("%d", &mhs[i].ipk);
                getchar();
                printf("\n");
            }
            goto menu;
        break;

        case 2:
            for(int i = 0; i<4; i++)
            {
                printf("Data mahasiswa %d: \n", i+1);
                printf("NIM: %s\n", mhs[i].NIM);
                printf("Nama: %s\n", mhs[i].nama);
                printf("IPk : %d\n\n", mhs[i].ipk);
            }
            goto menu;
        break;

        case 3:
            exit(0);
        break;
    }
    return 0;
}