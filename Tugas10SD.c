#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

struct data{
    int noAbsen;
    char nama[50];
};

int fungsihash(int x, int y)
{
    int res;
    res = x%y;
    return res;
}

int fungsiLinear(int x, int y, int z)
{
    int res;
    res = (x+y)%z;
    return res;
}

int fungsiQuadratic1(int x, int y, int i)//x = data asli; y = index; i = counter;
{
    int res;
    res = ((x+((int)(pow(i,2))))+y)%y;
    return res;
}
int fungsiQuadratic2(int x, int y, int i)
{
    int res;
    res = ((x-((int)(pow(i,2))))+y)%y;
    return res;
}
int fungsiQuadratic3(int x, int y, int i)
{
    int res;
    res = (x+i)%y;
    return res;
}

int main()
{
    int jml;
    printf("Ketik jumlah data: ");
    scanf("%d", &jml);
    getchar();

    //deklarasi variabel
    struct data mhs[jml];
    memset(&mhs->noAbsen,0,sizeof(mhs));
    int data[jml];
    int tempInt;
    char tempChar[50];   
    bool empty = true;
                        
    int pilihan;
menu:
    printf("\nMenu:\n1. Input Data\n2. View Data\n3. Cari Data\n4. Keluar\nPilihan: ");
    scanf("%d", &pilihan); getchar();

    switch(pilihan)
    {
        case 1:
            int pilihan2;
            printf("\nMenu metode collision resolusion:\n1. Linear Probing\n2. Quadratic Probing\nPilihan: ");
            scanf("%d", &pilihan2);
            getchar();
            switch (pilihan2)
            {
            case 1: //Linear Probing
                //meminta input
                for(int i = 0; i<jml; i++)
                {
                    
                    printf("Data - %d:\n",i+1);
                    printf("No Absen: ");
                    scanf("%d", &tempInt);
                    getchar();
                    printf("Nama: ");
                    gets(tempChar);

                    //mencari index kosong
                    int counter = 1;
                    bool indicator = false;
                    int k = fungsihash(tempInt, jml);

                    if(mhs[k].noAbsen==0)
                    {

                        mhs[k].noAbsen=tempInt;
                        strcpy(mhs[k].nama, tempChar);
                    }
                    else if(mhs[k].noAbsen!=0)
                    {
                        while (indicator==false)
                        {
                            if(mhs[fungsiLinear(k,counter,jml)].noAbsen==0)
                            {
                                mhs[fungsiLinear(k,counter,jml)].noAbsen=tempInt;
                                strcpy(mhs[fungsiLinear(k,counter,jml)].nama, tempChar);
                                indicator=true;
                            }
                            else
                                counter++;
                            }
                        }
                        
                    }
                
                break;

            case 2: //Quadratic probing
            //meminta input
            for(int i = 0; i<jml; i++)
            {
                printf("Data - %d:\n",i+1);
                printf("No Absen: ");
                scanf("%d", &tempInt);
                getchar();
                printf("Nama: ");
                gets(tempChar);
            
                //mencari index kosong
                int counter = 1;
                bool indicator = false;
                int k = fungsihash(tempInt, jml);
                if(mhs[k].noAbsen==0)
                {
                    mhs[k].noAbsen=tempInt;
                    strcpy(mhs[k].nama, tempChar);
                }
                else if(mhs[k].noAbsen!=0)
                {
                    while(indicator==false)
                    {
                        if(mhs[fungsiQuadratic1(k,jml,counter)].noAbsen==0)
                        {
                                mhs[fungsiQuadratic1(k,jml,counter)].noAbsen=tempInt;
                                strcpy(mhs[fungsiQuadratic1(k,jml,counter)].nama, tempChar);
                                indicator=true;
                        }
                        else if(mhs[fungsiQuadratic2(k,jml,counter)].noAbsen==0)
                        {
                                mhs[fungsiQuadratic2(k,jml,counter)].noAbsen=tempInt;
                                strcpy(mhs[fungsiQuadratic2(k,jml,counter)].nama, tempChar);
                                indicator=true;                            
                        }
                        else if(mhs[fungsiQuadratic3(k,jml,counter)].noAbsen==0)
                        {
                                mhs[fungsiQuadratic3(k,jml,counter)].noAbsen=tempInt;
                                strcpy(mhs[fungsiQuadratic3(k,jml,counter)].nama, tempChar);
                                indicator=true;                            
                        }
                        else{
                            counter++;
                        }
                    }
                }
            }
                break;
            
            default:
                printf("Pilihan salah, silahkan coba lagi");
                goto menu;
                break;
            }
            empty = false;
            goto menu;
        break;

        case 2:
        if(empty==true)
        {
            printf("\nData kosong");
        }
        else if(empty==false)
        {
            printf("\nList data:");
            for(int i = 0; i<jml; i++)
            {
                printf("\n%d :%s", mhs[i].noAbsen,mhs[i].nama);
            }
        }
        goto menu;
        break;

        case 3: //cari
        if(empty==true)
        {
            printf("\nData kosong");
        }
        else if(empty==false)
        {
            int absenCari;
            printf("No absen yang ingin dicari: ");
            scanf("%d", &absenCari);
            getchar();
            int x=0;

            for(int i = 0; i<jml; i++)
            {
                int k = fungsihash(absenCari+i,jml);
                if(mhs[k].noAbsen==absenCari)
                {
                    printf("\nNomor absen %d : %s", mhs[k].noAbsen, mhs[k].nama);
                }
                else{
                    x++;
                }
            }
            if(x==jml)
            {
                printf("\nData tidak ditemukan");
            }
        }
        goto menu;
        break;

        case 4:
            exit(0);
        break;

        default:
            printf("Pilihan salah, silahkan coba lagi");
            getchar();
            goto menu;
        break;
    }
    return 0;
}