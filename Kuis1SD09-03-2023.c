#include <stdio.h>
#include <stdlib.h>

    struct nilai{
        char nama[50];
        char nim[30];
        int uts;
        int uas;
    };

int main(){
    struct nilai mhs;

    printf("Ketik Data Mahasiswa : \n");
    printf("Masukkan NIM mhs: ");
    gets(mhs.nim);
    printf("Masukkan Nama Mhs: ");
    gets(mhs.nama);
    printf("Masukkan Nilai UAS mhs: ");
    scanf("%d", &mhs.uas);
    printf("Masukkan Nilai UTS mhs: ");
    scanf("%d", &mhs.uts);
    printf("\n");
    
    int nilaiakhir = mhs.uts + mhs.uas;
    int rata = nilaiakhir/2;
    printf("Data mahasiswa\n");
    printf("NIM:%s\n", mhs.nim);
    printf("Nama:%s\n",mhs.nama);
    printf("UAS: %d\n", mhs.uas);
    printf("UTS: %d\n", mhs.uts);
    printf("Nilai: %d\n", nilaiakhir);
    printf("Rata: %d\n", rata);
    char nilaistatus[20];
    if(nilaiakhir>=50)
    {
        printf("Status: Lulus");
    }
    else
    {
        printf("Status: Tidak Lulus");
    }
}