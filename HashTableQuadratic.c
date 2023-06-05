#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

//20 31 33 40 10 12 30 15

int fungsi(int x, int y)
{
    int res;
    res = (x+y)%y;
    return res;
}

int fungsiresolusi1(int x, int y, int i)//x = data asli; y = index; i = counter;
{
    int res;
    res = ((x+((int)(pow(i,2))))+y)%y;
    return res;
}
int fungsiresolusi2(int x, int y, int i)
{
    int res;
    res = ((x-((int)(pow(i,2))))+y)%y;
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
    int quadratic[index];
    
    for(int i = 0; i<jumlahdata; i++)
    {
        data[0][i]=0;
        data[1][i]=0;
    }
    for(int i = 0; i<index; i++)
    {
        quadratic[i]=0;
    }

    //meminta input user
    for(int i = 0; i<jumlahdata; i++)
    {
        printf("Data %d: ", i+1);
        scanf("%d", &data[0][i]);
    }
    //mengisi baris mod
    for(int i = 0; i<jumlahdata; i++)
    {
        data[1][i]=fungsi(data[0][i],index);
    }
    //mengisi baris quadratic
    for(int i = 0; i<jumlahdata; i++)
    {
        int counter = 1;
        bool indicator = false;
        int k = data[1][i];
        if(quadratic[k]==0)
        {
            quadratic[k]=data[0][i];
        }
        else if(quadratic[k]!=0)
        {
            while(indicator==false)
            {
                if(quadratic[fungsiresolusi1(k,index,counter)]==0)
                {
                    quadratic[fungsiresolusi1(k,index,counter)]=data[0][i];
                    indicator=true;
                }
                else if(quadratic[fungsiresolusi2(k,index,counter)]==0)
                {
                    quadratic[fungsiresolusi2(k,index,counter)]=data[0][i];
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
        printf("%d %d %d\n", data[0][i], data[1][i]);
    }
    printf("\nquadratic\n");
    for(int i = 0; i<index; i++)
    {
        printf("%d\n", quadratic[i]);
    }
    return 0;
}