
#include "menu.h"


void menu(ListPegawai &L, listGaji &L2, list_relasi &L3)
{
    int pilih;
    system("cls");
    cout<<" "<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"                               DATA PEGAWAI"<<endl;
    cout<<"                     PT. BENIH MERAH PUTIH INDONESIA"<<endl;
    cout<<" ----------------------------------------------------------------------------- "<<endl;
    cout<<" "<<endl;
    cout<<"1. DAFTAR PEGAWAI"<<endl;
    cout<<"2. DAFTAR GAJI"<<endl;
    cout<<"3. PENDATAAN GAJI PEGAWAI"<<endl;
    cout<<"4. PENCARIAN"<<endl;
    cout<<" "<<endl;
    cout<<"Pilihan Anda: "; cin>>pilih; cout<<endl;
    if(pilih == 1){
           menu_pegawai(L,L2,L3);
    }
    else if(pilih == 2){
           menu_gaji(L,L2,L3);
    }
    else if(pilih == 3){
           menu_relasi(L,L2,L3);
    }
    else if (pilih==4){
        menu_pencarian(L,L2,L3);
    }
}

void update_pegawai(ListPegawai &L, listGaji &L2, list_relasi &L3)
{
    infotype pegawai;
    cout<<"Masukkan data diri Anda dengan benar!"<<endl;
    cin.ignore();
    cout<<"NIP             : "; getline(cin,pegawai.NIP); cout<<endl;
    cout<<"Nama            : "; getline(cin,pegawai.nama); cout<<endl;
    cout<<"Jabatan         : "; getline(cin,pegawai.jabatan); cout<<endl;
    cout<<"Alamat          : "; getline(cin,pegawai.alamat); cout<<endl;
    cout<<"No. Telp        : "; getline(cin,pegawai.noTelp); cout<<endl;
    adr_pegawai a;
    a = updatePgw(pegawai);
    adr_pegawai a1;
    a1 = cariPegawai(L,pegawai);
    if(a1 != NULL){
      cout<<"Data yang anda masukkan sudah ada!"<<endl;
    }
    else{
        insertLast(L,a);
        cout<<"Data berhasil ditambahkan"<<endl;
    }
    system("pause");
    menu_pegawai(L,L2,L3);
}

void delete_pegawai(ListPegawai &L, listGaji &L2, list_relasi &L3)
{
    infotype pegawai;
    cout<<"Masukkan NIP pegawai yang ingin dihapus!"<<endl;
    cin.ignore();
    cout<<"NIP Pegawai : "; getline(cin,pegawai.NIP); cout<<endl;
    adr_pegawai b;
    b = cariPegawai(L,pegawai);
    if(b == NULL){
      cout<<"data peserta tidak di temukan, penghapusan gagal."<<endl;
    }
    else{
        if(b == first(L)){
          deleteFirst(L,b);
        }
        else if(b == last(L)){
               deleteLast(L,b);
        }
        else{
            adr_pegawai r;
            r = prev(b);
            deleteAfter(L,b);
        }
        cout<<"Data Anda berhasil dihapus!"<<endl;
    }
    system("pause");
    menu_pegawai(L,L2,L3);
}



void menu_pegawai(ListPegawai &L, listGaji &L2, list_relasi &L3)
{
    int pilih;
    do
    {
        system("cls");
        cout<<" "<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"                          DATA PEGAWAI"<<endl;
        cout<<"                   PT. BENIH MERAH PUTIH INDONESIA"<<endl;
        cout<<" ----------------------------------------------------------------------------- "<<endl;
        cout<<" "<<endl;
        cout<<"1. Menambah data pegawai"<<endl;
        cout<<"2. Menghapus data pegawai"<<endl;
        cout<<"3. Menampilkan data pegawai"<<endl;
        cout<<"tekan tombol '0' untuk kembali"<<endl;
        cout<<" "<<endl;
        cout<<"Pilihan Anda: "; cin>>pilih;
        cout<<endl;
        if(pilih == 1){
          update_pegawai(L,L2,L3);
        }
        else if (pilih == 2){
               delete_pegawai(L,L2,L3);
        }
        else if(pilih == 0){
               menu(L,L2,L3);
        }else if(pilih== 3){
            printInfoPegawai(L);
        }

    }
    while(pilih != 0);
}

void update_gaji(ListPegawai &L, listGaji &L2, list_relasi &L3){
    infotype_gaji salary;
    cout<<"Masukkan data dengan benar!"<<endl;
    cin.ignore();
    cout<<"Kode Gaji             : "; getline(cin,salary.kode_gaji); cout<<endl;
    cout<<"Golongan              : "; getline(cin,salary.golongan); cout<<endl;
    cout<<"Gaji                  : "; getline(cin,salary.gaji); cout<<endl;
    address c;
    c = updateGaji(salary);
    address c1;
    c1 = cari(L2,salary);
    if(c1 != NULL){
      cout<<"Daftar Gaji Sudah ada."<<endl;
    }
    else{
        insertLast(L2,c);
        cout<<"Daftar gaji berhasil ditambahkan."<<endl;
    }
    system("pause");
    menu_gaji(L,L2,L3);

}
void delete_gaji(ListPegawai &L, listGaji &L2, list_relasi &L3){
    infotype_gaji salary;
    cout<<"Masukkan NIP pegawai yang ingin dihapus!"<<endl;
    cin.ignore();
    cout<<"kode_gaji : "; getline(cin,salary.kode_gaji); cout<<endl;
    address b;
    b = cari(L2,salary);
    if(b == NULL){
      cout<<"daftar gaji tidak di temukan, penghapusan gagal."<<endl;
    }
    else{
        if(b == (L2).first){
          deleteFirst(L2,b);
        }
        else if(b == (L2).last){
               deleteLast(L2,b);
        }
        else{
            address r;
            r = prev(b);
            deleteAfter(L2,b);
        }
        cout<<"Daftar gaji berhasil dihapus!"<<endl;
    }
    system("pause");
    menu_gaji(L,L2,L3);

}

void menu_gaji(ListPegawai &L, listGaji &L2, list_relasi &L3)
{
    int pilih;
    do
    {
        system("cls");
        cout<<" "<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"                              DATA PEGAWAI"<<endl;
        cout<<"                    PT. BENIH PUTIH MERAH INDONESIA"<<endl;
        cout<<" ----------------------------------------------------------------------------- "<<endl;
        cout<<" "<<endl;
        cout<<"1. Penambahan Daftar Gaji"<<endl;
        cout<<"2. Penghapusan Daftar Gaji"<<endl;
        cout<<"3. Menampilkan Daftar Gaji"<<endl;
        cout<<"tekan tombol '0' untuk kembali"<<endl;
        cout<<" "<<endl;
        cout<<"Pilihan Anda: "; cin>>pilih;
        cout<<endl;
        if(pilih == 1){
          update_gaji(L,L2,L3);
        }
        else if (pilih == 2){
               delete_gaji(L,L2,L3);
        }
        else if(pilih == 0){
               menu(L,L2,L3);
        }
        else if(pilih==3){
            printInfo(L2);
        }
    }
    while(pilih != 0);
}

void menu_relasi(ListPegawai &L, listGaji &L2, list_relasi &L3)
{
    system("cls");
    cout<<" "<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"                             DATA PEGAWAI"<<endl;
    cout<<"                   PT. BENIH PUTIH MERAH INDONESIA"<<endl;
    cout<<" ----------------------------------------------------------------------------- "<<endl;
    cout<<" "<<endl;
    infotype x;
    infotype_gaji y;
    pengubung(L,L2,L3,x,y);
    system("pause");
    menu(L,L2,L3);
}

void menu_pencarian(ListPegawai &L, listGaji &L2, list_relasi &L3)
{
    int pilih;
    do
    {
        system("cls");
        cout<<" "<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"                                DATA PEGAWAI"<<endl;
        cout<<"                       PT. BENIH PUTIH MERAH INDONESIA"<<endl;
        cout<<" ----------------------------------------------------------------------------- "<<endl;
        cout<<" "<<endl;
        cout<<"1. Menampilkan Seluruh Data Berdasarkan Gaji"<<endl;
        cout<<"2. Menampilkan Seluruh Data Berdasarkan Pegawai"<<endl;
        cout<<"3. Menampilkan Data Pegawai Berdasarkan Kode Gaji"<<endl;
        cout<<"4. Menampilkan Data Gaji Pegawai Tertentu"<<endl;
        cout<<"5. Menampilkan Urutan Data Pegawai"<<endl;
        cout<<"Untuk kembali ke menu sebelumnya, tekan tombol '0'"<<endl;
        cout<<" "<<endl;
        cout<<"Pilihan Anda: "; cin>>pilih; cout<<endl;
        if(pilih == 1){
          if((L2).first == NULL){
            cout<<"[daftar gaji kosong]"<<endl;
            system("pause");
          }else{
            tampil_berdasarkan_gaji(L2,L3);
          }
        }else if (pilih==2){
            if((L).first==NULL){
                cout<<"[daftar pegawai kosong]"<<endl;
                system("pause");
            }else{
                tampil_berdasarkan_pegawai(L,L3);
            }
        }else if (pilih==0){
            menu(L,L2,L3);
        }else if (pilih==4){
            tampil_berdasarkan_pegawai_tertentu (L,L3);
            system("pause");
        }else if(pilih==3){
            tampil_berdasarkan_gaji_tertentu (L2,L3);
            system("pause");
        }
    }
    while(pilih != 0);
}
