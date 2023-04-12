
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

#include "pegawai.h"
#include "gaji.h"
#include "relasi.h"

using namespace std;

void menu(ListPegawai &L, listGaji &L2, list_relasi &L3);

void update_pegawai (ListPegawai &L, listGaji &L2, list_relasi &L3);
void delete_pegawai(ListPegawai &L1, listGaji &L2, list_relasi &L3);

void update_gaji(ListPegawai &L, listGaji &L2, list_relasi &L3);
void delete_gaji(ListPegawai &L, listGaji &L2, list_relasi &L3);

void menu_pegawai(ListPegawai &L, listGaji &L2, list_relasi &L3);
void menu_gaji(ListPegawai &L, listGaji &L2 , list_relasi &L3);

void menu_relasi(ListPegawai &L, listGaji &L2, list_relasi &L3);
void menu_pencarian(ListPegawai &L, listGaji &L2, list_relasi &L3);


#endif // MENU_H_INCLUDED
