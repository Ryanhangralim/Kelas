#include <stdio.h>
#include <stdlib.h>

struct data
{
    char judul[50];
    char kode[50];
    int halaman;
};

int top = -1;

int main()
{

    int maks;
    printf("Ketik jumlah maksimum tumpukan: ");
    scanf("%d", &maks);
    getchar();

    struct data buku[maks];

    int pilihan;

    while (1)
    {
    menu:
        printf("\nMenu:");
        printf("\n1.Tambah Buku\n2.Ambil Buku\n3.Lihat Data Buku\n4.Keluar");
        printf("\n\nPilihan: ");
        scanf("%d", &pilihan);
        getchar();
        switch (pilihan)
        {
        case 1:
            system("cls");

            if (top == maks - 1)
            {
                printf("\nStack Penuh");
            }
            else
            {
                top = top + 1;
                printf("Ketik data buku\n");
                printf("Ketik Kode:");
                gets(buku[top].kode);
                printf("Ketik Judul:");
                gets(buku[top].judul);
                printf("Ketik Jumlah halaman:");
                scanf("%d", &buku[top].halaman);
                getchar();

                char ch;
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

            if (top == -1)
            {
                printf("\nStack Kosong");
            }
            else
            {
            printf("Data yang akan dihapus:\n");
            printf("Kode: %s\n", buku[top].kode);
            printf("Judul: %s\n",buku[top].judul);
            printf("Jumlah halaman: %d\n", buku[top].halaman);
            printf("Apakah anda yakin (y/n)?");
            scanf("%c", &choice);
            getchar();

            if(choice == 'y')
            {
            top = top - 1;
            printf("Data telah dihapus\n");

                char ch;
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
            printf("Data tidak dihapus\n");
                char ch;
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
                char ch;
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
            if (top == -1)
            {
                printf("\nStack Kosong!!");
            }
            else
            {
                printf("\nData dalam stack: \n");
                printf("No\tKode\tJudul\t\tHal");
                int j = 1;
                for (int i = 0; i <= top; i++)
                {
                    printf("\n%d\t%s\t%s\t\t%d", i+1 , buku[i].kode,  buku[i].judul, buku[i].halaman);
                    j=j+1;
                }
                printf("\n");
                char ch;
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
}
