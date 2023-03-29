#include<stdio.h>
#include<stdlib.h>

int main()
{
    char band[4]={"Bocchi", "Ikuyo", "Ryo", "Nijika"};
    
    //Changing "Ikuyo" to "Kita"
    band[1]="Kita";

    for(char member:band)
    {
        printf("%s\n",member);
    }

    return 0;
}