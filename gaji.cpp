
#include "gaji.h"

using namespace std;

void createList(listGaji &L2){
    (L2).first = NULL;
    (L2).last = NULL;
}

address alokasi(string kode_gaji, string golongan, string gaji){
    address P;
    P = new elmGaji;
    info(P).kode_gaji=kode_gaji;
    info(P).golongan=golongan;
    info(P).gaji=gaji;

    prev(P) = NULL;
    next(P) = NULL;

    return P;
}

address updateGaji(infotype_gaji x){
    address P;
    P = new elmGaji;
    info(P) = x;
    prev(P) = NULL;
    next(P) = NULL;

    return P;
}


void dealokasi(address &P){
    delete P;
}

address cari(listGaji L2, infotype_gaji x){
   if ((L2).first==NULL){
    return NULL;
   }else{
    address P=(L2).first;
    while(P!=NULL && info(P).kode_gaji != x.kode_gaji){
        P=next(P);
    }
    if (P==NULL){
        return NULL;
    }else{
        return P;
    }
   }

}

void printInfo(listGaji L2) {
    system("cls");
    if((L2).first == NULL){
       cout<<"[Daftar Gaji Kosong]"<<endl;
     }
     else{
         address P;
         P = (L2).first;
         while(P != NULL){
              cout<<"Kode Gaji : ";
              cout<<info(P).kode_gaji<<endl;
              cout<<"Golongan : ";
              cout<<info(P).golongan<<endl;
              cout<<"Gaji : ";
              cout<<info(P).gaji<<endl;
              cout<<"________________________________"<<endl;
              P=next(P);
         }
    }
    system("pause");

}

void insertFirst(listGaji &L2, address P){
    if ((L2).first==NULL){
        (L2).first = P;
        (L2).last = P;
    }
    else{
        next(P) = (L2).first;
        prev((L2).first) = P;
        (L2).first = P;
    }
}

void insertLast(listGaji &L2, address P){
    if ((L2).first==NULL && (L2).last==NULL){
        (L2).first = P;
        (L2).last = P;
    }
    else{
        next((L2).first) = P;
        prev(P) = (L2).last;
        (L2).last = P;
    }
}

void deleteFirst(listGaji &L2, address &P){
    if ((L2).first==NULL && (L2).last==NULL){
        cout<<"List Kosong"<<endl;
    }
    else{
        P = (L2).first;
        (L2).first = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deleteLast(listGaji &L2, address &P){
    if ((L2).first==NULL && (L2).last==NULL){
        cout<<"List Kosong"<<endl;
    }
    else{
        P = (L2).last;
        (L2).last = prev ((L2).last);
        prev(P) = NULL;
        next((L2).last) = NULL;
    }
}
void deleteAfter(listGaji &L2, address Q){
    if ((L2).first==NULL && (L2).last==NULL){
        cout<<"Delete Gagal, List Kosong"<<endl;
    }
    else{
        address p;
        p = (L2).first;
        while(p!=NULL && info(p).kode_gaji!=info(Q).kode_gaji){
             p = next(p);
        }
        prev(next(p)) = prev(p);
        next(prev(p)) = next(p);
        prev(p) = NULL;
        next(p) = NULL;
    }
}

void insertAfter(listGaji &L2, address P, address Q){
    if(prev(Q) == (L2).last){
       insertFirst(L2,P);
    }
    else if(prev(Q) == (L2).first){
       insertLast(L2,P);
    }
    else{
        next(Q) = next(Q);
        prev(next(Q)) = P;
        next(Q) = P;
        prev(P) = Q;
    }
}
