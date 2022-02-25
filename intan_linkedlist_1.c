#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Single linked list
typedef struct Node{
 int Id;
 char Nama[15];
 int Usia;
 struct Node *next;
}node;

node *List;  //variabel Global

//membuat linked list
node *createList(int Id, char Nama[15], int Usia) {
 node *baru;
 baru = (node*)malloc(sizeof(node)); //alokasikan memori sebesar node struct
 baru->Id = Id; //isi atribut nim
 baru->Nama[15] = Nama[15];
 baru->Usia = Usia;
 baru->next = NULL; //isi alamat yang menunjukkan node berikutnya
 
 return baru;
}

void addAwal (int Id, char Nama, int Usia) {
 node *tambah;
 tambah = createList(Id); //Cara create listnya bukan gini tan, contoh: createList(Id,Nama,Usia). Line 30 sama 31 nya dihapus aja
 tambah = createList(Nama); 
 tambah = createList(Usia);
 tambah->next = Element; //Kamu variabel globalnya namanya List bukan Element (cek line 13)
 Element = tambah; //ubah nilai element menjadi tambah, sehingga pointer awal tetap pada element
 tambah = NULL; //kosongkan kembali nilai tambah
}

void addAkhir (int Id, char Nama, int Usia) {
 node *tambah;
 node *help;
 help = Element; //sama kaya line 32
 tambah = createList(Id); //Sama kaya line 29
 tambah = createList(Nama);
 tambah = createList(Usia); // buat list baru
 while (help->next != NULL) { //periksa dan telusuri nilai variabel pointer suatu list itu kosong
  help = help->next;
 }
 help->next= tambah; //isi pointer next dengan list tambah
}

void addmid (int Id, char Nama[15], int Usia, int urut) {
 node *help;
 int i;
 help = Element; //isi variabel temp help dengan nilai element //Sama kaya line 32
 node *tambah = createList(Id); // buat list baru //Mirip kaya line 29
 node *tambah1 = createList(Nama);
 node *tambah2 = createList(Usia);   
 for(i=1;i<urut;i++) { //cari urutan nilai list yang akan di tambahkan
  help = help->next;
 }
 tambah->next = help->next; //isi var pointer list baru dengan var pointer list temp help
 help->next = tambah; //isi var pointer list help dengan node tambah
 tambah = NULL; //kosongkan kembali nilai tambah
 help = NULL; //kosongkan kembali nilai tambah
}

void cetakList () {
 node * ptr;
 ptr = Element; //Nama variabel globalnya List bukan Element
 while(ptr != NULL) {
  printf("%d\n",ptr->Id);
  printf("%d\n",ptr->Nama);
  printf("%d\n",ptr->Usia);
  ptr = ptr->next;
 }
}

int main(){
 node * Element; //ini buat apa tan? jadinya mau pake variabel global atau yang lokal? Pilih salah satu ajaa
 int Id, Id2;
 char Nama [15];
 int Usia;
 
 scanf("%d",&Id);
 scanf("%s",&Nama);
 scanf("%d",&Usia);
 
 Element = createElement(Id,Nama,Usia);
 scanf("%d",&Id);
 scanf("%s",&Nama);
 scanf("%d",&Usia);
 
 addAwal(Id,Nama,Usia);
 scanf("%d",&Id);
 scanf("%s",&Nama);
 scanf("%d",&Usia);
 
 addAkhir(Id,Nama,Usia);
 scanf("%d",&Id);
 scanf("%s",&Nama);
 scanf("%d",&Usia);
 scanf("%d",&Id2);
 
 addAfter(Id,Nama,Usia,Id2);//add id after id2
 scanf("%d",&Id);
 scanf("%",&Nama);
 scanf("%d",&Usia);
 scanf("%d",&Id2);
 
 addBefore(Id,Nama,Usia,Id2);//add id after id2
 scanf("%d",&Id);
 
 hapus(Id);
 scanf("%d",&Id);
 scanf("%s",&Nama);
 scanf("%d",&Usia);
 
 addLast(Id);
 scanf("%d",&Id);
 hapus(Id);
 scanf("%d",&Id);
 hapus(Id);
 cetakList();  
 
 return 0;
}
