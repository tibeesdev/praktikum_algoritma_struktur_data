#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();
void hapusTargetH();
void clearSelangSelingH();
void hapusTargetHT();
void clearSelangSelingHT();


int main()
{
    menu:
    cout<<"Double Linked List Circular (DLLNC)"<<endl;
    cout<<"==================================="<<endl;
    cout<<"Silahkan pilih program DLLNC yang ingin dijalankan!"<<endl;
    cout<<"1. DLLNC dengan Head"<<endl;
    cout<<"2. DLLNC dengan Head dan Tail"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Pilihan : "<<endl;
    cin>>menu;
    system("cls");
    if (menu == 1){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head)"<<endl;
            cout<<"=============================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Target"<<endl;
            cout<<"7. Reset"<<endl;
            cout<<"8. Reset Selang Seling"<<endl;
            cout<<"9. Kembali ke Menu"<<endl;
            cout<<"Pilihan : "<<endl;
            cin>>pilihan;
            pil=atoi(pilihan);

            switch (pil){
            case 1:
                tambahDepanH();
                break;
            case 2:
                tambahBelakangH();
                break;
            case 3:
                tampilkanH();
                break;
            case 4:
                hapusDepanH();
                break;
            case 5:
                hapusBelakangH();
                break;
            case 6:
                hapusTargetH();
                break;
            case 7:
                clearH();
                break;
            case 8:
                clearSelangSelingH();
                break;
            default:
                system("cls");
                goto menu;
            }

            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");

        } while (pil<9);
    } else if (menu == 2){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head dan Tail)"<<endl;
            cout<<"=============================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Target"<<endl;
            cout<<"7. Reset"<<endl;
            cout<<"8. Reset Selang Seling"<<endl;
            cout<<"9. Kembali ke Menu"<<endl;
            cout<<"Pilihan : "<<endl;
            cin>>pilihan;
            pil=atoi(pilihan);

            switch (pil){
            case 1:
                tambahDepanHT();
                break;
            case 2:
                tambahBelakangHT();
                break;
            case 3:
                tampilkanHT();
                break;
            case 4:
                hapusDepanHT();
                break;
            case 5:
                hapusBelakangHT();
                break;
            case 6:
                hapusTargetHT();
                break;
            case 7:
                clearHT();
                break;
            case 8:
                clearSelangSelingHT();
                break;
            default:
                system("cls");
                goto menu;
            }

            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");

        } while (pil<9);   
    } else {
        cout<<"\nTERIMA KASIH"<<endl;
        cout<<"Program was made by Ahnmad Tibrizi (2510817210027)."<<endl;
    }
}

void initH(){
    head = NULL;
}

void initHT(){
    head = NULL;
    tail = NULL;
}

int isEmptyH(){
    if (head == NULL) return 1;
    else return 0;
}

int isEmptyHT(){
    if (tail == NULL) return 1;
    return 0;
}

void tambahDepanH(){
    string baris;
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    getline(cin, baris);

    istringstream iss(baris);
    vector<string> tokens;
    string token;
    while(iss >> token){
        tokens.push_back(token);
    }

    if(tokens.empty()){
        cout<<"Tidak ada data yang dimasukkan." <<endl;
        return;
    }

    for(int i = (int)tokens.size() - 1; i >= 0; i--){
        TNode *baru;
        baru = new TNode;
        baru->data = tokens[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyH() == 1){
            head = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }

    cout << "Data \""<<baris<<"\" berhasil dimasukkan di bagian depan.";
}

void tambahDepanHT() {
    string baris;
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore(); 
    getline(cin, baris);

    istringstream iss(baris);
    vector<string> tokens;
    string token;
    while(iss >> token) {
        tokens.push_back(token);
    }

    if(tokens.empty()) {
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    for(int i = (int)tokens.size() - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = tokens[i];
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyHT() == 1) {
            head = baru;
            tail = baru; 
        } else {
            baru->next = head; 
            head->prev = baru;
            head = baru;      
        }
    }

    cout << "Data \"" << baris << "\" berhasil dimasukkan di bagian depan." << endl;
}
void tambahBelakangH(){
    string baris;
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore(); 
    getline(cin, baris);

    istringstream iss(baris);
    vector<string> tokens;
    string token;
    while(iss >> token){
        tokens.push_back(token);
    }

    if(tokens.empty()){
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    for(int i = 0; i < (int)tokens.size(); i++){
        TNode *baru = new TNode;
        baru->data = tokens[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyH() == 1){
            head = baru;
        } else {
            TNode *bantu = head;
            while (bantu->next != NULL){
                bantu = bantu->next;
            }
            bantu->next = baru;
            baru->prev = bantu;
        }
    }
    
    cout << "Data \"" << baris << "\" berhasil dimasukkan di bagian belakang." << endl;
}
    
void tambahBelakangHT(){
    string baris;
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore(); 
    getline(cin, baris);

    istringstream iss(baris);
    vector<string> tokens;
    string token;
    while(iss >> token){
        tokens.push_back(token);
    }

    if(tokens.empty()){
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    for(int i = 0; i < (int)tokens.size(); i++){
        TNode *baru = new TNode;
        baru->data = tokens[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyHT() == 1){
            head = baru;
            tail = baru; 
        } else {
            tail->next = baru; 
            baru->prev = tail; 
            tail = baru;      
        }
    }

    cout << "Data \"" << baris << "\" berhasil dimasukkan di bagian belakang." << endl;
}

void tampilkanH(){
    TNode *bantu;
    bantu = head;
    if(isEmptyH() == 0){
        while (bantu != NULL) {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List";
}

void tampilkanHT() {
    TNode *bantu;
    bantu = head;
    if (isEmptyHT() == 0) {
        while (bantu != tail->next){
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List";  
}

void hapusTargetH() {
    if (isEmptyH() == 1) {
        cout << "Tidak terdapat data pada linked list." << endl;
        return;
    }

    string target;
    cout << "Masukkan data target yang ingin dihapus : ";
    cin >> target;

    TNode *bantu = head;
    bool ditemukan = false;
    int indeks = 0;

    while (bantu != NULL) {
        TNode *nextNode = bantu->next; 

        if (bantu->data == target) {
            ditemukan = true;
            TNode *hapus = bantu;

            if (hapus == head) {
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } 
            else {
                hapus->prev->next = hapus->next;
                if (hapus->next != NULL) {
                    hapus->next->prev = hapus->prev;
                }
            }
            delete hapus;
        cout << "Data \"" << target << "\" pada indeks ke-" << indeks << " berhasil dihapus." << endl;        }
        bantu = nextNode; 
        indeks++;
    }

    if (!ditemukan) {
        cout << "Data target \"" << target << "\" tidak ditemukan di dalam list!" << endl;
    }
}

void hapusTargetHT() {
    if (isEmptyHT() == 1) {
        cout << "Tidak terdapat data pada linked list." << endl;
        return;
    }

    string target;
    cout << "Masukkan data target yang ingin dihapus : ";
    cin >> target;

    TNode *bantu = head;
    bool ditemukan = false;
    int indeks = 0;

    while (bantu != NULL) {
        TNode *nextNode = bantu->next;

        if (bantu->data == target) {
            ditemukan = true;
            TNode *hapus = bantu;

            if (hapus == head && hapus == tail) {
                head = NULL;
                tail = NULL;
            } 
            else if (hapus == head) {
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } 
            else if (hapus == tail) {
                tail = tail->prev;
                if (tail != NULL) {
                    tail->next = NULL;
                }
            } 
            else {
                hapus->prev->next = hapus->next;
                hapus->next->prev = hapus->prev;
            }

            delete hapus;
        cout << "Data \"" << target << "\" pada indeks ke-" << indeks << " berhasil dihapus." << endl;        }

        bantu = nextNode;
        indeks++;
    }

    if (!ditemukan) {
        cout << "Data target \"" << target << "\" tidak ditemukan di dalam list!" << endl;
    }
}

void hapusDepanH() {
    TNode *hapus;
    string data;
    if (isEmptyH() == 0) {
        hapus = head;
        data = hapus->data;
        if (head->next != NULL){
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout<<"Data\""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada linked list";
}

void hapusDepanHT() {
    TNode *hapus;
    string data;
    if (isEmptyHT() == 0) {
        hapus = head;
        data = hapus->data;
        if (head->next != NULL){
            head = head->next;
            head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout<<"Data\""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}

void hapusBelakangH() {
    if (isEmptyH() == 1) {
        cout << "Tidak terdapat data pada linked list." << endl;
        return;
    }

    int N;
    cout << "Masukkan posisi node yang ingin dihapus dari belakang (N): ";
    cin >> N;

    if (N <= 0) {
        cout << "Nilai N harus lebih besar dari 0!" << endl;
        return;
    }

    int totalNode = 0;
    TNode *bantu = head;
    while (bantu != NULL) {
        totalNode++;
        bantu = bantu->next;
    }

    int posisiHapusDariBelakang = N;
    if (N > totalNode) {
        posisiHapusDariBelakang = N % totalNode;
        if (posisiHapusDariBelakang == 0) {
            posisiHapusDariBelakang = totalNode; 
        }
    }

    int targetPosisiDepan = totalNode - posisiHapusDariBelakang + 1;

    bantu = head;
    for (int i = 1; i < targetPosisiDepan; i++) {
        bantu = bantu->next;
    }

    TNode *hapus = bantu;
    string dataDihapus = hapus->data;

    if (hapus == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } 
    else {
        hapus->prev->next = hapus->next;
        if (hapus->next != NULL) {
            hapus->next->prev = hapus->prev;
        }
    }

    delete hapus;
    cout << "Node ke-" << N << " dari belakang (Data: \"" << dataDihapus << "\") berhasil dihapus." << endl;
}

void hapusBelakangHT() {
    if (isEmptyHT() == 1) {
        cout << "Tidak terdapat data pada linked list." << endl;
        return;
    }

    int N;
    cout << "Masukkan posisi node yang ingin dihapus dari belakang (N): ";
    cin >> N;

    if (N <= 0) {
        cout << "Nilai N harus lebih besar dari 0!" << endl;
        return;
    }

    int totalNode = 0;
    TNode *bantu = head;
    while (bantu != NULL) {
        totalNode++;
        bantu = bantu->next;
    }

    int posisiHapusDariBelakang = N;
    if (N > totalNode) {
        posisiHapusDariBelakang = N % totalNode;
        if (posisiHapusDariBelakang == 0) {
            posisiHapusDariBelakang = totalNode;
        }
    }

    bantu = tail;
    for (int i = 1; i < posisiHapusDariBelakang; i++) {
        bantu = bantu->prev; // Berjalan mundur lewat link prev
    }

    TNode *hapus = bantu;
    string dataDihapus = hapus->data;

    if (hapus == head && hapus == tail) {
        head = NULL;
        tail = NULL;
    } 
    else if (hapus == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } 
    else if (hapus == tail) {
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
    } 
    else {
        hapus->prev->next = hapus->next;
        hapus->next->prev = hapus->prev;
    }

    delete hapus;
    cout << "Node ke-" << N << " dari belakang (Data: \"" << dataDihapus << "\") berhasil dihapus." << endl;
}

void clearSelangSelingH() {
    if (isEmptyH() == 1) {
        cout << "Linked list sudah kosong." << endl;
        return;
    }

    int urutan = 1; 
    bool hapusDepan = true; 

    cout << "=== MEMULAI PROSES CLEAR SELANG-SELING ===" << endl; 

    while (isEmptyH() != 1) {
        TNode *hapus = NULL;

        if (hapusDepan) {
            hapus = head;
            
            if (head->next != NULL) {
                head = head->next;
                head->prev = NULL;
            } else {
                head = NULL; 
            }
            
            hapusDepan = false; 
        } 
        else {
            TNode *bantu = head;
            while (bantu->next != NULL) {
                bantu = bantu->next;
            }
            hapus = bantu;

            if (hapus->prev != NULL) {
                hapus->prev->next = NULL;
            } else {
                head = NULL;
            }

            hapusDepan = true;
        }

        cout << "Penghapusan ke-" << urutan << " : Node bertuliskan \"" 
             << hapus->data << "\" berhasil dihapus." << endl;

        delete hapus; 
        urutan++; 
    }

    cout << "Linked list berhasil dikosongkan sepenuhnya." << endl;
}

void clearH(){
    TNode *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    initH();
    cout<<"Seluruh data pada Linked List telah dibersihkan.";
}

void clearHT(){
    TNode *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    initHT();
    cout<<"Seluruh data pada Linked List telah dibersihkan.";
}

void clearSelangSelingHT() {
    if (isEmptyHT() == 1) {
        cout << "Linked list sudah kosong." << endl;
        return;
    }

    int urutan = 1; 
    bool hapusDepan = true; 

    cout << "=== MEMULAI PROSES CLEAR SELANG-SELING (HT) ===" << endl;

    while (isEmptyHT() != 1) {
        TNode *hapus = NULL;

        if (hapusDepan) {
            hapus = head;
            
            if (head == tail) {
                head = NULL;
                tail = NULL;
            } else {
                head = head->next; 
                head->prev = NULL; 
            }
            
            hapusDepan = false; 
        } 
        else {
            hapus = tail; 

            if (head == tail) {
                head = NULL;
                tail = NULL;
            } else {
                tail = tail->prev; 
                tail->next = NULL; 
            }

            hapusDepan = true;
        }

        cout << "Penghapusan ke-" << urutan << " : Node bertuliskan \"" 
             << hapus->data << "\" berhasil dihapus." << endl;

        delete hapus; 
        urutan++; 
    }

    cout << "Linked list berhasil dikosongkan sepenuhnya." << endl;
}