#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//20 31 33 40 10 12 30 15

int fungsi(int x, int y)
{
    int res;
    res = x%y;
    return res;
}

int fungsiresolusi(int x, int i, int y)
{
    int res;
    res = (x+i)%y;
    return res;
}

int main()
{
    int index = 0;
    printf("Masukkan index: ");
    scanf("%d", &index); getchar();
    int jumlahdata;
data:
    printf("\nMasukkan jumlah data: ");
    scanf("%d", &jumlahdata); getchar();

    if(jumlahdata>index)
    {
        printf("Data melebihi index");
        goto data;
    }

    int data[2][jumlahdata];
    int linear[index];
    
    for(int i = 0; i<jumlahdata; i++)
    {
        data[0][i]=0;
        data[1][i]=0;
    }
    for(int i = 0; i<index; i++)
    {
        linear[i]=0;
    }

    //meminta input user
    for(int i = 0; i<jumlahdata; i++)
    {
        printf("Data %d: ", i+1);
        scanf("%d", &data[0][i]);
    }
    //mengisi baris mod/hash
    for(int i = 0; i<jumlahdata; i++)
    {
        data[1][i]=fungsi(data[0][i],index);
    }
    //mengisi baris linear
    for(int i = 0; i<jumlahdata; i++)
    {
        int counter = 1;
        bool indicator = false;
        int k = data[1][i];
        if(linear[k]==0)
        {
            linear[k]=data[0][i];
        }
        else if(linear[k]!=0)
        {
            while(indicator==false)
            {
                if(linear[fungsiresolusi(k,counter,index)]==0)
                {
                    linear[fungsiresolusi(k,counter,index)]=data[0][i];
                    indicator=true;
                }
                else{
                    counter++;
                }
            }
        }
    }
    printf("Data Hash\n");
    for(int i = 0; i<jumlahdata; i++)
    {
        printf("%d %d\n", data[0][i], data[1][i]);
    }
    printf("\nLinear\n");
    for(int i = 0; i<index; i++)
    {
        printf("%d\n", linear[i]);
    }
    return 0;
}