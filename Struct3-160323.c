#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char judul[50];
    char penerbit[50];
    int halaman;
}data;

int main()
{
    int x;

    printf("Ketik Jumlah Buku: ");
    scanf("%d", &x);
    getchar();

    data buku[x];

    for(int i=0; i<x; i++)
    {
        printf("Ketik Data Buku %d : \n", i+1);
        printf("Masukkan judul buku: ");
        gets(buku[i].judul);
        printf("Masukkan Penerbit Buku: ");
        gets(buku[i].penerbit);
        printf("Masukkan Jumlah Halaman buku: ");
        scanf("%d", &buku[i].halaman);
        getchar();
        printf("\n");
    }
  
    printf("\nNo\tJudul\t\t\tPenerbit\tHalaman\n");

    for(int j=0; j<x; j++)
    {
        printf("%d\t%s\t\t\t%s\t\t%d\n", j+1, buku[j].judul, buku[j].penerbit, buku[j].halaman);
    }
    return 0;
}