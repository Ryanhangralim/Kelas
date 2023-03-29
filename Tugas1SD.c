#include<stdio.h>
#include<stdlib.h>

/*Struct*/
 struct nilai
 {
    int uts, uas, tugas, kuis;
    char nama [50];
    char nim [20];
 };
 
int main(){
    int jmlmhs;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jmlmhs);
    getchar();

    struct nilai mhs[jmlmhs];
    
    /*meminta input user*/
    for(int i=0; i<jmlmhs; i++)
    {
        printf("Masukkan Data Mahasiswa %d:\n", i+1);
        printf("Masukkan NIM :");
        gets(mhs[i].nim);
        printf("Masukkan Nama :");
        gets(mhs[i].nama);
        printf("Masukkan Nilai UTS :");
        scanf("%d",&mhs[i].uts);
        getchar();
        printf("Masukkan Nilai UAS :");
        scanf("%d",&mhs[i].uas);
        getchar();
        printf("Masukkan Nilai Tugas :");
        scanf("%d",&mhs[i].tugas);
        getchar();
        printf("Masukkan Nilai Kuis :");
        scanf("%d",&mhs[i].kuis);
        getchar();
        printf("\n");
    }
    
    /*menghitung nilai total*/
    int nilai;

    for(int j=0; j<jmlmhs ;j++)
    {
            nilai = (mhs[j].uts *30/100) + (mhs[j].uas *30/100) + (mhs[j].tugas *20/100) +(mhs[j].kuis *20/100);
        printf("Data Mahasiswa %d\n", j+1);
        printf("NIM : %s\n", mhs[j].nim);
        printf("Nama : %s\n", mhs[j].nama);
        printf("Total Nilai: %d\n",nilai);

        if(nilai>100){
        printf("Huruf mutu : Error");
        }
        else{
            if(nilai>=80 && nilai<=100){
            printf("Huruf mutu : A");
            }
            else if(nilai>=70 && nilai<80){
            printf("Huruf mutu : B+");
            }
            else if(nilai>=65 && nilai<70){
            printf("Huruf mutu : B");
            }
            else if(nilai>=60 && nilai<65){
            printf("Huruf mutu : C+");
            }
            else if(nilai>=55 && nilai<60){
            printf("Huruf mutu : C");
            }
            else if(nilai>=50 && nilai<55){
            printf("Huruf mutu : D+");
            }
            else if(nilai>=45 && nilai<50){
            printf("Huruf mutu : D+");
            }
            else if(nilai<45){
            printf("Huruf mutu : E");
            }
            else{
            printf("Nilai tidak valid");
            }
            }
            printf("\n\n");
        }
    return 0;
}