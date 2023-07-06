#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

int main()
{
    int maks;
    printf("Ketik Jumlah Maksimum Kapasitas: ");
    scanf("%d", &maks);
    getchar();

    int jumlahdata;
data:
    printf("Ketik Jumlah Data: ");
    scanf("%d", &jumlahdata);

    if(jumlahdata>maks)
    {
        printf("\nJumlah data melebihi maksimum\n");
        goto data;
    }

    int data[2][jumlahdata];
    int linear[maks];

    for(int i = 0; i<jumlahdata; i++)
    {
        data[0][i]=0;
        data[1][i]=0;
    }
    for(int i = 0; i<maks; i++)
    {
        linear[i]=0;
    }

    int bil;

    //meminta input user
    for(int i = 0; i<jumlahdata; i++)
    {
        printf("Bil- %d: ", i+1);
        scanf("%d", &bil);
        getchar();
        data[0][i]=bil;

        int x = fungsihash(bil,maks);

        if(linear[x]==0)
        {
            linear[x]=bil;
            data[1][i]=x;
        }
        else{
            int counter = 1;
            while(linear[fungsiLinear(x,counter,maks)]!=0)
            {
                counter++;
            }
                linear[fungsiLinear(x,counter,maks)]=bil;
                data[1][i]=fungsiLinear(x,counter,maks);
        }
    }

    printf("\nNo.\tBil.\tIndex");
    for(int i = 0; i<jumlahdata; i++)
    {
        
        printf("\n%d\t%d\t%d",i+1,data[0][i],data[1][i]);
    }

    return 0;
}