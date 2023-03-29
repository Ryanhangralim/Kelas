#include <stdio.h>
#include <stdlib.h>


    struct nilai{
        char nama[50];
        int bb;
        int tb;
    };

int main(){
    
    int x;
    printf("Ketik jumlah pasien: ");
    scanf("%d", &x);
    getchar();
    struct nilai pasien[x];

    for(int i=0; i<x; i++)
    {
    printf("Ketik Data pasien %d : \n", i+1);
    printf("Masukkan Nama pasien: ");
    gets(pasien[i].nama);
    printf("Masukkan Berat Badan Pasien: ");
    scanf("%d", &pasien[i].bb);
    getchar();
    printf("Masukkan Tinggi Badan Pasien: ");
    scanf("%d", &pasien[i].tb);
    getchar();
    printf("\n");
    }

    for(int j=0; j<x; j++)
    {
    printf("Data %d\n",j+1);
    printf("Nama: %s\n", pasien[j].nama);
    printf("Berat Badan: %d\n", pasien[j].bb);
    printf("Tinggi Badan: %d\n", pasien[j].tb);
    printf("\n");
    }

    int beratMin = pasien[0].bb;
    int tinggiMin = pasien[0].tb;
    for (int i = 1; i < x; i++)
    {
        if (pasien[i].bb < beratMin)
        {
            beratMin = pasien[i].bb;
        }
        if (pasien[i].tb < tinggiMin)
        {
            tinggiMin = pasien[i].tb;
        }
    }

    printf("Berat Terendah: %d\n", beratMin);
    printf("Tinggi Terendah: %d\n", tinggiMin);
}