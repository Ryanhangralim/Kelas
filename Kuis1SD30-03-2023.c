#include<stdio.h>
#include<stdlib.h>

struct data
{
    char norek[50];
    char nama[50];
    char nominal[50];
};

int head, tails = 0;

int main()
{
    int maks;
    printf("Ketik Jumlah maksimum antrian: ");
    scanf("%d",&maks);
    getchar();

    struct data nasabah[maks];

    int pilihan;
    char ch;

    while (1)
    {
    menu:
        printf("\nMenu:");
        printf("\n1.Tambah antrian\n2.Proses antrian\n3.Lihat antrian\n4.Keluar");
        printf("\n\nPilihan: ");
        scanf("%d", &pilihan);
        getchar();
        switch (pilihan)
        {
        case 1:
            system("cls");

            if (tails == maks)
            {
                printf("\nAntrian Penuh");
            }
            else
            {
                printf("Ketik data nasabah\n");
                printf("Ketik No.Rekening:");
                gets(nasabah[tails].norek);
                printf("Ketik Nama:");
                gets(nasabah[tails].nama);
                printf("Ketik Nominal transaksi:");
                gets(nasabah[tails].nominal);
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
            system("cls");

            char choice;

            if (tails == 0)
            {
                printf("\nAntrian Kosong");
            }
            else
            {
            printf("Data nasabah yang akan diproses:\n");
            printf("No. Rekening: %s\n", nasabah[head].norek);
            printf("Nama: %s\n", nasabah[head].nama);
            printf("Nominal transaksi: %s\n", nasabah[head].nominal);
            printf("Apakah anda yakin (y/n)?");
            scanf("%c", &choice);
            getchar();

            if(choice == 'y')
            {
            head = head + 1;
            printf("Data telah dihapus\n");

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
            else if(choice == 'n')
            {
            printf("Data tidak dihapus");
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
            else{
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
            system("cls");
            if (head == tails)
            {
                printf("\nAntrian Kosong");
            }
            else
            {
                int j = 0;
                printf("\nData dalam Antrian: \n");
                printf("No\tNo.Rek\t\t\tNama\t\tNominal");
                for (int i = head; i < tails; i++)
                {
                    printf("\n%d\t%s\t\t%s\t\t\t%s", j+1 , nasabah[i].norek, nasabah[i].nama, nasabah[i].nominal);
                    j++;
                }
                printf("\n");
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
        case 4:
            exit(0);

        default:
            printf("\nPilihan Salah");
        }
    }

    return 0;
}