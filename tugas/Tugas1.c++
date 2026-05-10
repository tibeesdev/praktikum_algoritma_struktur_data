#include <conio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan[2];
string dataBaru, dataHapus;

void init();
int isEmpty();
int hitungNode();

void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main()
{
    init();
    do {
        cout<<"Single Linked List Circular (SLLC)"<<endl;
        cout<<"===================================="<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampilkan Data"<<endl;
        cout<<"6. Hapus Semua Elemen"<<endl;
        cout<<"7. Cari Data"<<endl;
        cout<<"8. Hapus Setiap Data Tertentu"<<endl;
        cout<<"9. Sisipkan Node/Data Baru Sebelum Data Tertentu"<<endl;
        cout<<"10. Sisipkan Node/Data Baru Setelah Data Tertentu"<<endl;
        cout<<"11. Quit"<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        pil=atoi(pilihan);

        switch(pil) {
            case 1:  tambahDepan();  break;
            case 2:  tambahBelakang(); break;
            case 3:  hapusDepan();   break;
            case 4:  hapusBelakang(); break;
            case 5:  tampilkan();    break;
            case 6:  reset();        break;
            case 7:  cariData();     break;
            case 8:  hapusData();    break;
            case 9:  sisipkanSebelum(); break;
            case 10: sisipkanSetelah(); break;
            default:
                cout<<"\nTERIMA KASIH"<<endl;
                cout<<"Program was made by Ahmad Tibrizi (2510817210027)."<<endl;
        }

        cout<<"\nPress any key to continue!"<<endl;
        getch();
        system("cls");

    } while (pil<11);
}

void init(){
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if(head == NULL) return 1;
    else return 0;
}

int hitungNode() {
    if(isEmpty()) return 0;
    int count = 0;
    TNode *bantu = head;
    do {
        count++;
        bantu = bantu->next;
    } while(bantu != head);
    return count;
}

void tambahDepan() {
    string baris;
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    getline(cin, baris);

    istringstream iss(baris);
    vector<string> tokens;
    string token;
    while(iss >> token) {
        tokens.push_back(token);
    }

    if(tokens.empty()) {
        cout<<"Tidak ada data yang dimasukkan."<<endl;
        return;
    }

    for(int i = (int)tokens.size() - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = tokens[i];
        baru->next = baru;

        if(isEmpty()) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head = baru;
            tail->next = head;
        }
    }

    cout<<"Data \""<<baris<<"\" berhasil dimasukkan di bagian depan."<<endl;
}

void tambahBelakang() {
    cout<<"Masukkan data : ";
    TNode *baru = new TNode;
    cin>>dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if(isEmpty() == 1) {
        head = baru; tail = baru;
    } else {
        tail->next = baru; tail = baru; tail->next = head;
    }
    cout<<"Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian belakang."<<endl;
}

void hapusDepan() {
    if(isEmpty() == 0) {
        int N, total;
        cout<<"Masukkan posisi node ke-N dari depan yang ingin dihapus : ";
        cin>>N;

        total = hitungNode();

        if(N > total) {
            cout<<"N ("<<N<<") lebih besar dari jumlah node ("<<total
                <<"). Node tail yang akan dihapus."<<endl;
            N = total;
        }

        TNode *hapus;

        if(N == 1) {
            hapus = head;
            dataHapus = hapus->data;
            if(head != tail) { head = head->next; tail->next = head; }
            else init();
        } else if(N == total) {
            TNode *newTail = head;
            for(int i = 1; i < total - 1; i++) newTail = newTail->next;
            hapus = tail;
            dataHapus = hapus->data;
            tail = newTail;
            tail->next = head;
        } else {
            TNode *sebelum = head;
            for(int i = 1; i < N - 1; i++) sebelum = sebelum->next;
            hapus = sebelum->next;
            dataHapus = hapus->data;
            sebelum->next = hapus->next;
        }

        cout<<"Data \""<<dataHapus<<"\" pada posisi ke-"<<N
            <<" dari depan telah berhasil dihapus."<<endl;
        delete hapus;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void hapusBelakang() {
    if(isEmpty() == 0) {
        int N, total;
        cout<<"Masukkan posisi node ke-N dari belakang yang ingin dihapus : ";
        cin>>N;

        total = hitungNode();

        if(N > total) {
            cout<<"N ("<<N<<") lebih besar dari jumlah node ("<<total
                <<"). Node head yang akan dihapus."<<endl;
            N = total;
        }

        // Konversi: posisi dari belakang ke-N = posisi dari depan ke-(total-N+1)
        int posiDariDepan = total - N + 1;

        TNode *hapus;

        if(posiDariDepan == 1) {
            hapus = head;
            dataHapus = hapus->data;
            if(head != tail) { head = head->next; tail->next = head; }
            else init();
        } else if(posiDariDepan == total) {
            TNode *newTail = head;
            for(int i = 1; i < total - 1; i++) newTail = newTail->next;
            hapus = tail;
            dataHapus = hapus->data;
            tail = newTail;
            tail->next = head;
        } else {
            TNode *sebelum = head;
            for(int i = 1; i < posiDariDepan - 1; i++) sebelum = sebelum->next;
            hapus = sebelum->next;
            dataHapus = hapus->data;
            sebelum->next = hapus->next;
        }

        cout<<"Data \""<<dataHapus<<"\" pada posisi ke-"<<N
            <<" dari belakang telah berhasil dihapus."<<endl;
        delete hapus;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void tampilkan() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        do {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        } while(bantu != head);
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void reset() {
    if(isEmpty() == 0) {
        int nodeKe = 1;
        while(!isEmpty()) {
            TNode *hapus = head;
            cout<<"Menghapus node ke-"<<nodeKe<<" : \""<<hapus->data<<"\""<<endl;
            if(head != tail) { head = head->next; tail->next = head; }
            else init();
            delete hapus;
            nodeKe++;
        }
        cout<<"Seluruh elemen pada Linked List telah dibersihkan."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void cariData() {
    if(isEmpty() == 0) {
        string cari;
        cout<<"Masukkan data yang ingin dicari : ";
        cin>>cari;

        TNode *bantu = head, *bantuTampilkan;
        bool apaDitemukan = false;

        do {
            if(cari == bantu->data){
                cout<<"Setiap data yang berada di dalam tanda kurung siku ([...]) "
                    <<"merupakan data yang anda cari."<<endl;
                cout<<"Linked List : ";
                bantuTampilkan = head;
                do {
                    if(cari == bantuTampilkan->data) cout<<"["<<bantuTampilkan->data<<"] ";
                    else cout<<bantuTampilkan->data<<' ';
                    bantuTampilkan = bantuTampilkan->next;
                } while(bantuTampilkan != head);
                apaDitemukan = true;
                cout<<endl;
                break;
            }
            bantu = bantu->next;
        } while(bantu != head);

        if(!apaDitemukan)
            cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void hapusData() {
    if(isEmpty() == 0) {
        string cari;
        cout<<"Masukkan data yang ingin dihapus : ";
        cin>>cari;

        TNode *bantu, *sebelum, *hapus[255], *bantu2;
        int hitung = 0;
        bool apaDitemukan = false;
        bantu = head;

        do {
            bantu2 = bantu;
            if(cari == bantu->data){
                hapus[hitung++] = bantu;
                apaDitemukan = true;
                if(bantu != head && bantu != tail) {
                    sebelum->next = bantu->next;
                    bantu2 = sebelum;
                }
            }
            sebelum = bantu2;
            bantu = bantu->next;
        } while(bantu != head);

        if(apaDitemukan) {
            for(int i = 0; i < hitung; i++) {
                if(hapus[i] == head){
                    TNode *h = head;
                    if(head != tail) { head = head->next; tail->next = head; } else init();
                    delete h;
                } else if(hapus[i] == tail) {
                    TNode *newTail = head;
                    while(newTail->next != tail) newTail = newTail->next;
                    TNode *h = tail;
                    tail = newTail; tail->next = head;
                    delete h;
                } else {
                    delete hapus[i];
                }
            }
            cout<<"Setiap data \""<<cari<<"\" yang terdapat pada Linked List telah dihapus."<<endl;
        } else cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void sisipkanSebelum() {
    if(isEmpty() == 0) {
        TNode *bantu = head, *sebelum = tail;
        string nextData;
        bool apaAda = false;

        cout<<"Sisipkan data baru sebelum data : ";
        cin>>nextData;

        do {
            if(nextData == bantu->data){ apaAda = true; break; }
            else { sebelum = bantu; bantu = bantu->next; }
        } while(bantu != head);

        if(apaAda) {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>dataBaru;
            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu;
            sebelum->next = baru;
            if(bantu == head) head = baru;
            cout<<"Data \""<<dataBaru<<"\" berhasil disisipkan sebelum data \""<<nextData<<"\"."<<endl;
        } else cout<<"Tidak terdapat data \""<<nextData<<"\" pada Linked List."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void sisipkanSetelah() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        string prevData;
        bool apaAda = false;

        cout<<"Sisipkan data baru setelah data : ";
        cin>>prevData;

        do {
            if(prevData == bantu->data){ apaAda = true; break; }
            else bantu = bantu->next;
        } while(bantu != head);

        if(apaAda) {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>dataBaru;
            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu->next;
            bantu->next = baru;
            if(bantu == tail) tail = baru;
            cout<<"Data \""<<dataBaru<<"\" berhasil disisipkan setelah data \""<<prevData<<"\"."<<endl;
        } else cout<<"Tidak terdapat data \""<<prevData<<"\" pada Linked List."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}