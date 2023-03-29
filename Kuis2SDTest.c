#include <stdio.h>
#include <stdlib.h>

struct data
{
    char judul[50];
    char penerbit[50];
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
        printf("\n1.Tambah Data\n2.Ambil Data\n3.Lihat Data\n4.Keluar");
        printf("\n\nPilihan: ");
        scanf("%d", &pilihan);
        getchar();
        switch (pilihan)
        {
        case 1:
            system("cls");

            if (top == maks - 1)
            {
                printf("\nStack Overflow");
            }
            else
            {
                top = top + 1;
                printf("Ketik data buku\n");
                printf("Ketik Judul:");
                gets(buku[top].judul);
                printf("Ketik Penerbit:");
                gets(buku[top].penerbit);
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
                printf("\nStack Underflow");
            }
            else
            {
            printf("Data yang akan dihapus:\n");
            printf("Judul: %s\n",buku[top].judul);
            printf("Penerbit: %s\n", buku[top].penerbit);
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
            printf("Data tidak dihapus");
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
                printf("\nStack Underflow!!");
            }
            else
            {
                printf("\nData dalam stack: \n");
                printf("No\tJudul\t\tPenerbit\tHal");
                int j = 1;
                for (int i = top; i >= 0; --i)
                {
                    printf("\n%d\t%s\t\t%s\t\t%d", j , buku[i].judul, buku[i].penerbit, buku[i].halaman);
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
