
#ifndef GAJI_H_INCLUDED
#define GAJI_H_INCLUDED

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct infotype_gaji{
    string kode_gaji;
    string golongan;
    string gaji;

};

typedef struct elmGaji *address;

struct elmGaji {
    infotype_gaji info;
    address next;
    address prev;
};

struct listGaji {
    address first;
    address last;
};

void createList(listGaji &L2);
address alokasi(string kode_gaji, string golongan, string gaji);
address updateGaji (infotype_gaji x);

void dealokasi(address &P);

address cari(listGaji L2, infotype_gaji x);
void printInfo(listGaji L2);

void insertFirst(listGaji &L2, address P);
void insertLast(listGaji &L2, address P);

void deleteFirst(listGaji &L2, address &P);
void deleteLast(listGaji &L2, address &P);
void deleteAfter(listGaji &L2, address Q);

void insertAfter(listGaji &L2, address P, address Q);





#endif // GAJI_H_INCLUDED
