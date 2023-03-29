else
            {
                printf("\nData dalam stack: \n");
                printf("No\tJudul\t\tPenerbit\tHalaman");
                int j = 1;
                for (int i = top; i >= 0; --i)
                {
                    printf("\n%d\t%s\t\t%s\t%d", j , buku[i].judul, buku[i].penerbit, buku[i].halaman);
                    j=j+1;
                }
                printf("\n");
                char ch;
                printf("Apakah anda ingin kembali ke menu utama? (y/n)");
                