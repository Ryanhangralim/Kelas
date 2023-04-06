#include<stdio.h>
#include<stdlib.h>

struct data
{
    int nomor;
    char nama[50];
    int usia;
    char alamat[100];
};

int main()
{
    int maks;
    int head = 0;
    int tails = 0;
    printf("Ketik jumlah maksimum antrian: ");
    scanf("%d", &maks);
    getchar();

    maks = maks + 1;
    struct data pemilih[maks];


    while(1)
    {
    menu:
        char ch,choice;
        int pilihan;

        printf("\nMenu:");
        printf("\n1.Tambah Data Pemilih\n2.Panggil Pemilih\n3.Lihat Pemilih\n4.Keluar");
        printf("\n\nPilihan: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan)
        {
        case 1:
            //tambah data
            system("cls");
            if(((tails<head)&&(tails-head==1-maks))||(tails>head)&&(tails-head==maks-1))
            {
                printf("Antrian Penuh");
            }
            else
            {
                printf("Ketik data pemilih\n");
                printf("Ketik nomor pemilih:");
                scanf("%d",&pemilih[tails%maks].nomor);
                getchar();
                printf("Ketik nama:");
                gets(pemilih[tails%maks].nama);
                printf("Ketik usia:");
                scanf("%d",&pemilih[tails%maks].usia);
                getchar();
                printf("Ketik alamat:");
                gets(pemilih[tails%maks].alamat);
                tails = tails + 1;

                printf("Apakah anda ingin kembali ke menu utama? (y/n)");
                scanf("%c", &ch);
                getchar();

                if(ch =='y'||ch =='Y'){
                    goto menu;
                }
                else if(ch=='n'||ch=='N'){
                    exit(0);
                }
                else{
                    printf("Pilihan salah");
                } 
            }
            break;

        case 2:
            //panggil pemlih
            system("cls");
            if(head==tails)
            {
                printf("Antrian Kosong");
            }
            else
            {
            printf("Pemilih yang akan dipanggil:\n");
            printf("Nomor Pemilih: %d\n",pemilih[head%maks].nomor);
            printf("Nama: %s\n", pemilih[head%maks].nama);
            printf("Usia: %d\n",pemilih[head%maks].usia);
            printf("Alamat: %s\n",pemilih[head%maks].alamat);
            printf("Apakah anda yakin?(y/n)");
            scanf("%c",&choice);
            getchar();

            if(choice == 'y'||choice == 'Y')
            {
                head = head + 1;
                printf("Pemilih telah dipanggil\n");

                printf("Apakah anda ingin kembali ke menu utama? (y/n)");
                scanf("%c", &ch);
                getchar();

                if(ch =='y'||ch =='Y'){
                    goto menu;
                }
                else if(ch=='n'||ch=='N'){
                    exit(0);
                }
                else{
                    printf("Pilihan salah");
                }
            }
            else if(choice == 'n'||choice=='N')
            {
                printf("Pemilih tidak dipanggil\n");

                printf("Apakah anda ingin kembali ke menu utama? (y/n)");
                scanf("%c", &ch);
                getchar();

                if(ch =='y'||ch =='Y'){
                    goto menu;
                }
                else if(ch=='n'||ch=='N'){
                    exit(0);
                }
                else{
                    printf("Pilihan salah");
                }
            }
            else
            {
                printf("Pilihan tidak valid");

                printf("Apakah anda ingin kembali ke menu utama? (y/n)");
                scanf("%c", &ch);
                getchar();

                if(ch =='y'||ch =='Y'){
                    goto menu;
                }
                else if(ch=='n'||ch=='N'){
                    exit(0);
                }
                else{
                    printf("Pilihan salah");
                }
            }
            }
            break;

        case 3:
            //lihat pemilih
            system("cls");
            if(head==tails)
            {
                printf("Antrian Kosong");
            }
            else
            {
                int j = 0;
                int x = head;
                printf("Antrian pemilih:\n");
                printf("No\tNomor Pemilih\tNama\t\t\tUsia\tAlamat");

                    for (int i = head; i<tails; i++)
                    { 
                        printf("\n%d\t%d\t\t%s\t\t%d\t%s", j+1, pemilih[i%maks].nomor, pemilih[i%maks].nama, pemilih[i%maks].usia, pemilih[i%maks].alamat);
                        j++;
                    }

                printf("\n%d",head%maks);
                printf("%d",tails%maks);
                printf("\n%d",head);
                printf("%d",tails);

                printf("\nApakah anda ingin kembali ke menu utama? (y/n)");
                scanf("%c", &ch);
                getchar();

                if(ch =='y'||ch =='Y'){
                    goto menu;
                }
                else if(ch=='n'||ch=='N'){
                    exit(0);
                }
                else{
                    printf("Pilihan salah");
                }

            }
            break;

        case 4:
            //keluar
            exit(0);
        
        default:
            printf("Pilihan salah");
            break;
        }

    }
    return 0;
}

