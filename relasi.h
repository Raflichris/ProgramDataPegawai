
#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#define next_pegawai(r) (r)->next_pegawai
#define next_gaji(r) (r)->next_gaji
#define next_relasi(r) (r)->next_relasi

#include "pegawai.h"
#include "gaji.h"

typedef struct elmRelasi *adr_relasi;

struct elmRelasi{
      adr_pegawai next_pegawai;
      address next_gaji;
      adr_relasi next_relasi;
};
struct list_relasi{
      adr_relasi first;
};

void createRelasi(list_relasi &L3);
adr_relasi alokasi(adr_pegawai p, adr_relasi q);
void dealokasi(adr_relasi &r);

adr_relasi cari_relasi(list_relasi L3, adr_relasi p);

void insertFirst_relasi(list_relasi &L3, adr_relasi p);

void deleteFirst_relasi(list_relasi &L3, adr_relasi p);
void deleteLast_relasi(list_relasi &L3, adr_relasi p);
void deleteAfter_relasi(list_relasi &L3, adr_relasi p);

void pengubung(ListPegawai &L, listGaji &L2, list_relasi &L3, infotype x, infotype_gaji y);

void tampil_berdasarkan_gaji(listGaji L2, list_relasi L3);
void tampil_berdasarkan_pegawai(ListPegawai L, list_relasi L3);
void tampil_berdasarkan_pegawai_tertentu(ListPegawai L, list_relasi L3);
void tampil_berdasarkan_gaji_tertentu (listGaji L2, list_relasi L3);

#endif // RELASI_H_INCLUDED
