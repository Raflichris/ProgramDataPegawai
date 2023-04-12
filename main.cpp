
#include <iostream>
#include <stdlib.h>
#include "pegawai.h"
#include "gaji.h"
#include "menu.h"
using namespace std;

int main()
{

ListPegawai L;
createListPegawai(L);
adr_pegawai P=alokasi("PGW01296","Andira Zahra","Supervisor","jalan puri zahara blok A-12 Medan, Sumatera Utara ","0811412346");
insertFirst(L,P);
adr_pegawai z=alokasi("PGW01295","Nurul Dian Kusumawati","Direktur Utama","jalan raya jelanggu No. 113 ","0811412346");
insertLast(L,z);
z=alokasi("PGW01200","Romi Novandri","Konsultan Perusahaan","jalan Amatir No. 221 Jakarta Pusat ","0811345123");
insertLast(L,z);
z=alokasi("PGW01201","Karin Novilda","Resepsionis","Komp. Bunga Lestari Indah Blok F-12 Jakarta Selatan ","0811345123");
insertLast(L,z);
z=alokasi("PGW01243","Amira Zalikha","HRD","Komp. Bougenville Indah Blok C-12 Bandung ","0811345123");
insertLast(L,z);


listGaji L2;
createList(L2);
address Y=alokasi("444","D","1500000");
insertFirst(L2,Y);
Y=alokasi("333","C","2000000");
insertFirst(L2,Y);
Y=alokasi("222","B","3500000");
insertFirst(L2,Y);
Y=alokasi("111","A","5500000");
insertFirst(L2,Y);






list_relasi L3;
createRelasi(L3);


menu(L,L2,L3);



}

