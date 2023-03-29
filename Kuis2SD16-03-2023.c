#include<stdio.h>
#include<stdlib.h>

int main()
{
    typedef struct data{
    char judul[50];
    char penerbit[50];
    int halaman;
    }data;
    int pilihan;
do{
    
    printf("MENU UTAMA");
    printf("1. Tambah Data");
    printf("2. Ambil Data");
    printf("3. Lihat Data");
    printf("4. Keluar");
    printf("Masukkan Pilihan: ");
    scanf("%d", &pilihan);

switch(pilihan)
    {
        case 1: /*Tambah data*/
            int x;

        printf("Ketik Jumlah Buku: ");
        scanf("%d", &x);

        data buku[x];

        for(int i=0; i<x; i++)
        {
            printf("Ketik Data Buku %d : \n", i+1);
            printf("Masukkan judul buku: ");
            fflush(stdin);
            gets(buku[i].judul);
            printf("Masukkan Penerbit Buku: ");
            fflush(stdin);
            gets(buku[i].penerbit);
            printf("Masukkan Jumlah Halaman buku: ");
            scanf("%d", &buku[i].halaman);
            printf("\n");
        }
        break;

        case 2: /*Ambil data*/

        break;

        case 3: /*Lihat Data*/
            printf("\nNo\tJudul\t\t\tPenerbit\tHalaman\n");

        for(int j=0; j<x; j++)
        {
            printf("%d\t%s\t\t%s\t%d\n", j+1, buku[j].judul, buku[j].penerbit, buku[j].halaman);
        }
        break;

    default: printf("Pilihan salah, silahkan coba kembali");
        break;

        
    }
    } while (pilihan !=4);
    return 0;
}