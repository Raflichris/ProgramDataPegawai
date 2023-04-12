#include "pegawai.h"

void createListPegawai(ListPegawai &L){
    first(L) = NULL;
    last(L) = NULL;
}

adr_pegawai alokasi(string NIP, string nama, string jabatan, string alamat, string noTelp){
    adr_pegawai P;
    P = new elmPegawai;
    info(P).NIP=NIP;
    info(P).nama=nama;
    info(P).jabatan=jabatan;
    info(P).alamat=alamat;
    info(P).noTelp=noTelp;

    prev(P) = NULL;
    next(P) = NULL;

    return P;

}

adr_pegawai updatePgw(infotype x){
    adr_pegawai P;
    P= new elmPegawai;
    info(P) = x;
    prev(P) = NULL;
    next(P) = NULL;

    return P;
}

void dealokasi(adr_pegawai &P){
    delete P;
}

adr_pegawai cariPegawai(ListPegawai L, infotype x){
   if (first(L)==NULL){
    return NULL;
   }else{
    adr_pegawai P=first(L);
    while(P!=NULL && info(P).NIP != x.NIP){
        P=next(P);
    }
    if (P==NULL){
        return NULL;
    }else{
        return P;
    }
   }

}

void printInfoPegawai(ListPegawai L){
    system("cls");
    if (first(L)==NULL){
        cout<<"[tidak ada data pegawai]"<<endl;
    }else{
        adr_pegawai P;
        P=first(L);
        int i=1;
        while(P!=NULL){
            cout<<"Data pegawai "<<i<<endl;
            cout<<"NIP      : "<<info(P).NIP<<endl;
            cout<<"Nama     : "<<info(P).nama<<endl;
            cout<<"Jabatan  : "<<info(P).jabatan<<endl;
            cout<<"Alamat   : "<<info(P).alamat<<endl;
            cout<<"No. Telp : "<<info(P).noTelp<<endl;
            cout<<endl;
            P=next(P);
            i=i+1;
        }
    }
    system("pause");
}

void insertFirst(ListPegawai &L, adr_pegawai P){
    if (first(L)==NULL){
        first(L)=P;
        last(L)=P;
    }else{
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
}


void insertLast(ListPegawai &L, adr_pegawai P){
    if (first(L)==NULL && last(L)==NULL){
        first(L) = P;
        last(L) = P;
    }
    else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void deleteFirst(ListPegawai &L, adr_pegawai &P){
    if (first(L)==NULL && last(L)==NULL){
        cout<<"[tidak ada data pegawai]"<<endl;
    }
    else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteLast(ListPegawai &L, adr_pegawai &P){
   if (first(L)==NULL && last(L)==NULL){
        cout<<"[tidak ada data pegawai]"<<endl;
    }
    else{
        P = last(L);
        last(L) = prev(last(L));
        prev(P) = NULL;
        next(last(L)) = NULL;
    }
}

void deleteAfter(ListPegawai &L, adr_pegawai q){
    if (first(L)==NULL && last(L)==NULL){
        cout<<"[tidak ada data pegawai]"<<endl;
    }
    else{
        adr_pegawai P;
        P= first(L);
        while(P!=NULL && info(P).NIP!=info(q).NIP){
             P = next(P);
        }
        prev(next(P)) = prev(P);
        next(prev(P)) = next(P);
        prev(P) = NULL;
        next(P) = NULL;
    }
}

void insertAfter(ListPegawai &L, adr_pegawai P, adr_pegawai q){
    if(prev(q) == last(L)){
       insertFirst(L,P);
    }
    else if(prev(q) == first(L)){
       insertLast(L,P);
    }
    else{
        next(q) = next(q);
        prev(next(q)) = P;
        next(q) = P;
        prev(P) = q;
    }
}
