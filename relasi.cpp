
#include "relasi.h"

void createRelasi(list_relasi &L3){
    (L3).first = NULL;
}

adr_relasi alokasi(adr_pegawai p, address q){
    adr_relasi r;
    r = new elmRelasi;
    next_pegawai(r) = p;
    next_gaji(r) = q;
    next_relasi(r) = NULL;

    return r;
}

void dealokasi(adr_relasi &r){
    delete r;
}

adr_relasi cari_relasi(list_relasi L3, adr_relasi p){
    if((L3).first == NULL){
      return  NULL;
    }
    else{
        adr_relasi q;
        q = (L3).first;
        while(q!=NULL && q!=p){
             q = next_relasi(q);
        }
        if(q != NULL){
          return q;
        }
        else{
            return NULL;
        }
    }
}

void insertFirst_relasi(list_relasi &L3, adr_relasi p){
    if((L3).first == NULL){
      (L3).first = p;
    }
    else{
        if(cari_relasi(L3,p) == NULL){
          next_relasi(p) = (L3).first;
          (L3).first = p;
        }
        else{
            cout<<"DATA SUDAH ADA"<<endl;
        }
    }
}

void deleteFirst_relasi(list_relasi &L3, adr_relasi p){
    if((L3).first == NULL){
      cout<<"[data tidak ada]"<<endl;
    }
    else{
        p = (L3).first;
        (L3).first = next_relasi(p);
        next_relasi(p) = NULL;
    }
}

void deleteLast_relasi(list_relasi &L3, adr_relasi p){
    adr_relasi q;
    if((L3).first != NULL){
      p = (L3).first;
      while(next_relasi(p) != NULL){
           q = p;
           p = next_relasi(p);
      }
      next_relasi(q) = NULL;
    }
}

void deleteAfter_relasi(list_relasi &L3, adr_relasi p){
    adr_relasi q;
    q = next_relasi(p);
    next_relasi(p) = next_relasi(q);
    next_relasi(q) = NULL;
}


void pengubung(ListPegawai &L, listGaji &L2, list_relasi &L3, infotype x, infotype_gaji y){

    cin.ignore();
    cout<<"\nMasukkan NIP Pegawai : "; getline(cin,x.NIP); cout<<endl;
    adr_pegawai p;
    p = cariPegawai(L,x);
    cout<<"Masukkan Golongan Gaji   : "; getline(cin,y.golongan); cout<<endl;
    address q;
    q = cari(L2,y);
    if((L3).first == NULL){
      if(p!=NULL && q!=NULL){
        adr_relasi r;
        r = alokasi(p,q);
        insertFirst_relasi(L3,r);
        cout<<"Data Anda Sudah Masuk"<<endl;
      }
      else{
          cout<<"Anda gagal dalam melakukan proses pendataan."<<endl;
      }
    }
    else{
        if(p!=NULL && q!=NULL){
          adr_relasi s;
          adr_relasi t;
          s = alokasi(p,q);
          t = cari_relasi(L3,s);
          if(t == NULL){
            insertFirst_relasi(L3,s);
            cout<<"Data Anda Sudah Masuk!"<<endl;
          }
          else{
              cout<<"Anda sudah melakukan pengisian data."<<endl;
          }
        }
        else{
            cout<<"Anda gagal dalam melakukan proses pendataan."<<endl;
        }
    }
}

void tampil_berdasarkan_gaji(listGaji L2, list_relasi L3){
    address p;
    p = (L2).first;
    while(p != NULL){
         cout<<"------------------------------------------------------------------------------"<<endl;
         cout<<"Kode Gaji    : "<<info(p).kode_gaji<<endl;
         cout<<"Golongan     : "<<info(p).golongan<<endl;
         cout<<"Gaji         : "<<info(p).gaji<<endl;
         cout<<"------------------------------------------------------------------------------"<<endl;
         adr_relasi q;
         q = (L3).first;
         int i=1;
         while(q != NULL){
              if(p == next_gaji(q)){
                cout<<i<<". ";
                cout<<"NIP              : "<<q->next_pegawai->info.NIP<<endl;
                cout<<"   Nama             : "<<q->next_pegawai->info.nama<<endl;
                cout<<" "<<endl;
                cout<<" "<<endl;
                i=i+1;
              }
              q = next_relasi(q);
         }
         p = next(p);
    }
    system("pause");
}

void tampil_berdasarkan_pegawai(ListPegawai L, list_relasi L3){
    adr_pegawai p;
    system("cls");
    p = first(L);
    while(p != NULL){
         cout<<"------------------------------------------------------------------------------"<<endl;
         cout<<"NIP              : "<<info(p).NIP<<endl;
         cout<<"Nama             : "<<info(p).nama<<endl;
         cout<<"Jabatan          : "<<info(p).jabatan<<endl;
         cout<<"Alamat           : "<<info(p).alamat<<endl;
         cout<<"No telp          : "<<info(p).noTelp<<endl;
         cout<<""<<endl;
         adr_relasi q;
         q = (L3).first;
         while(q != NULL){
              if(p == next_pegawai(q)){
                cout<<"kode gaji          : "<<q->next_gaji->info.kode_gaji<<endl;
                cout<<"golongan           : "<<q->next_gaji->info.golongan<<endl;
                cout<<"gaji               : "<<q->next_gaji->info.gaji<<endl;
                cout<<" "<<endl;
                cout<<" "<<endl;
              }
              q = next_relasi(q);
         }
         p = next(p);
    }
    system("pause");
}

void tampil_berdasarkan_pegawai_tertentu (ListPegawai L, list_relasi L3){
    adr_pegawai y;
    infotype x;
    cout<<"Masukkan Data Pegawai yang Ingin di Cari."<<endl;
    cout<<"NIP : ";
    cin>>x.NIP;
    y=cariPegawai(L,x);
    adr_relasi a;
    a=(L3).first;
    if (y!=NULL){
        while(a!=NULL){
            if (next_pegawai(a)==y){
                cout<<"Nama     : "<<a->next_pegawai->info.nama<<endl;
                cout<<"Golongan : "<<a->next_gaji->info.golongan<<endl;
                cout<<"Gaji     : "<<a->next_gaji->info.gaji<<endl;
            }
            a=next_relasi(a);
        }

    }

}

void tampil_berdasarkan_gaji_tertentu (listGaji L2, list_relasi L3){
    address y;
    infotype_gaji x;
    cout<<"Masukkan Golongan Gaji yang Ingin di Cari."<<endl;
    cout<<"Golongan : ";
    cin>>x.golongan;
    y=cari(L2,x);
    adr_relasi a;
    a=(L3).first;
    if (y!=NULL){
        while(a!=NULL){
            if (next_gaji(a)==y){
                cout<<"Golongan   : "<<a->next_gaji->info.golongan<<endl;
                cout<<"NIP        : "<<a->next_pegawai->info.NIP<<endl;
                cout<<"Nama       : "<<a->next_pegawai->info.nama<<endl;
            }
            a=next_relasi(a);
        }

    }


}
