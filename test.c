#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode{
char NIM[25];
char nama[100];
int ipk;
struct tnode *next;
};

int main(){
int maks, choice;
printf("Maksimum tumpukan: ");
scanf("%d", &maks);
getchar();

int counter = 0;
struct tnode *head, *tail, *node, *temp, *temp2;
menu:
printf("Menu:\n1.Tambah data\n2.Lihat data\n3.Hapus data\n4.Hapus data dengan NIM\n5.Keluar\nPilihan: ");
scanf("%d",&choice); getchar();
head=node=tail=NULL;
switch(choice){
case 1:
if(counter==maks)
{
printf("Tumpukan penuh");
}
else{
if(counter==0){
head=(struct tnode*) malloc (sizeof(struct tnode));
printf("NIM: "); gets(head->NIM); 
printf("Nama: "); gets(head->nama);
printf("IPK: "); scanf("%d",&head->ipk);
head->next=node;
counter++;}
else if(counter>0){
node = (struct tnode*) malloc (sizeof(struct tnode));
printf("NIM: "); gets(node->NIM); 
printf("Nama: "); gets(node->nama);
printf("IPK: "); scanf("%d",&node->ipk);
head->next = node;
node->next = head;
tail = node;
node = NULL;
counter++;
}
}
goto menu;
break;

case 2:
temp = head;
while(temp->next!=head){
printf("NIM: %s\n",temp->NIM);
printf("Nama: %s\n",temp->nama);
printf("IPK: %d\n\n", temp->ipk);
temp = temp->next;
}
goto menu;
break;

case 3:
temp = head;
head = head->next;
tail->next = head;
free(temp);
counter--;
goto menu;
break;

case 4:
temp = head;
char nimhapus[25];
printf("NIM yang akan dihapus: "); gets(nimhapus);
if(counter==0)
{
printf("Tumpukan kosong");
}
else{
if(stricmp(temp->NIM,nimhapus)==0)
{
temp = head;
head = head->next;
tail->next = head;
free(temp);
counter--;
}
else if(stricmp(temp->NIM,nimhapus)!=0)
{
while(stricmp(temp->next->NIM,nimhapus)!=0)
{
temp = temp->next;
}
temp2=temp->next;
temp->next = temp2->next;
free(temp2);
}
counter--;
}
goto menu;
break;

case 5:
exit(0);
break;
}
}
