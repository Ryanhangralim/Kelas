#include<stdio.h>
#include<stdlib.h>

struct data{
        char nim[20];
        char nama[50];
        float ipk;
    };

int main()
{
    struct data mhs[4];

    printf("Ketik data mahasiswa:\n");
    for(int i = 0; i<4; i++)
    {
        printf("NIM mahasiswa %d: ",i+1);
        gets(mhs[i].nim);
        printf("Nama mahasiwa %d: ",i+1);
        gets(mhs[i].nama);
        printf("IPK mahasiswa %d: ",i+1);
        scanf("%f", &mhs[i].ipk);
        getchar();
        printf("\n");
    }

    for(int i = 0; i<4; i++)
    {
        printf("Data mahasiswa %d\n", i+1);
        printf("NIM: %s\n", mhs[i].nim);
        printf("Nama: %s\n", mhs[i].nama);
        printf("IPK: %.2f\n\n", mhs[i].ipk);

    }

    return 0;
}