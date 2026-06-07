#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* kiri;
    Node* kanan;
};

Node* tambah(Node* root, int data){
    if (root == NULL)
    {
        Node* baru = new Node;
        baru->data = data;
        baru->kiri = NULL;
        baru->kanan = NULL;
        return baru;
    }
    if (data < root->data)
    {
        root->kiri = tambah(root->kiri, data);
    } else if (data > root->data)
    {
        root->kanan = tambah(root->kanan, data);
    }
    return root;
}

int hitungTinggi(Node* node){
    if (node == NULL){
        return 0;
    }
    if (node->kiri == NULL && node->kanan == NULL){
        return 0;
    }

    int tinggiKiri = 0;
    if (node->kiri != NULL)
    {
        tinggiKiri = 1 + hitungTinggi(node->kiri);
    }

    int tinggiKanan = 0;
    if (node->kanan != NULL)
    {
        tinggiKanan = 1 + hitungTinggi(node->kanan);
    }

    if (tinggiKiri > tinggiKanan)
    {
        return tinggiKiri;
    } else{
        return tinggiKanan;
    }   
}

int cariJarakTerjauh(Node* root){
    if (root == NULL)
    {
        return 0;
    }

    int tinggiKiri = 0;
    if (root->kiri != NULL)
    {
        tinggiKiri = 1 + hitungTinggi(root->kiri);
    }

    int tinggiKanan = 0;
    if (root->kanan != NULL)
    {
        tinggiKanan = 1 + hitungTinggi(root->kanan);
    }

    int jarakMelaluiRootSekarang = tinggiKiri + tinggiKanan;

    int jarakMaksKiri = cariJarakTerjauh(root->kiri);
    int jarakMaksKanan = cariJarakTerjauh(root->kanan);

    int nilaiMaksimal = jarakMelaluiRootSekarang;

    if (jarakMaksKiri > nilaiMaksimal)
    {
        nilaiMaksimal = jarakMaksKiri;
    }
    if (jarakMaksKanan > nilaiMaksimal)
    {
        nilaiMaksimal = jarakMaksKanan;
    }
    return nilaiMaksimal;
}

int main(){
    int jumlahElemen = 0;

    printf("Masukkan panjang data : ");
    if(cin >> jumlahElemen){
        Node* pohonBST = NULL;
        int nilaiData = 0;

        printf("Masukkan data sebanyak %d dipisah dengan spasi : ", jumlahElemen);
        for (int i = 0; i < jumlahElemen; i++)
        {
            cin >> nilaiData;
            pohonBST = tambah(pohonBST, nilaiData);
        }

        int hasilJarakTerjauh = cariJarakTerjauh(pohonBST);

        cout <<"Hasil Perhitungan jarak terjauh adalah : "<< hasilJarakTerjauh << "\n";
    }
    return 0;
}