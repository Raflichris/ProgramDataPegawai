
#ifndef PEGAWAI_H_INCLUDED
#define PEGAWAI_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) (L).first
#define last(L) (L).last
#include <string>

using namespace std;

struct infotype{
    string NIP;
    string nama;
    string jabatan;
    string alamat;
    string noTelp;
};


typedef struct elmPegawai *adr_pegawai;

struct elmPegawai{
    infotype info;
    adr_pegawai next;
    adr_pegawai prev;
};

struct ListPegawai{
    adr_pegawai first;
    adr_pegawai last;
};


void createListPegawai(ListPegawai &L);

adr_pegawai alokasi(string NIP, string nama, string jabatan, string alamat, string noTelp);
void dealokasi(adr_pegawai &P);
adr_pegawai updatePgw(infotype x);

adr_pegawai cariPegawai(ListPegawai L, infotype x);
void printInfoPegawai(ListPegawai L);

void insertFirst(ListPegawai &L, adr_pegawai P);
void insertLast(ListPegawai &L, adr_pegawai P);
void insertAfter(ListPegawai &L, adr_pegawai P, adr_pegawai q);


void deleteFirst(ListPegawai &L, adr_pegawai &P);
void deleteLast(ListPegawai &L, adr_pegawai &P);
void deleteAfter(ListPegawai &L, adr_pegawai q);



#endif // PEGAWAI_H_INCLUDED
